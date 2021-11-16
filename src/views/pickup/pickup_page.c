#include "pickup_page.h"

boolean pu_is_vip_taken() {
  boolean result = false;
  ToDoList todo = SG_TDL(s_status_game);
  LinkedList p = FIRST(todo);

  while (p && !result) {
    if (INFO(p).item.itemID == 'V') {
      result = true;
    }
  }

  return result;
}

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
  pl_insert_last(&(s_status_game.to_do_list), order);
}

void pu_add_bag(Order order) {
  t_add_item(&(s_status_game.tas_mobita), order.item);
}

void show_pickup() {
  if (!pu_is_vip_taken()) {
    Order* top = pu_item_upper();

    if (top) {
      td_removeTask(&(s_status_game.to_do_list), NULL, top->orderID);
      pu_add_progress(*top);
      pu_add_bag(*top);

      printf("\n");

      char pesan[50];

      snprintf(pesan, 50, "Pesanan berupa %s berhasil diambil!",
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