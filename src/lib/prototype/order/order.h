#ifndef H_ORDER
#define H_ORDER

#include "building/building.h"
#include "item/item.h"
#include "time/time.h"

typedef struct order {
  int orderID;
  Item item;
  Building pickUp;
  Building dropOff;
  Time incomingTime;
} Order;

/* Memeriksa apakah dua order merupakan order yang sama */
boolean o_is_equal(Order order1, Order order2);

/* Membuat Objek Order baru
    I.S. order sembarang
    F.S. Order didefinisikan dengan data yang diinputkan
*/
void o_create_order(Order* order, Item item, 
      Building pickup, Building dropoff, Time incommingTime);

/* Menghasilkan nilai true bila incommingTime >= currentTime */
boolean o_is_order_todo(Order order, Time currentTime);

/* Mendapatkan item dari sebuah order */
Item o_get_item(Order order);

#endif