#include "inventory_page.h"

void g_change_state(char type, StatusGame *s) {
  if (type == 'K') {
    Time curr = ol_get_head(SG_OL(*s)).expiredTime;
    curr =
        SG_TIME(*s) + ol_get_head(SG_OL(*s)).item.expired;
  } else if (type == 'S') {
    t_increase_capacity(&((*s).tas_mobita),
                        t_cap((*s).tas_mobita));
  } else if (type == 'P') {
    int len = (*s).peta_game.buildinglist.nEff;
    int i;
    for (i = 0; i < len; i++) {
      printf("%d. ", i + 1);
      b_display((*s).peta_game.buildinglist.buffer[i]);
    }
    printf("\nPosisi yang dipilih: ");
    int mv;
    read_int_line(&mv, 3);
    move(s, mv, true, false);
    printf("\nNobita sekarang berada di titik ");
    Building pos = (s)->posisi_sekarang;
    print_yellow(pos.label);

    printf(" (%d, %d)\n", pos.position.x, pos.position.y);

    printf("🕑 Waktu: %u\n", SG_TIME(*s));
    sg_reload_status();
  } else if (type == 'M') {
    int tm = (*s).Waktu_Permainan;
    if (tm < 50) {
      (*s).Waktu_Permainan = 0;
    } else {
      (*s).Waktu_Permainan -= 50;
    }
  }
}

void show_inventory(StatusGame *s_status_game) {
  int cmd;
  Gadget G;
  ig_display_ig(SG_IG(*s_status_game));
  printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
  printf("ENTER COMMAND: ");
  read_int_line(&cmd, 5);
  printf("%d\n", cmd);
  if (cmd <= sl_length(SG_IG(*s_status_game)) && cmd > 0) {
    sl_delete_at(&SG_IG(*s_status_game), &G, cmd - 1);
    // printf("Eksekusi Gadget bertipe %c\n", G.label);
    g_change_state(G.label, s_status_game);
  } else if (cmd != 0) {
    // Do something
    printf("Gadget tidak dapat digunakan!\n");
  } else {
    printf("Returning...\n");
  }
  // Disini
}
