#ifndef H_LOADEX
#define H_LOADEX

#include "../lib.h"
#define maxLength 100

typedef struct
{
    char wordArray[maxLength + 1];
    int length;
} word;

extern boolean EndKata;

// readNumber parses input to be an integer
int lx_readNumber();

// readConfigFile will read config file and make the structure
void lx_readConfigFile(char configFilename[]);
void lx_readConfigFile_silent(char configFilename[]);

// Save to file
void saveToFile();

void ldx_newGame(const char *path, StatusGame *status_game);

void ldx_loadGame(const char *path, StatusGame *status_game);

void ldx_saveGame(const char *path, StatusGame status_game);

#endif