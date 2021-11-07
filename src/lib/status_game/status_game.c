#include "status_game.h"
#include <stdio.h>



StatusGame status_game;

void sg_reset_time(){
    
    status_game.Waktu_Permainan = 0; 

}

void sg_inc_time(){
    
    status_game.Waktu_Permainan++;

}
