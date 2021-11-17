#include "return_page.h"

void show_return() {
  if (SG_S_BTS(s_status_game)) {
    Order i = S_TOP(t_isi(SG_TAS(s_status_game)));

    if (i.item.type == 'P') {
      i.expiredTime = (Time)-1;
      td_insertTask(&SG_TDL(s_status_game), i);
      printf("Barang %s berhasil dikembalikan ke bangunan %c",
             i_item_type_name(i.item), i.pickUp.label);
    } else if (i.item.type != 'V') {
      td_insertTask(&SG_TDL(s_status_game), i);
      printf("Barang %s berhasil dikembalikan ke bangunan %c",
             i_item_type_name(i.item), i.pickUp.label);
    } else {
      cm_modal_warning("Oops.. Kamu ga bisa balikin barang VIP.");
    }

  } else {
    cm_modal_error(
        "Kamu belum punya ability \"Return to Sende\"\nSilahkan antarkan "
        "barang VIP terlebih dahulu.");
  }
}