#ifndef H_INVENTORY_GADGET
#define H_INVENTORY_GADGET

#include "../game.h"

typedef StaticList inventory_gadget;
/**
 * I.S. Inventory Gadget belum terdefenisi
 * F.S. Inventory Gadget kosong
 */
void ig_create_ig(inventory_gadget* IG);

/**
 * I.S. Inventory Gadget terdefinisi
 * F.S. Jika tidak penuh, diisi
 *      Jika penuh, lakukan sesuatu
 */
void ig_add_item(inventory_gadget* IG, Gadget G);

/**
 * I.S. Inventory Gadget terdefenisi
 * F.S. Akan print list item, kemudian 
 *      player dapat memilih untuk mengambil
 *      item yang mana.
 */
void ig_take_item(inventory_gadget* IG, Gadget* G);

#endif
