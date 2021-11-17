#include "inventory_gadget.h"

/**
 * I.S. Inventory Gadget belum terdefenisi
 * F.S. Inventory Gadget kosong
 */
void ig_create_ig(inventory_gadget *IG) { sl_create_list(IG); }

boolean ig_is_full(inventory_gadget IG){
    return sl_is_full(IG);
}/**
 * I.S. Inventory Gadget terdefinisi
 * F.S. Jika tidak penuh, diisi
 *      Jika penuh, lakukan sesuatu
 */
void ig_add_item(inventory_gadget *IG, Gadget G) {
  if (!ig_is_full(*IG)) {
    sl_insert_last(IG, G);
  } else {
    // Do something
    printf("Inventory Gadget penuh!\n");
  }
}


/**
 * I.S. Inventory Gadget terdefinisi
 * F.S. Cuma ngeprint list item
 */
void __ig_print_numbering(int num, char label) {
  switch (label) {
  case 'K':
    printf("%d. Kain Pembungkus Waktu\n", num);
    break;
  case 'S':
    printf("%d. Senter Pembesar\n", num);
    break;
  case 'P':
    printf("%d. Pintu Kemana Saja\n", num);
    break;
  case 'M':
    printf("%d. Mesin Waktu\n", num);
    break;
  }
}

void ig_display_ig(inventory_gadget IG) {
  int i;
  for (i = 0; i < 5; i++) {
    if (i < sl_length(IG)) {
      __ig_print_numbering(i + 1, sl_elmt(IG, i).label);
    } else {
      printf("%d. -\n", i + 1);
    }
  }
}
