#include "dropoff_page.h"

#include <stdio.h>

boolean dp_is_any_vip() { return pl_is_any_vip(s_status_game.progress_list); }

boolean dp_is_dropable() { return true; }

int dp_get_prize(Item i) {
  switch (i.type) {
    case 'N':
      return 200;
    case 'H':
    case 'P':
      return 400;
    case 'V':
      return 600;
  }
}

void show_dropoff() {
  if (!t_is_empty(s_status_game.tas_mobita)) {
    if (!dp_is_any_vip()) {
      Item obj = S_TOP(t_isi(s_status_game.tas_mobita));
      Order* top = pl_get_order_by_item(s_status_game.progress_list, obj);

      if (top && b_is_equal(top->dropOff, s_status_game.posisi_sekarang)) {
        int harga = dp_get_prize(obj);

        char pesan[200];
        snprintf(pesan, 200,
                 "Yaay 🎉, kamu berhasil mengantarkan barang %s.\nKamu "
                 "mendapatkan %d Yen.",
                 i_item_type_name(obj), harga);

        cm_modal_info(pesan);
        pl_delete_by_order(&(s_status_game.progress_list), *top);
        t_take_item(&(s_status_game.tas_mobita));
        s_status_game.uang_mobita += harga;
      } else {
        cm_modal_info("Tidak ada yang bisa di drop off disini.");
      }
    } else {
      printf("\n");
      cm_modal_warning(
          "Anda sedang mengambil pesanan VIP.\nSilahkan antarkan terlebih "
          "dahulu.");
    }
  } else {
    printf("\n");
    cm_modal_info("Tas kamu saat ini kosong.\nSilahkan ambil pesanan dulu.");
  }
}