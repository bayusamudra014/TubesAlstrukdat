#include <stdio.h>

#include "views/mainmenu/mainmenu.h"
#include "views/views.h"

int main() {
  // char file_name[50];
  // scanf(" %[^\n]s", file_name);

  // printf("loading...\n");
  // lx_readConfigFile_silent("config.conf");
  // printf("loading selesai\n");

  // Order order;
  // Item item;
  // item.expired = -1;
  // item.itemID = 0;
  // item.type = 'N';
  // order.dropOff = 'A';
  // order.orderID = 1;
  // order.pickUp = 'B';
  // order.expiredTime = (Time)-1;
  // order.incomingTime = 6;
  // order.item = item;

  // t_add_item(&SG_TAS(s_status_game), order);

  // td_insertTask(&SG_TDL(s_status_game),order);

  // pl_insert_last(&SG_PL(s_status_game), order);

  // SG_TIME(s_status_game) = 19;
  // SG_MONEY(s_status_game) = 9000;
  // SG_S_BTS(s_status_game) = 1;
  // // Order order = ol_dequeue_order(&SG_OL(s_status_game));
  // // printf("Ini di main abis selesai Config %d\n",*order.expiredTime);
  // lx_saveToFile("save.conf");
  // lx_loadSaveFile("save.conf");

  // // Building pos;
  // // pos = loc(SG_MAP(s_status_game),3);
  // // SG_POS(s_status_game) = pos;
  // lx_saveToFile("save1.conf");

  show_main_menu();
  // lx_saveToFile("save.conf");
  return 0;
}
