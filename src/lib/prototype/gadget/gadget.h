#ifndef H_GADGET
#define H_GADGET

#include <stdio.h>
#include <stdlib.h>
#include "../prototype.h"

typedef struct gadget{

    int gadgetID;
    char label;
    int price;

}Gadget;

/*I.S. Sembarang*/
/*F.S. set gadget sesuai dengan spesifikasi*/
void g_set_gadget(Gadget *gadget, int type);

#endif
