#include "pickup_page.h"

boolean pu_is_vip_taken() { return pl_is_any_vip(SG_PL(s_status_game)); }

/* Mengembalikan NULL bila tidak ada item yang bisa di pickup */
Order* pu_item_upper() {
  ToDoList todo = SG_TDL(s_status_game);
  int len = td_length(todo);

  Order* result = NULL;

  for (int i = 0; i < len; i++) {
    Order data = td_getOrder(todo, i);

    if (b_is_equal(data.pickUp, s_status_game.posisi_sekarang)) {
      if (!result) {
        result = &data;
      } else if (data.incomingTime < result->incomingTime) {
        result = &data;
      }
    }
  }

  return result;
}

void pu_add_progress(Order order) {
  pl_insert_last(&(SG_PL(s_status_game)), order);
}

void pu_add_bag(Order order) { t_add_item(&(SG_TAS(s_status_game)), order); }

void show_pickup() {
  if (!pu_is_vip_taken()) {
    Order* top = pu_item_upper();

    if (top) {
      if (top->item.type == 'P') {
        top->expiredTime = SG_TIME(s_status_game) + top->item.expired;
      }

      td_removeTask(&(SG_TDL(s_status_game)), NULL, top->orderID);
      pu_add_progress(*top);
      pu_add_bag(*top);

      printf("\n");

      char pesan[100];

      snprintf(pesan, 100, "Pesanan berupa %s berhasil diambil!",
               i_item_type_name(top->item));

      cm_modal_info(pesan);
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