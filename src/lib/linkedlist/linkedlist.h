#ifndef H_LINKED_LIST
#define H_LINKED_LIST

#include "../lib.h"

typedef struct node* LinkedList;

typedef Order LlEltype;

/* Konstrukror List Dinamis */
void ll_create_list(LinkedList* ll);

void ll_set_elmt(LinkedList* ll, int idx, LlEltype value);

LlEltype ll_get_elmt(LinkedList ll, int idx);

/* Menghitung jumlah elemen yang berada pada dynamic list */
int ll_length(LinkedList ll);

/* Mengembalikan true bila list statis kosong */
boolean ll_is_empty(LinkedList ll);

/* Mengembalikan nilai indeks dari list statis */
int ll_index_of(LinkedList ll, LlEltype value);

/* Menambahkan elemen baru di awal list */
void ll_insert_first(LinkedList* ll, LlEltype value);

/* Menambahkan elemen pada indeks tertentu */
void ll_insert_at(LinkedList* ll, LlEltype value, int idx);

/* Menambahkan elemen pada akhir list */
void ll_insert_last(LinkedList* ll, LlEltype value);

/* Menghapus elemen di awal list.

   I.S. List tidak kosong

   F.S. Elemen pertama dihapus. Bila deletedValue tidak bernilai NULL,
   alamat yang ditunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus. */
void ll_delete_first(LinkedList* ll, LlEltype* deletedValue);

/* Menghapus elemen di awal list.

   I.S. Indeks idx < length list.

   F.S. Elemen pada index idx dihapus, bila deletedValue tidak bernilai NULL,
   alamat yang dithunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus. */
void ll_delete_at(LinkedList* ll, LlEltype* deletedValue, int idx);

/* Menghapus elemen pada akhir list.

   I.S. List tidak kosong.

   F.S. Elemen terakhir dihapus. Bila deletedValue tidak bernilai NULL,
   alamat yang ditunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus.*/
void ll_delete_last(LinkedList* ll, LlEltype* deletedValue);

#endif