#include "mainmenu.h"

// void show_main_menu() {
//   clear_screen();
//
//   cm_modal_error("Ini adalah contoh error.");
//   cm_modal_warning("Ini adalah contoh warning.");
//   cm_modal_info("Ini adalah contoh info.");
// }

boolean __is_str_same(char input1[], char input2[]) {
  int i = 0;
  boolean same = input1[i] == input2[i];
  while (same && (input1[i] != '\0' || input2[i] != '\0')) {
    i++;
    same = input1[i] == input2[i];
  }
  return same;
}

char *__mm_copyWord(Word str) {
  char *res = (char *)malloc(sizeof(char) * (str.length + 1));
  int i;
  for (i = 0; i < str.length; i++) {
    res[i] = str.contents[i];
  }
  res[i] = '\0';
  return res;
}

char *__ask_input() {
  printf("ENTER COMMAND: ");
  char *input;
  wm_start_word(stdin);
  while (!wm_end_word) {
    input = __mm_copyWord(wm_current_word);
    wm_adv_word();
  }
  return input;
}
void mm_dashboard() { printf("Permainan Mobita\n"); }

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
    main_input_command = __ask_input();
    if (__is_str_same(main_input_command, "NEW GAME") ||
        __is_str_same(main_input_command, "LOAD GAME")) {
      if (__is_str_same(main_input_command, "NEW GAME")) {
        // Loading Config
        printf("Path to config file: ");
        char *configPath = __ask_input();
        readConfigFile(configPath, &s_status_game);

        // Config file nya udah dibaca
        // configPath adalah hasil malloc, harus di free supaya gak makan memory
        free(configPath);
      } else {
        show_load_game(&s_status_game);
      }

      // Game berlangsung selama ToDoList tidak Kosong dan
      // Tas (Isinya pesanan yang harus diantar) tidak kosong
      char *input_command;
      while (!td_is_empty(SG_TDL(s_status_game)) &&
             !t_is_empty(SG_TAS(s_status_game))) {
        // Game
        input_command = __ask_input();
        if (__is_str_same(input_command, "MOVE")) {
          // MOVE
        } else if (__is_str_same(input_command, "PICK_UP")) {
          // PICK UP
        } else if (__is_str_same(input_command, "DROP_OFF")) {
          // DROP OFF
        } else if (__is_str_same(input_command, "MAP")) {
          show_map();
        } else if (__is_str_same(input_command, "TO_DO")) {
          show_to_do(s_status_game);
        } else if (__is_str_same(input_command, "IN_PROGRESS")) {
          show_progress(s_status_game);
        } else if (__is_str_same(input_command, "BUY")) {
          show_page_buy(&s_status_game);
        } else if (__is_str_same(input_command, "INVENTORY")) {
          show_inventory(&s_status_game);
        } else if (__is_str_same(input_command, "HELP")) {
          // HELP
        } else if (__is_str_same(input_command, "SAVE_GAME")) {
          show_save_game(s_status_game);
        } else {
          cm_modal_error("COMMAND TIDAK DIKENALI!");
        }
        // input_command merupakan hasil malloc,
        // jadinya perlu di dealokasi
        free(input_command);
      }
      // Keluar while, artinya game sudah selesai
      GAME_COMPLETE = true;

      // Tampilin Statistik Game
      printf("Game Selesai\n");
      printf("Time: %d\n", SG_TIME(s_status_game));
      // Display berapa banyak item yang diantar

    } else if (__is_str_same(main_input_command, "HELP")) {
      // SHOW HELP
    } else if (__is_str_same(main_input_command, "EXIT")) {
      printf("Exiting Game....\n");
      GAME_COMPLETE = true;
    } else {
      cm_modal_error("COMMAND TIDAK DIKENALI!\n");
    }
    // main_input_command adalah hasil malloc, perlu free biar gak jadi zombie
    free(main_input_command);
  } while (!GAME_COMPLETE);
}
