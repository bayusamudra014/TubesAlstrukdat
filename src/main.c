#include <stdio.h>

#include "views/views.h"

int main()
{
  StatusGame s_status_game;

  char file_name[50];
  scanf(" %[^\n]s", file_name);

  printf("loading...\n");
  readConfigFile(file_name, &s_status_game);
  printf("loading selesai\n");

  printf("%d",s_status_game.uang_mobita);
  return 0;
}

/*test page to_do*/
// int main(){
//   StatusGame s_status_game;
//   s_status_game.uang_mobita = 10000;

// //   Order order1, order2;
//   s_status_game.uang_mobita = 0;

//   // order1.item.expired = 5;
//   order1.item.itemID = 0;
//   order1.item.type = 'N';

//   order1.incomingTime = 2;
//   order1.dropOff.label = 'B';
//   order1.dropOff.position.x = 1;
//   order1.dropOff.position.y = 2;
//   order1.pickUp.label = 'G';
//   order1.pickUp.position.x = 5;
//   order1.pickUp.position.y = 10;
//   order1.orderID = 0;

//   order2.item.expired = 5;
//   order2.item.itemID = 0;
//   order2.item.type = 'H';

//   order2.incomingTime = 2;
//   order2.dropOff.label = 'G';
//   order2.dropOff.position.x = 1;
//   order2.dropOff.position.y = 2;
//   order2.pickUp.label = 'M';
//   order2.pickUp.position.x = 5;
//   order2.pickUp.position.y = 10;
//   order2.orderID = 1;

//   td_create(&s_status_game.to_do_list);
//   pl_create_progress(&s_status_game.progress_list);
//   t_create_tas(&s_status_game.tas_mobita);

//   td_insertTask(&s_status_game.to_do_list, order1);
//   td_insertTask(&s_status_game.to_do_list, order2);

//   pl_insert_last(&s_status_game.progress_list, order1);
//   pl_insert_last(&s_status_game.progress_list, order2);

//   // show_to_do(s_status_game);
//   show_progress(s_status_game);
//   printf("\n");
//   printf("kapasitas tas mobita saat ini :
//   %d",s_status_game.tas_mobita.capacity); printf("\n"); printf("uang mobita
//   saat ini : %d\n",s_status_game.uang_mobita);
//   // td_removeTask(&s_status_game.to_do_list,&order1,1);
//   // pl_delete_first(&s_status_game.progress_list,&order1);
//   progress_dropoff(&s_status_game);
//   show_progress(s_status_game);

//   printf("kapasitas tas mobita saat ini :
//   %d",s_status_game.tas_mobita.capacity); printf("\n"); printf("uang mobita
//   saat ini : %d\n",s_status_game.uang_mobita);

// show_to_do(s_status_game);
//   Gadget gadget;
//   gadget.gadgetID = 1;
//   gadget.label = 'K';
//   gadget.price = 800;

//   ig_create_ig(&s_status_game.inventory_gadget);
//   printf("\n");
//   printf("Kapasitas dari inventory gadget adalah :
//   %d",sl_length(s_status_game.inventory_gadget)); printf("\n");
//   ig_display_ig(s_status_game.inventory_gadget);
//   printf("\n");
//   show_page_buy(&s_status_game);
//   printf("\n");
//   printf("Kapasitas dari inventory gadget adalah :
//   %d",sl_length(s_status_game.inventory_gadget)); printf("\n");
//   ig_display_ig(s_status_game.inventory_gadget);
//   printf("\n");
//   printf("Uang mobita saat ini : %d Yen\n",s_status_game.uang_mobita);
