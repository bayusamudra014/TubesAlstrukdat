#ifndef H_NODE
#define H_NODE

#include "../structure.h"

typedef struct node {
  Order payload;
  struct node* next;
} Node;

#define INFO(p) (p)->payload
#define NEXT(p) (p)->next

void n_create_node(Node* n, Order payload);
void n_delete_node(Node* n);

#endif