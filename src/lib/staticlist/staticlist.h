#ifndef H_STATIC_LIST
#define H_STATIC_LIST

#define SL_CAPACITY 5

#include "../gadget/gadget.h"

typedef Gadget SlEltype;

typedef struct staticlist {
  SlEltype buffer[SL_CAPACITY];
} StaticList;

/* Membuat Objek Static List */
void sl_create_list(StaticList* sl);

/* Selektor untuk mengakses element pada static list */
#define sl_elmt(sl, i) sl.buffer[i]

/* Menghitung jumlah elemen yang berada pada static list */
int sl_length(StaticList sl);

/* Mengembalikan true bila list statis kosong */
boolean sl_is_empty(StaticList sl);

/* Mengembalikan true bila list statis penuh */
boolean sl_is_full(StaticList sl);

/* Mengembalikan nilai indeks dari list statis */
int sl_index_of(StaticList sl, SlEltype value);

/* Menambahkan elemen baru di awal list */
void sl_insert_first(StaticList* sl, SlEltype value);

/* Menambahkan elemen pada indeks tertentu */
void sl_insert_at(StaticList* sl, SlEltype value, int idx);

/* Menambahkan elemen pada akhir list */
void sl_insert_last(StaticList* sl, SlEltype value);

/* Menghapus elemen di awal list.

   I.S. List tidak kosong

   F.S. Elemen pertama dihapus. Bila deletedValue tidak bernilai NULL,
   alamat yang ditunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus. */
void sl_delete_first(StaticList* sl, SlEltype* deletedValue);

/* Menghapus elemen di awal list.

   I.S. Indeks idx < length list.
   
   F.S. Elemen pada index idx dihapus, bila deletedValue tidak bernilai NULL,
   alamat yang dithunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus. */
void sl_delete_at(StaticList* sl, SlEltype* deletedValue, int idx);

/* Menghapus elemen pada akhir list.

   I.S. List tidak kosong.
   
   F.S. Elemen terakhir dihapus. Bila deletedValue tidak bernilai NULL,
   alamat yang ditunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus.*/
void sl_delete_last(StaticList* sl, SlEltype* deletedValue);

#endif