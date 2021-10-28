#include "linkedlist.h"

void CreateList(List *l){
    FIRST(*l) = NULL;
}

boolean isEmpty(List l){
    return (FIRST(l) == NULL);
}

ElType getElmt(List l, int idx){
    int cnt = 0;
    Address p = FIRST(l);
    while (cnt < idx){
        cnt++;
        p = NEXT(p);
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType value){
    int cnt = 0;
    Address p = FIRST(*l);
    while (cnt < idx){
        cnt++;
        p = NEXT(p);
    }
    INFO(p) = value;
}

int indexOf(List l, ElType val){
    Address p = FIRST(l);
    boolean found = false;
    int idx = 0;
    while ((!found) && (p != NULL)){
        if (INFO(p) == val) {
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

void insertFirst(List *l, ElType val){
    Address p = newNode(val);
    if (p != NULL){
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType val){
    if (isEmpty(*l)){
        insertFirst(l, val);
    } 
    else{
        Address p = newNode(val);
        if (p != NULL){
            Address last = FIRST(*l);
            while (NEXT(last) != NULL){
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
    if (idx == 0){
        insertFirst(l, val);
    } 
    else{
        Address p = newNode(val);
        if (p != NULL){
            int cnt = 0;
            Address loc = FIRST(*l);
            while (cnt < idx-1){
                cnt++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

void deleteFirst(List *l, ElType *val){
    Address p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val){
    Address p = FIRST(*l);
    Address loc = NULL;
    while (NEXT(p) != NULL){
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL){
        FIRST(*l) = NULL;
    } 
    else{
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val){
    if (idx == 0){
        deleteFirst(l, val);
    }
    else{
        int cnt = 0;
        Address loc = FIRST(*l);
        while (cnt < idx-1){
            cnt++;
            loc = NEXT(loc);
        }
        Address p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

void displayList(List l){
    if (!isEmpty(l)){
        Address p = FIRST(l);
        printf("[");
        do{
            printf("%d", INFO(p));
            p = NEXT(p);
            if (p != NULL){
                printf(",");
            }
        } 
        while (p != NULL);
        printf("]");
    }
    else{
        printf("[]");
    }
}

int length(List l) {
    int cnt = 0;
    Address p = FIRST(l);
    while (p != NULL){
        cnt++;
        p = NEXT(p);
    }
    return cnt;
}

List concat(List l1, List l2) {
    List l3;
    CreateList(&l3);
    Address p = FIRST(l1);
    while (p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}