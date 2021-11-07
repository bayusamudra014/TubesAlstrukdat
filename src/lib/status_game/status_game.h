#ifndef H_STATUS_GAME
#define H_STATUS_GAME

#include <stdio.h>
#include "../game/game.h"

typedef struct StatusGame{

    ProgressList progress_list;
    ToDoList to_do_list;
    Tas tas_mobita;
    OrderList order_list;
    inventory_gadget inventory_gadget; 
    
    

}StatusGame;

extern StatusGame s_status_game;



#endif