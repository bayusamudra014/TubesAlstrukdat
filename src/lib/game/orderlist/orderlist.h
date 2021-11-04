#include "../game.h"

typedef Queue OrderList;

/* Membuat Order List baru */
void ol_create_orederlist(OrderList *ol);

/* Menambahkan order baru */
void ol_add_order(OrderList *ol, Order order);

/* Mendapatkan order yang paling depan */
Order ol_get_head(OrderList ol);

/* Menghapus order teratas dan mengembalikannya */
Order ol_dequeue_order(OrderList* ol);

/* Mengembalikan jumlah order yang ada */
int ol_order_count(OrderList ol);

/* Mengembalikan semua order dengan urutan sesuai dengan waktunya */
Order* ol_get_all_order(OrderList ol);

/* Mengembalikan true bila order sudah habis */
boolean ol_is_empty(OrderList ol);