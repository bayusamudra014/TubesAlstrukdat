#ifndef H_LOADEX
#define H_LOADEX

#include "../lib.h"
#define maxLength 100

typedef struct {
    char wordArray[maxLength+1];
    int length;
} word;

extern boolean EndKata;


// Advances until CC is not blank
void ignoreBlank();

// Advances until CC is not blank
void ignoreBlankSTDIN();

// readNumber parses input to be an integer
int readNumber();

// readSTDIN will input from STDIN and convert it to ADT Word
void readSTDIN(word *input);


// readConfigFile will read config file and make the structure
void readConfigFile(char configFilename[], StatusGame* s_status_game);


// readNumberSTDIN returns number from STDIN input
void readNumberSTDIN(int *X);

// Print ASCII of character (for debugging purposes)
void printASCIIFile();

// Print word
void printWord(word W);

// Save to file
void saveToFile();

// Load from file
void loadFromFile(StatusGame* s_status_game);

// Word to int converter
int intConverter(word W);

// Word Compare
boolean wordCompare(word W, char * S);


void ldx_newGame(const char* path,StatusGame *status_game);

void ldx_loadGame(const char* path,StatusGame *status_game);

void ldx_saveGame(const char* path,StatusGame status_game);



#endif