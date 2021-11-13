#include "building_list.h"

void bl_create(Building_list *bl, int capacity){
    buffer(*bl) = (blElType *)malloc(capacity * sizeof(blElType));
    nEff(*bl) = 0;
    CAP(*bl) = capacity;
}

void bl_free(Building_list *bl){
    free(buffer(*bl));
    CAP(*bl) = 0;
    nEff(*bl) = 0;
}

int bl_length(Building_list bl){
    return nEff(bl);
}

int bl_get_lastidx(Building_list bl){
    return length(bl)-1;
}

boolean bl_is_idxvalid(Building_list bl, int i){
    return (i >= 0 && i < CAP(bl));
}

boolean bl_is_idxeff(Building_list bl, int i){
    return (i >= 0 && i < nEff(bl));
}

boolean bl_is_empty(Building_list bl){
    return (length(bl) == 0);
}

boolean bl_is_full(Building_list bl){
    return (length(bl) == CAP(bl));
}

void bl_display(Building_list bl){
    int i;

    if (isEmpty(bl)){
        printf("[]");
    }
    else{
        printf("[");
        for (i = 0; i < length(bl); i++){
            if (i == 0){
                printf("%d", bl_elmt(bl, i));
            }
            else{
                printf(",%d", bl_elmt(bl, i));
            }
        }
        printf("]");
    }
}

void bl_copy(Building_list blIn, Building_list *blOut){
    bl_create(blOut, CAP(blIn));
    nEff(*blOut) = nEff(blIn);
    CAP(*blOut) = CAP(blIn);

    int i;
    for (i = 0; i < length(blIn); i++)
    {
        bl_elmt(*blOut, i) = bl_elmt(blIn, i);
    }
}

void bl_insert_Last(Building_list *bl, blElType val){
    bl_elmt(*bl, bl_get_lastidx(*bl)+1) = val;
    nEff(*bl) += 1;
}

void bl_deleteLast(Building_list *bl, blElType *val){
    *val = bl_elmt(*bl, bl_get_lastidx(*bl));
    nEff(*bl) -= 1;
}

void bl_change_capacity(Building_list *bl, int n){
    CAP(*bl) += n;
}