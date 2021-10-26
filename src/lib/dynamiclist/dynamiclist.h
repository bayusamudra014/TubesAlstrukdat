#ifndef H_DYNAMIC_LIST
#define H_DYNAMIC_LIST

#include "../lib.h"

typedef Building DlEltype;

typedef struct dynamiclist {
  DlEltype* buffer;
  int capacity;
  int nEff;
} DynamicList;

/* Konstrukror List Dinamis */
void dl_create_list(DynamicList* dl, int size);

/* Selektor untuk mengakses element pada dynamic list */
#define dl_elmt(dl, i) dl.buffer[i]

/* Menghitung jumlah elemen yang berada pada dynamic list */
int dl_length(DynamicList dl);

/* Menghitung kapasitas dynamic list */
int dl_capacity(DynamicList dl);

/* Mengembalikan true bila list statis kosong */
boolean dl_is_empty(DynamicList dl);

/* Mengembalikan true bila list statis penuh */
boolean dl_is_full(DynamicList dl);

/* Mengembalikan nilai indeks dari list statis */
int dl_index_of(DynamicList dl, DlEltype value);

/* Menambahkan elemen baru di awal list */
void dl_insert_first(DynamicList* dl, DlEltype value);

/* Menambahkan elemen pada indeks tertentu */
void dl_insert_at(DynamicList* dl, DlEltype value, int idx);

/* Menambahkan elemen pada akhir list */
void dl_insert_last(DynamicList* dl, DlEltype value);

/* Menghapus elemen di awal list.

   I.S. List tidak kosong

   F.S. Elemen pertama dihapus. Bila deletedValue tidak bernilai NULL,
   alamat yang ditunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus. */
void dl_delete_first(DynamicList* dl, DlEltype* deletedValue);

/* Menghapus elemen di awal list.

   I.S. Indeks idx < length list.

   F.S. Elemen pada index idx dihapus, bila deletedValue tidak bernilai NULL,
   alamat yang dithunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus. */
void dl_delete_at(DynamicList* dl, DlEltype* deletedValue, int idx);

/* Menghapus elemen pada akhir list.

   I.S. List tidak kosong.

   F.S. Elemen terakhir dihapus. Bila deletedValue tidak bernilai NULL,
   alamat yang ditunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus.*/
void dl_delete_last(DynamicList* dl, DlEltype* deletedValue);

#endif