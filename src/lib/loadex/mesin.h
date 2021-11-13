/* File: mesin.h */
/* File to store ADT Mesin Kata/Input */

#ifndef __MESIN_H_
#define __MESIN_H_

# include "mesinkar.h"


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

// readNumberSTDIN returns number from STDIN input
void readNumberSTDIN(int *X);

// readConfigFile will read config file and make the structure
void readConfigFile(matrix *M, buildingsArray *arr, graph *G, int *buildingCounter);

// Print ASCII of character (for debugging purposes)
void printASCIIFile();

// Print word
void printWord(word W);

// Save to file
void saveToFile(matrix *M, buildingsArray *arr, graph *G, int turn, boolean ignore, boolean critical, boolean extraTurn, queue *Q1, queue *Q2, boolean criticalP1, boolean criticalP2, boolean isShieldActiveP1, boolean shieldActivatedP1, boolean isShieldActiveP2, boolean shieldActivatedP2, int counterShieldP1, int counterShieldP2, int lengthFlagAttack, int lengthFlagMove, int * arrFlagAttack, int * arrFlagMove);

// Load from file
void loadFromFile(matrix *M, buildingsArray *arr, graph *G, int *turn, boolean *ignore, boolean *critical, boolean *extraTurn, queue *Q1, queue *Q2, int *buildingCounter, boolean *criticalP1, boolean *criticalP2, boolean *isShieldActiveP1, boolean *shieldActivatedP1, boolean *isShieldActiveP2, boolean *shieldActivatedP2, int *counterShieldP1, int *counterShieldP2, int * lengthFlagAttack_, int * lengthFlagMove_, int ** arrFlagAttack, int ** arrFlagMove);

// Word to int converter
int intConverter(word W);

// Word Compare
boolean wordCompare(word W, char * S);

#endif