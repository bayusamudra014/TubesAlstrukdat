#include "node.h"
#include <stdlib.h>


struct node* n_create_node(Order payload) {
    struct node* p = (struct node*) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = payload;
        NEXT(p) = NULL;
    }
    return p;
}