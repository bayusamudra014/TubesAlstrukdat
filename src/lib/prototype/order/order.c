#include "order.h"

static int __o_order_id = 0;

boolean o_is_equal(Order order1, Order order2) {
  return b_is_equal(order1.dropOff, order2.dropOff) &&
         order1.incomingTime == order2.incomingTime &&
         order1.orderID == order2.orderID &&
         b_is_equal(order1.pickUp, order2.pickUp) &&
         i_is_equal(order1.item, order2.item);
}

void o_create_order(Order* order, Item item, Building pickup, Building dropoff,
                    Time incommingTime) {
  order->orderID = __o_order_id;
  order->item = item;
  order->pickUp = pickup;
  order->dropOff = dropoff;
  order->incomingTime = incommingTime;
  order->expiredTime = (Time)-1;

  __o_order_id++;
}

boolean o_is_order_todo(Order order, Time currentTime) {
  return order.incomingTime >= currentTime;
}

Item o_get_item(Order order) { return order.item; }

boolean o_is_expired(Order o, Time currentTime) {
  return o.expiredTime >= currentTime;
}