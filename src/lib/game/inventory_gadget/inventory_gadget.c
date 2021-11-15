#include "inventory_gadget.h"

/**
 * I.S. Inventory Gadget belum terdefenisi
 * F.S. Inventory Gadget kosong
 */
void ig_create_ig(inventory_gadget* IG){
    sl_create_list(IG);
}

/**
 * I.S. Inventory Gadget terdefinisi
 * F.S. Jika tidak penuh, diisi
 *      Jika penuh, lakukan sesuatu
 */
void ig_add_item(inventory_gadget* IG, Gadget G){
    if(sl_length(*IG) < 5){
        sl_insert_last(IG, G);
    } else {
        // Do something
        printf("Inventory Gadget penuh!\n");
    }
}

/**
 * I.S. Inventory Gadget terdefenisi
 * F.S. Akan print list item, kemudian 
 *      player dapat memilih untuk mengambil
 *      item yang mana.
 */
void ig_take_item(inventory_gadget* IG, Gadget* G){
    int cmd;
    ig_display_ig(*IG);
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    printf("ENTER COMMAND: ");
    scanf("%d\n", &cmd);
    if(cmd < sl_length(*IG)){
        sl_delete_at(IG, G, cmd);
    } else {
        // Do something
        printf("Tidak ada Gadget yang dapat digunakan!\n");
    }
}

/**
 * I.S. Inventory Gadget terdefinisi
 * F.S. Cuma ngeprint list item
 */
void ig_display_ig(inventory_gadget IG) {
  int i;
  for (i = 0; i < 5; i++) {
    if (i < sl_length(IG)) {
      printf("%d. %c\n", i + 1, sl_elmt(IG, i).label);

    } else {
      printf("%d. -\n", i + 1);
    }
  }
}
