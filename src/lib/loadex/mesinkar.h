/* File: mesinkar.h */
/* File to store ADT Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include <string.h>
#include "boolean.h"

#define MARK EOF

extern char CC;
extern boolean EOP;

// Mesin karakter to open file
void START(const char* filename);

// Mesin karakter for STDIN
void STARTSTDIN();

// Advances karakter in file until EOP
void ADV();

// Advances karakter from STDIN
void ADVSTDIN();

#endif