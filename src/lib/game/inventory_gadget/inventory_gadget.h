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
 * I.S. Inventory Gadget terdefinisi
 * F.S. Cuma ngeprint list item
 */

void ig_display_ig(inventory_gadget IG);

/**
 * return true kalau penuh
 */
boolean ig_is_full(inventory_gadget IG);
#endif
