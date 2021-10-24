#ifndef H_NODE
#define H_NODE

#include "../order/order.h"

typedef struct node {
  Order payload;
  struct node* next;
} Node;

void n_create_node(Node* n, Order payload);
void n_delete_node(Node* n);

#endif