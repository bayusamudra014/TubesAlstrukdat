#include "item.h"

boolean i_is_equal(Item i1, Item i2) {
  return i1.expired == i2.expired && i1.itemID == i2.itemID &&
         i1.type == i2.type;
}