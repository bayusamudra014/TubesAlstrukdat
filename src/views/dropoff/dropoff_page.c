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
    default:
      cm_modal_error("Oops, item tidak dikenal");
      exit(-1);
  }
}

void show_dropoff() {
  printf("\n");
  if (!t_is_empty(SG_TAS(s_status_game))) {
    Order obj = S_TOP(t_isi(SG_TAS(s_status_game)));
    Order* top = &obj;

    if (top && b_is_equal(top->dropOff, s_status_game.posisi_sekarang)) {
      int harga = dp_get_prize(obj.item);

      char pesan[200];
      snprintf(pesan, 200,
               "Yaay 🎉, kamu berhasil mengantarkan barang %s.\nKamu "
               "mendapatkan %d Yen.",
               i_item_type_name(obj.item), harga);

      cm_modal_info(pesan);

      if (obj.item.type == 'V') {
        printf("\n🎁 Hadiah dari pengirim\n");
        printf("Wah, kamu mendapatkan ability Return to Sender. Selamat..\n");
        SG_S_BTS(s_status_game)++;
      }

      pl_delete_by_order(&(SG_PL(s_status_game)), *top);
      t_take_item(&(SG_TAS(s_status_game)));
      SG_MONEY(s_status_game) += harga;
    } else if (dp_is_any_vip()) {
      cm_modal_warning(
          "Anda sedang mengambil pesanan VIP.\nSilahkan antarkan terlebih "
          "dahulu.");
    } else {
      cm_modal_info("Tidak ada barang yang bisa diturunkan disini");
    }
  } else {
    cm_modal_info("Tas kamu saat ini kosong.\nSilahkan ambil pesanan dulu.");
  }
}