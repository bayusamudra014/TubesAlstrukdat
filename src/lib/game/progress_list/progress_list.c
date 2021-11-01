

#include <stdio.h>
#include "progress_list.h"

/*Membuat progress list yang baru*/
/*I.S. progress list sembarang*/
/*F.S. progress list kosong yang baru*/
void pl_create_progress(ProgressList *pl){

    ll_create_list(*pl);

}

/*Menghasilkan true apabila progress list masih kosong*/
boolean pl_is_empty(ProgressList pl){
    
    return ll_is_empty(pl);
}


/*Menambahkan order baru kedalam progress list*/
/*order baru tersebut menjadi elemen terakhir dari progress list*/
void pl_insert_last(ProgressList *pl, PlElType order){
    
    ll_insert_last(&pl, order);

}


/*Menghapus order pertama dari progress list */
/*Hal ini terjadi ketika order telah selesai diantarkan*/
void pl_delete_first(ProgressList *pl, PlElType *order){

    ll_delete_first(*pl, &order);
}

/*Menampilkan isi progress list ke layar*/
void pl_display_progress(ProgressList pl){
    Order order;
    char tujuan;
    char typeItem;

    tujuan = order.dropOff.label;
    typeItem = order.item.type;

}