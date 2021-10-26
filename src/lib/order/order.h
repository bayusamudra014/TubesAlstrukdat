#ifndef H_ORDER
#define H_ORDER

#include "../lib.h"

typedef struct order {
  int orderID;
  Item item;
  Building pickUp;
  Building dropOff;
  Time incomingTime;
} Order;

#endif