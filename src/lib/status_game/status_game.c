#include "status_game.h"
#include <stdio.h>

void sg_reset_time(StatusGame *sg){
    
    (*sg).Waktu_Permainan = 0; 

}

void sg_inc_time(StatusGame *sg){
    
    (*sg).Waktu_Permainan++;

}
