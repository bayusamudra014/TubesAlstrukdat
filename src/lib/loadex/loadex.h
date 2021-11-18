#ifndef H_LOADEX
#define H_LOADEX

#include "../lib.h"
#define maxLength 100


// readNumber parses input to be an integer
int lx_readNumber();

// readConfigFile will read config file and make the structure
void lx_readConfigFile_silent(char configFilename[]);

// Save to file
void lx_saveToFile(char saveFileName[]);

// Load
void lx_loadSaveFile(char saveFileName[]);


//Pembantu write
void lx_wNum(int x);
void lx_wNl();
void lx_wSpace();
void lx_wAdj(int buildingN);


void ldx_newGame(const char *path, StatusGame *status_game);

void ldx_loadGame(const char *path, StatusGame *status_game);

void ldx_saveGame(const char *path, StatusGame status_game);

#endif