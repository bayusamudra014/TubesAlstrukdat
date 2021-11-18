/* File : td_list.h */
/* ADT untuk To Do List, menggunakan ADT Linked List yang disesuaikan
 * primitifnya  */
/* ElType adalah Order */

#include "td_list.h"
/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/

/*  I.S. sembarang
    F.S. Terbentuk To Do List kosong */
void td_create(ToDoList *tdl) {
  /* Kamus */

  /* Algoritma */
  ll_create_list(tdl);
}

/*  I.S. To Do List tdl terdefinisi, mungkin kosong.
    F.S. Menambahkan Order order ke dalam To Do List di urutan terakhir. */
void td_insertTask(ToDoList *tdl, Order order) {
  /* Kamus */
  /* Algoritma */
  ll_insert_last(tdl, order);
}
/*  I.S Order dengan id=orderId ada pada tdl
    F.S Order dengan id=orderId dikeluarkan dari tdl
*/
void td_removeTask(ToDoList *tdl, Order *orderOut, int orderId) {
  /* Kamus */
  struct node *p, *q;
  /* Algoritma */
  p = FIRST(*tdl);
  q = p;

  if (INFO(p).orderID == orderId) {
    FIRST(*tdl) = NEXT(p);
  } else {
    while (INFO(NEXT(p)).orderID != orderId) {
      p = NEXT(p);
    }

    q = NEXT(p);

    if (NEXT(q) == NULL) {
      NEXT(p) = NULL;
    } else {
      NEXT(p) = NEXT(q);
    }
  }

  if (orderOut) {
    *orderOut = INFO(q);
  }
  // free(q);
}

/*  I.S tdl tidak kosong
    F.S order ke idx di dalam to do list dikeluarkan.
    orderOut berisi order yang dikeluarkan tadi.
    Prekondisi: idx valid untuk tdl.
*/
void td_removeTaskByIdx(ToDoList *tdl, Order *orderOut, int idx) {
  /* Kamus */
  /* Algoritma */
  ll_delete_at(tdl, orderOut, idx);
}

/* Mengembalikan Order ke idx . Diasumsikan idx valid untuk jumlah elemen tdl*/
Order td_getOrder(ToDoList tdl, int idx) {
  /* Kamus */
  /* Algoritma */
  return ll_get_elmt(tdl, idx);
}
/* Mengembalikan true bila to do list kosong */
boolean td_is_empty(ToDoList tdl) {
  /* Kamus */
  /* Algoritma */
  return ll_is_empty(tdl);
}
/* Mengembalikan panjang tdl, akan mengembalikan 0 jika tdl kosong */
int td_length(ToDoList tdl) {
  /* Kamus */
  /* Algoritma */
  return ll_length(tdl);
}