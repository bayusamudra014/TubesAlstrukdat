#include "inventory_page.h"

void show_inventory(StatusGame *s_status_game) {
  int cmd;
  Gadget G;
  ig_display_ig(SG_IG(*s_status_game));
  printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
  printf("ENTER COMMAND: ");
  read_int_line(&cmd, 5);
  if (cmd < sl_length(SG_IG(*s_status_game)) && cmd > 0) {
    sl_delete_at(&SG_IG(*s_status_game), &G, cmd);
    // Use Gadget
  } else if (cmd !=  0){
    // Do something
    printf("Gadget tidak dapat digunakan!\n");
  } else {
      printf("Returning...\n");
  }
  // Disini
}
