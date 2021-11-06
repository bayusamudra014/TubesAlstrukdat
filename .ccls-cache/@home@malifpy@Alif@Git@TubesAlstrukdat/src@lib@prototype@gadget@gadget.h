#ifndef H_GADGET
#define H_GADGET

#include <stdio.h>
typedef char Gadget;

/* Mengembalikan nama gadget */
Gadget g_get_name(int type);

/* Mengembalikan harga beli gadget */
int g__get_price(int type);

/* mengubah state game berdasarkan gadget yang diinputkan */
/* masih menunggu beberapa adt game selesai */
void g_change_state(int type);
#endif