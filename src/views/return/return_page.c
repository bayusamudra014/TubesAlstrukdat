#include "return_page.h"

void r_delete_top() {
  Order data = t_take_item(&SG_TAS(s_status_game));
  pl_delete_by_order(&SG_PL(s_status_game), data);
}

void show_return() {
  printf("\n");
  if (SG_S_BTS(s_status_game) > 0) {
    Order i = S_TOP(t_isi(SG_TAS(s_status_game)));

    if (i.item.type == 'P') {
      i.expiredTime = (Time)-1;
      td_insertTask(&SG_TDL(s_status_game), i);
      printf("Barang %s berhasil dikembalikan ke bangunan %c\n",
             i_item_type_name(i.item), i.pickUp.label);

      r_delete_top();

      SG_S_BTS(s_status_game)--;
    } else if (i.item.type != 'V') {
      td_insertTask(&SG_TDL(s_status_game), i);
      printf("Barang %s berhasil dikembalikan ke bangunan %c\n",
             i_item_type_name(i.item), i.pickUp.label);

      r_delete_top();

      SG_S_BTS(s_status_game)--;
    } else {
      cm_modal_warning("Oops.. Kamu ga bisa balikin barang VIP.");
    }

  } else {
    cm_modal_info(
        "Kamu belum punya ability \"Return to Sender\"\nSilahkan antarkan "
        "barang VIP terlebih dahulu.");
  }
}