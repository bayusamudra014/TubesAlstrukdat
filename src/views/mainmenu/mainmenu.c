#include "mainmenu.h"

#include <stdio.h>

boolean __is_str_same(char input1[], char input2[]) {
  int i = 0;
  boolean same = input1[i] == input2[i];
  while (same && (input1[i] != '\0' || input2[i] != '\0')) {
    i++;
    same = input1[i] == input2[i];
  }
  return same;
}

char *__ask_input(char message[]) {
  printf("%s", message);
  char *input = malloc(100 * sizeof(char));

  read_line(input, 100);
  return input;
}

void mm_dashboard() {
  Color cyan = create_text_color_cd(0x0a9396);
  set_text_color(cyan);

  printf("___  ___      _     _ _ _ _        \n");
  printf("|  \\/  |     | |   (_) (_) |       \n");
  printf("| .  . | ___ | |__  _| |_| |_ __ _ \n");
  printf("| |\\/| |/ _ \\| '_ \\| | | | __/ _` |\n");
  printf("| |  | | (_) | |_) | | | | || (_| |\n");
  printf("\\_|  |_/\\___/|_.__/|_|_|_|\\__\\__,_|\n");

  reset_color();

  printf("\n\nVersi 1.0.0.\n\n");

  cm_modal_info(
      "Halo, Aku Mobita. Bantuin aku yuk...\nKamu bisa masukin perintah "
      "dibawah ini yaa.");

  delete_color(cyan);
}

void mm_ending(StatusGame s_status_game) {
  cm_modal_info("Game Selesai!");
  printf("Waktu Permainan: %d\n", SG_TIME(s_status_game));
}

void show_main_menu() {
  // wm_start_word(stdin);
  // while (!wm_end_word){
  //     printf("%s\n", wm_current_word.contents);
  //     wm_adv_word();
  // }
  clear_screen();

  // Kalau mau ngeprint ascii art saat load game
  mm_dashboard();

  char *main_input_command;

  boolean GAME_COMPLETE = false;
  do {
    printf("Sebelum itu, pilihlah mode yang akan kamu mainkan:\n");
    printf("1. NEW_GAME : Memulai permainan baru\n");
    printf("2. LOAD_GAME : Load permainan sebelumnya\n\n");
    main_input_command = __ask_input("Mode Permainan : ");

    if (__is_str_same(main_input_command, "NEW_GAME") ||
        __is_str_same(main_input_command, "LOAD_GAME") ||
        __is_str_same(main_input_command, "1") ||
        __is_str_same(main_input_command, "2")) {
      if (__is_str_same(main_input_command, "NEW_GAME") ||
          __is_str_same(main_input_command, "1")) {
        // Loading Config
        char *configPath = __ask_input("Path to config file: ");
        while (!f_exist(configPath)) {
          printf("\n");
          cm_modal_error("File tidak bisa dibaca!");
          configPath = __ask_input("Path to config file: ");
        }

        lx_readConfigFile_silent(configPath);
        sg_reload_status();

        printf("\n");
        cm_modal_info("Oke, Load Config Berhasil. Selamat Bermain!");

        // Config file nya udah dibaca
        // configPath adalah hasil malloc, harus di free supaya gak makan memory
        free(configPath);
      } else {
        show_load_game(&s_status_game);
      }

      // Game berlangsung selama ToDoList tidak Kosong dan
      // Tas (Isinya pesanan yang harus diantar) tidak kosong
      char *input_command;
      boolean forceExit = false;
      while ((!ol_is_empty(SG_OL(s_status_game)) ||
              !t_is_empty(SG_TAS(s_status_game)) ||
              !td_is_empty(SG_TDL(s_status_game))) &&
             !forceExit) {
        // Game
        input_command = __ask_input("ENTER COMMAND: ");
        if (__is_str_same(input_command, "MOVE")) {
          show_move(&s_status_game);
        } else if (__is_str_same(input_command, "PICK_UP")) {
          show_pickup();
        } else if (__is_str_same(input_command, "DROP_OFF")) {
          show_dropoff();
        } else if (__is_str_same(input_command, "MAP")) {
          show_map(s_status_game);
        } else if (__is_str_same(input_command, "TO_DO")) {
          show_to_do(s_status_game);
        } else if (__is_str_same(input_command, "IN_PROGRESS")) {
          show_progress(s_status_game);
        } else if (__is_str_same(input_command, "BUY")) {
          if (ig_is_full(SG_IG(s_status_game))) {
            cm_modal_warning(
                "Inventory Gadget Penuh! Tidak bisa membeli Gadget");
          } else {
            show_page_buy(&s_status_game);
          }
        } else if (__is_str_same(input_command, "INVENTORY")) {
          show_inventory(&s_status_game);
        } else if (__is_str_same(input_command, "HELP")) {
          show_help();
        } else if (__is_str_same(input_command, "SAVE_GAME")) {
          show_save_game(s_status_game);
          // } else if (__is_str_same(input_command, "MAX_MONEY")) {
          //   SG_MONEY(s_status_game) = 9999;
        } else if (__is_str_same(input_command, "EXIT")) {
          set_text_color(TEXT_YELLOW);
          printf("\nPeringatan!\n");
          reset_color();

          printf("Apakah anda yakin ingin keluar dari permainan?\n");
          printf("Semua perubahan tidak akan disimpan.\n");
          char *jawaban = __ask_input("Jawaban [Y/n] : ");

          if (__is_str_same(jawaban, "Y") || __is_str_same(jawaban, "y")) {
            forceExit = true;
          }

          free(jawaban);
        } else if (!__is_str_same(input_command, "")) {
          cm_modal_error("COMMAND TIDAK DIKENALI!");
        }

        printf("\n");
        // input_command merupakan hasil malloc,
        // jadinya perlu di dealokasi
        free(input_command);
      }
      // Keluar while, artinya game sudah selesai
      GAME_COMPLETE = true;

      // Tampilin Statistik Game
      mm_ending(s_status_game);
      // Display berapa banyak item yang diantar

    } else if (__is_str_same(main_input_command, "HELP")) {
      show_help();
    } else if (__is_str_same(main_input_command, "EXIT")) {
      cm_modal_warning("Exiting Game....");
      GAME_COMPLETE = true;
    } else if (!__is_str_same(main_input_command, "")) {
      printf("\n");
      cm_modal_error("COMMAND TIDAK DIKENALI!");
    } else {
      printf("\n");
    }

    // main_input_command adalah hasil malloc, perlu free biar gak jadi zombie
    free(main_input_command);
  } while (!GAME_COMPLETE);
}
