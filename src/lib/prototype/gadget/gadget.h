#ifndef H_GADGET
#define H_GADGET

#include <stdio.h>
#include <stdlib.h>

typedef struct gadget{

    int gadgetID;
    char label;
    int price;

}Gadget;

/*I.S. Sembarang*/
/*F.S. set gadget sesuai dengan spesifikasi*/
void g_set_gadget(Gadget *gadget, int type);

/* mengubah state game berdasarkan gadget yang diinputkan */
/* masih menunggu beberapa adt game selesai */
void g_change_state(int type);

#endif
