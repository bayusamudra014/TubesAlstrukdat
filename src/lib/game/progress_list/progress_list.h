#ifndef H_PROGRESS_LIST
#define H_PROGRESS_LIST

#include "../game.h"

typedef LinkedList ProgressList;

typedef Order PlElType;

/*Membuat progress list yang baru*/
void pl_create_progress(ProgressList *pl);

/*Menghasilkan true apabila progress list masih kosong*/
boolean pl_is_empty(ProgressList pl);

/*Menambahkan order baru kedalam progress list*/
/*order baru tersebut menjadi elemen terakhir dari progress list*/
void pl_insert_last(ProgressList *pl, PlElType order);

/*Menghapus order pertama dari progress list */
/*Hal ini terjadi ketika order telah selesai diantarkan*/
void pl_delete_first(ProgressList *pl, PlElType *order);

/*Menampilkan isi progress list ke layar*/
void pl_display_progress(ProgressList pl);

/*Mengembalikan panjang dari progress list*/
int pl_length(ProgressList pl);

/* Mengembalikan true bila ada VIP Item di progress list */
boolean pl_is_any_vip(ProgressList pl);

/* I.S. Progress List terdefinisi
   F.S. Mengembalikan referensi item bila ada. 
        Bila tidak, mengembalikan null. */
Order* pl_get_order_by_item(ProgressList* pl, Item i);

/* I.S. Progress list tedefinisi
   F.S. Menghapus order pertama yang ditemukan di progress list.
        Bila tidak ada, maka tidak dilakukan apa-apa. */
void pl_delete_by_order(ProgressList *pl, PlElType order);

#endif