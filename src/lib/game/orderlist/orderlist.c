#include "orderlist.h"

void ol_create_orederlist(OrderList* ol) { q_create_queue(ol); }

void ol_add_order(OrderList* ol, Order order) { q_enqueue(ol, order); }

Order ol_get_head(OrderList ol) { return q_get_head(ol); }

Order ol_dequeue_order(OrderList* ol) {
  Order result;
  q_dequeue(ol, &result);

  return result;
}

int ol_order_count(OrderList ol) { return q_length(ol); }

Order* ol_get_all_order(OrderList ol) { return ol.buffer; }

boolean ol_is_empty(OrderList ol) { return q_is_empty(ol); }