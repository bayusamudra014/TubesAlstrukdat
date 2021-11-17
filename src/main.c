#include <stdio.h>

#include "views/mainmenu/mainmenu.h"
#include "views/views.h"

int main() {
  // char file_name[50];
  // scanf(" %[^\n]s", file_name);

  // printf("loading...\n");
  // lx_readConfigFile_silent("config.conf");
  // printf("loading selesai\n");
  //
  // printf("%d\n",s_status_game.uang_mobita);
  // printf("%d\n",q_length(s_status_game.order_list));
  // Order order = ol_get_head(s_status_game.order_list);
  // printf("%d %c %c ", order.incomingTime,
  // order.pickUp.label,order.dropOff.label);
  //
  // if (ol_is_empty(s_status_game.order_list)){
  //   printf("kosong\n");
  // } else {
  //   printf("gak ksoong");
  // }
  sg_create_state();
  show_main_menu();
  return 0;
}
