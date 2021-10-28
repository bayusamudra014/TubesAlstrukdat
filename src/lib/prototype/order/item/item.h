#ifndef H_ITEM
#define H_ITEM

#include "../../../boolean.h"

typedef struct item {
  int itemID;
  int expired;
  char type;
} Item;

boolean i_is_equal(Item i1, Item i2);

#endif