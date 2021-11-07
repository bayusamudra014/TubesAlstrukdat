#ifndef H_LOADEX
#define H_LOADEX

#include "../lib.h"




void ldx_newGame(const char* path,StatusGame *status_game);

void ldx_loadGame(const char* path,StatusGame *status_game);

void ldx_saveGame(const char* path,StatusGame status_game);



#endif