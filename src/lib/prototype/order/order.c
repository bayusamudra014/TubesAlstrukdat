#include "order.h"

boolean o_is_equal(Order order1, Order order2) {
  return b_is_equal(order1.dropOff, order2.dropOff) &&
         order1.incomingTime == order2.incomingTime &&
         order1.orderID == order2.orderID &&
         b_is_equal(order1.pickUp, order2.pickUp) &&
         i_is_equal(order1.item, order2.item);
}