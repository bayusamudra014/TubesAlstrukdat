#include "progress_list.h"

#include <stdio.h>

/*Membuat progress list yang baru*/
/*I.S. progress list sembarang*/
/*F.S. progress list kosong yang baru*/

void pl_create_progress(ProgressList *pl) { ll_create_list(pl); }

/*Menghasilkan true apabila progress list masih kosong*/
boolean pl_is_empty(ProgressList pl) { return ll_is_empty(pl); }

/*Menambahkan order baru kedalam progress list*/
/*order baru tersebut menjadi elemen terakhir dari progress list*/
void pl_insert_last(ProgressList *pl, PlElType order) {
  ll_insert_last(pl, order);
}

/*Menghapus order pertama dari progress list */
/*Hal ini terjadi ketika order telah selesai diantarkan*/
void pl_delete_first(ProgressList *pl, PlElType *order) {
  ll_delete_first(pl, order);
}

/*Mengembalikan panjang dari progress list*/
int pl_length(ProgressList pl) { return ll_length(pl); }

/*Menampilkan isi progress list ke layar*/
void pl_display_progress(ProgressList pl) { ll_display_list(pl); }

/* Mengembalikan true bila ada VIP Item di progress list */
boolean pl_is_any_vip(ProgressList pl) {
  ProgressList l = FIRST(pl);
  boolean result = false;

  while (l && !result) {
    if (l->payload.item.itemID == 'V') {
      result = true;
    } else {
      l = l->next;
    }
  }

  return result;
}

Order *pl_get_order_by_item(ProgressList pl, Item i) {
  ProgressList l = FIRST(pl);
  boolean result = false;

  while (l && !result) {
    if (i_is_equal(l->payload.item, i)) {
      result = true;
    } else {
      l = l->next;
    }
  }

  return &(l->payload);
}

void pl_delete_by_order(ProgressList *pl, PlElType order) {
  int idx = ll_index_of(FIRST(pl), order);

  Order tmp;
  ll_delete_at(FIRST(pl), &tmp, idx);
}