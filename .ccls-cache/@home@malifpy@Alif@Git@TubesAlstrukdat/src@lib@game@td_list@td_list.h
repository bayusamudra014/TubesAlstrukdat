/* File : td-list.h */
/* ADT untuk To Do List, menggunakan ADT Linked List yang disesuaikan primitifnya  */
/* ElType adalah Order */

#ifndef H_TD_LIST
#define H_TD_LIST



#include "../game.h"

typedef LinkedList ToDoList;
 


/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/

/*  I.S. sembarang             
    F.S. Terbentuk To Do List kosong */
void td_create(ToDoList *tdl);

/*  I.S. To Do List tdl terdefinisi, mungkin kosong.             
    F.S. Menambahkan Order order ke dalam To Do List di urutan terakhir. */
void td_insertTask(ToDoList *tdl, Order order);

/*  I.S Order dengan id=orderId ada pada tdl
    F.S Order dengan id=orderId dikeluarkan dari tdl
*/
void td_removeTask(ToDoList *tdl, Order *orderOut, int orderId);

/*  I.S tdl tidak kosong
    F.S order ke idx di dalam to do list dikeluarkan. 
    orderOut berisi order yang dikeluarkan tadi.
    Prekondisi: idx valid untuk tdl.
*/
void td_removeTaskByIdx(ToDoList *tdl, Order *orderOut, int idx);

/* Mengembalikan Order ke idx . Diasumsikan idx valid untuk jumlah elemen tdl*/ 
Order td_getOrder(ToDoList tdl, int idx);

/* Mengembalikan true bila to do list kosong */
boolean td_is_empty(ToDoList tdl);

/* Mengembalikan panjang tdl, akan mengembalikan 0 jika tdl kosong */
int td_length(ToDoList tdl);

#endif