#include <stdio.h>

#include "components/components.h"
#include "lib/lib.h"
#include "views/views.h"

int main()
{
  clear_screen();

  cm_modal_error("Ini adalah contoh error.");
  cm_modal_warning("Ini adalah contoh warning.");
  cm_modal_info("Ini adalah contoh info.");

  return 0;
}

/**
 * test page to_do
 * StatusGame s_status_game;
 * Order order1, order2;
 *
 * order1.item.expired = 5;
 * order1.item.itemID = 0;
 * order1.item.type = 'P';
 *
 * order1.incomingTime = 2;
 * order1.dropOff.label = 'B';
 * order1.dropOff.position.x = 1;
 * order1.dropOff.position.y = 2;
 * order1.pickUp.label = 'G';
 * order1.pickUp.position.x = 5;
 * order1.pickUp.position.y = 10;
 * order1.orderID = 0;
 *
 * order2.item.expired = 5;
 * order2.item.itemID = 0;
 * order2.item.type = 'H';
 *
 * order2.incomingTime = 2;
 * order2.dropOff.label = 'G';
 * order2.dropOff.position.x = 1;
 * order2.dropOff.position.y = 2;
 * order2.pickUp.label = 'M';
 * order2.pickUp.position.x = 5;
 * order2.pickUp.position.y = 10;
 * order2.orderID = 1;
 *
 * td_create(&s_status_game.to_do_list);
 * td_insertTask(&s_status_game.to_do_list, order1);
 * td_insertTask(&s_status_game.to_do_list, order2);
 *
 * show_to_do(s_status_game);
 *
 * td_removeTask(&s_status_game.to_do_list,&order1,1);
 *
 * show_to_do(s_status_game);
 * 
 */