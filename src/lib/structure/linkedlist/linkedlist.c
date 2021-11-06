#include "linkedlist.h"
#include <stdio.h>


void ll_create_list(LinkedList *ll){
    FIRST(*ll) = NULL;
}

void ll_set_elmt(LinkedList *ll, int idx, LlEltype value){
    int cnt = 0;
    struct node* p = FIRST(*ll);
    while (cnt < idx){
        cnt++;
        p = NEXT(p);
    }
    INFO(p) = value;
}

LlEltype ll_get_elmt(LinkedList ll, int idx){
    int cnt = 0;
    struct node* p = FIRST(ll);
    while (cnt < idx){
        cnt++;
        p = NEXT(p);
    }
    return INFO(p);
}

int ll_length(LinkedList ll) {
    
    int cnt = 0;
    struct node* p = FIRST(ll);
    while (p != NULL){
        cnt++;
        p = NEXT(p);
    }
    return cnt;
}

boolean ll_is_empty(LinkedList ll){
    return (FIRST(ll) == NULL);
}

int ll_index_of(LinkedList ll, LlEltype value){
    struct node* p = FIRST(ll);
    boolean found = false;
    int idx = 0;
    while ((!found) && (p != NULL)){
        if (o_is_equal(INFO(p), value)){
            found = true;
        }
        else{
            idx++;
            p = NEXT(p);
        }
    }

    if (found){
        return idx;
    }
    else{
        return IDX_UNDEF;
    }
}

void ll_insert_first(LinkedList *ll, LlEltype value){
    
    if (ll_is_empty(*ll)){
        FIRST(*ll) = n_create_node(value);
    }else{
        struct node* p = n_create_node(value);
        NEXT(p) = FIRST(*ll);
        FIRST(*ll) = p;
    }
}

void ll_insert_at(LinkedList* ll, LlEltype value, int idx){
    
    if (idx == 0){
        ll_insert_first(ll, value);
    }
    else{
        struct node* p = n_create_node(value);
        
        if (p != NULL){
            int cnt = 0;
            struct node* loc = FIRST(*ll);
            while (cnt < idx-1){
                cnt++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

void ll_insert_last(LinkedList *ll, LlEltype value){
    
    if (ll_is_empty(*ll)){
        FIRST(*ll) = n_create_node(value);
    }
    else{
        struct node* p = n_create_node(value);
        
        struct node* last = FIRST(*ll);
        while (NEXT(last) != NULL){
            last = NEXT(last);
        }
        NEXT(last) = p;
    }
}

void ll_delete_first(LinkedList *ll, LlEltype *deletedValue){
    
    struct node* p = FIRST(*ll);
    (*deletedValue) = INFO(p);
    FIRST(*ll) = NEXT(p);
}

void ll_delete_at(LinkedList *ll, LlEltype *deletedValue, int idx){
    
    if (idx == 0){
        ll_delete_first(ll, deletedValue);
    }
    else{
        int cnt = 0;
        struct node* loc = FIRST(*ll);
        while (cnt < idx-1){
            cnt++;
            loc = NEXT(loc);
        }
        struct node* p = NEXT(loc);
        *deletedValue = INFO(p);
        NEXT(loc) = NEXT(p);
    }
}

void ll_delete_last(LinkedList *ll, LlEltype *deletedValue){
    
    struct node* p = FIRST(*ll);
    struct node* loc = NULL;
    
    if (NEXT(p) == NULL){
        ll_delete_first(ll, deletedValue);
    }else{
        while (NEXT(p) != NULL){
            loc = p;
            p = NEXT(p);
        }
        NEXT(loc) = NULL;
        (*deletedValue) = INFO(p);    
    }
}

void ll_display_list(LinkedList ll){

    struct node* p = FIRST(ll);

    printf("[");
    while (p != NULL){
        if(p == FIRST(ll)){
            printf("%d", INFO(p).incomingTime);
        }else{
            printf(",%d", INFO(p).incomingTime);
        }
        p = NEXT(p);
    }
    printf("]");

}