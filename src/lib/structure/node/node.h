#ifndef H_NODE
#define H_NODE

#include "../structure.h"


typedef struct node {
  Order payload;
  struct node* next;
} Node;

#define INFO(p) (p)->payload
#define NEXT(p) (p)->next

struct node* n_create_node(Order payload);
struct node* n_delete_node();

#endif