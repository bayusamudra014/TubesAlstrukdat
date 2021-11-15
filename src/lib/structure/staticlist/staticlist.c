#include "staticlist.h"

/* Menukarkan nilai indeks 1 dan indeks 2 */
void __sl_swap(StaticList* sl, int idx1, int idx2) {
  SlEltype tmp = sl_elmt(*sl, idx1);
  sl_elmt(*sl, idx1) = sl_elmt(*sl, idx2);
  sl_elmt(*sl, idx2) = tmp;
}

void sl_create_list(StaticList* sl) { sl->length = 0; }

int sl_length(StaticList sl) { return sl.length; }

/* Mengembalikan true bila list statis kosong */
boolean sl_is_empty(StaticList sl) { return !sl_length(sl); }

/* Mengembalikan true bila list statis penuh */
boolean sl_is_full(StaticList sl) { return sl_length(sl) == SL_CAPACITY; }

/* Mengembalikan nilai indeks dari list statis */
int sl_index_of(StaticList sl, SlEltype value) {
  boolean found = false;
  int i = 0;

  while (i < SL_CAPACITY && !found) {
    if (sl_elmt(sl, i).gadgetID == value.gadgetID) {
      found = true;
    } else {
      i++;
    }
  }

  return i;
}

/* Menambahkan elemen baru di awal list */
void sl_insert_first(StaticList* sl, SlEltype value) {
  sl_insert_at(sl, value, 0);
}

/* Menambahkan elemen pada indeks tertentu */
void sl_insert_at(StaticList* sl, SlEltype value, int idx) {
  int len = sl_length(*sl);

  sl_elmt(*sl, len) = value;

  while (len > idx) {
    __sl_swap(sl, len, len - 1);
    len--;
  }

  sl->length++;
}

/* Menambahkan elemen pada akhir list */
void sl_insert_last(StaticList* sl, SlEltype value) {
  sl_insert_at(sl, value, sl_length(*sl));
}

/* Menghapus elemen di awal list.

   I.S. List tidak kosong

   F.S. Elemen pertama dihapus. Bila deletedValue tidak bernilai NULL,
   alamat yang ditunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus. */
void sl_delete_first(StaticList* sl, SlEltype* deletedValue) {
  sl_delete_at(sl, deletedValue, 0);
}

/* Menghapus elemen di awal list.

   I.S. Indeks idx < length list.

   F.S. Elemen pada index idx dihapus, bila deletedValue tidak bernilai NULL,
   alamat yang dithunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus. */
void sl_delete_at(StaticList* sl, SlEltype* deletedValue, int idx) {
  if (deletedValue) {
    *deletedValue = sl_elmt(*sl, idx);
  }

  for (int i = idx + 1; i < sl_length(*sl); i++) {
    sl_elmt(*sl, i - 1) = sl_elmt(*sl, i);
  }

  sl->length--;
}

/* Menghapus elemen pada akhir list.

   I.S. List tidak kosong.

   F.S. Elemen terakhir dihapus. Bila deletedValue tidak bernilai NULL,
   alamat yang ditunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus.*/
void sl_delete_last(StaticList* sl, SlEltype* deletedValue) {
  if (deletedValue) {
    *deletedValue = sl_elmt(*sl, sl_length(*sl) - 1);
  }

  sl->length--;
}