#include "pickup_page.h"

boolean pu_is_vip_taken() { return pl_is_any_vip(SG_PL(s_status_game)); }

/* Mengembalikan true bila ditemukan dan mengubah variabel hasil */
boolean pu_item_upper(Order* hasil) {
  ToDoList todo = SG_TDL(s_status_game);
  int len = td_length(todo);

  Order* result = NULL;

  for (int i = 0; i < len; i++) {
    Order data = td_getOrder(todo, i);

    if (b_is_equal(data.pickUp, s_status_game.posisi_sekarang)) {
      if (!result || data.incomingTime < result->incomingTime) {
        result = &data;
      }
    }
  }

  if (result) {
    *hasil = *result;
    return true;
  } else {
    return false;
  }
}

void pu_add_progress(Order order) {
  pl_insert_last(&(SG_PL(s_status_game)), order);
}

void pu_add_bag(Order order) { t_add_item(&(SG_TAS(s_status_game)), order); }

void show_pickup() {
  printf("\n");

  if (!pu_is_vip_taken()) {
    Order top;

    if (pu_item_upper(&top)) {
      if (!t_is_full(SG_TAS(s_status_game))) {
        if (top.item.type == 'P') {
          top.expiredTime = SG_TIME(s_status_game) + top.item.expired;
        }

        td_removeTask(&(SG_TDL(s_status_game)), NULL, top.orderID);
        pu_add_progress(top);
        pu_add_bag(top);

        char pesan[100];

        snprintf(pesan, 100, "Pesanan berupa %s berhasil diambil!",
                 i_item_type_name(top.item));

        cm_modal_info(pesan);
      } else {
        cm_modal_warning(
            "Yah kamu ga bisa ngambil barang karena tas kamu penuh.");
      }
    } else {
      printf("\n");
      cm_modal_warning("Tidak ada pesanan disini");
    }
  } else {
    printf("\n");
    cm_modal_warning(
        "Anda sedang mengambil pesanan VIP.\nSilahkan antarkan terlebih "
        "dahulu.");
  }
}