#ifndef H_STATUS_GAME
#define H_STATUS_GAME

#include <stdio.h>
#include "game/game.h"

typedef struct StatusGame{

    ProgressList Progress_List;
    ToDoList ToDoList;
    

}StatusGame;

extern StatusGame s_status_game;



#endif