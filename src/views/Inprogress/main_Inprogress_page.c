#include <stdio.h>
#include <stdlib.h>
#include "Inprogress_page.h"
#include "Inprogress_page.c"

int main(){

    s_status_game;
    Order order1;
    

    order1.item.expired = 5;
    order1.item.itemID = 0;
    order1.item.type = 'H';

    order1.incomingTime = 2;
    order1.dropOff.label = 'G';
    order1.dropOff.position.x = 1;
    order1.dropOff.position.y = 2;
    order1.pickUp.label = 'M';
    order1.pickUp.position.x = 5;
    order1.pickUp.position.y = 10;
    order1.orderID = 0;
    
    
    pl_create_progress(&s_status_game.progress_list);
    pl_insert_last(&s_status_game.progress_list, order1);

    show_progress(s_status_game);
    





    return 0;
}