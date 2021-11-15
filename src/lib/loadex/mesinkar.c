/* File: mesinkar.c */
/* mesinkar.h implementation */

#include "mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

// Mesin karakter to open file
void START(const char* filename) {
    pita = fopen(filename,"r");
    EOP = false;
    ADV();
}

// Mesin karakter for STDIN
void STARTSTDIN()
{
    pita = stdin;
    EOP = false;
    ADVSTDIN();
}

// Advances karakter in file until EOP
void ADV() {
    // Advances if not EOF (return value of EOF when fscanf fails is -1)
    if (fscanf(pita,"%c",&CC)==EOF)
    {
        EOP = true;
        fclose(pita);
    }
}

// Advances karakter from STDIN
void ADVSTDIN()
{
    if (fscanf(pita,"%c",&CC)=='\n')
    {
        EOP = true;
        fclose(pita);
    }
}