#ifndef H_ORDER
#define H_ORDER

#include "../building/building.h"
#include "../item/item.h"
#include "../time/time.h"

typedef struct order {
  Item item;
  Building pickUp;
  Building dropOff;
  Time incomingTime;
} Order;

#endif