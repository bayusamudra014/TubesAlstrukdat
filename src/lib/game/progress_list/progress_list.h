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

#endif