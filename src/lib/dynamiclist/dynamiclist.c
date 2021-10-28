#include "../lib.h"
#include <stdlib.h>

/* Konstrukror List Dinamis */
void dl_create_list(DynamicList* dl, int size){
    dl->buffer = (DlEltype *) malloc(size * sizeof(DlEltype));
    dl->capacity = size;
    dl->nEff = 0;
}

void dl_free_list(DynamicList* dl){
    free(dl->buffer);
}

void dl_resize_list(DynamicList* dl, int addSize){
    int newsize = dl->capacity + addSize;
    // Array baru
    DlEltype* newBuffer = (DlEltype *) malloc(newsize * sizeof(DlEltype));

    // Copy semua isi array lama ke baru
    int i = 0;
    while(i < dl_length(*dl) && i < newsize){
        newBuffer[i] = dl_elmt(*dl, i);
        i++;
    }

    // Bebaskan array lama
    dl_free_list(dl);

    // Masukkan buffer baru
    dl->buffer = newBuffer;

    // Ganti kapasitas
    dl->capacity = newsize;

    // Kalau kapasitasnya kurang dari nEff, atur nEff
    if(dl->capacity < dl->nEff){
        dl->nEff = dl_capacity(*dl);
    }
    
}

/* Menghitung jumlah elemen yang berada pada dynamic list */
int dl_length(DynamicList dl){
    return dl.nEff;
}

/* Menghitung kapasitas dynamic list */
int dl_capacity(DynamicList dl){
    return dl.capacity;
}

/* Mengembalikan true bila list statis kosong */
boolean dl_is_empty(DynamicList dl){
    return dl.nEff == 0;
}

/* Mengembalikan true bila list statis penuh */
boolean dl_is_full(DynamicList dl){
    return dl.nEff == dl.capacity;
}

/* Mengembalikan nilai indeks dari kemunculan
   pertama value di list statis */
int dl_index_of(DynamicList dl, DlEltype value){
    int i;

    /**
     * Kondisi berhenti : 
     *  - dl.buffer[i] == value
     *    Ketemu
     *  - i == dl_length
     *    Artinya sudah melewati panjang efektif, tidak ketemu
     */
    while(i < dl_length(dl) && !b_is_equal(dl_elmt(dl, i), value)){
        i++;
    }

    if (i < dl_length(dl)){
        return i;
    }
    else{
        return IDX_UNDEF;
    }
}
/**
 * I.S. *dl tidak penuh
 * F.S. Isi *dl yang dimulai dari index 
 *      idxStart digeser ke kanan sekali.
 *      elemen di idxStart kosong.
 */
void __dl_shift_right(DynamicList* dl, int idxStart){
    // Elemen terakhir
    int i;
    for (i = dl->nEff - 1; i >= idxStart; i--){
        dl_elmt(*dl, i + 1) = dl_elmt(*dl, i);
    }
}

/* Menambahkan elemen baru di awal list */
void dl_insert_first(DynamicList* dl, DlEltype value){
    dl_insert_at(dl, value, 0);
}

/* Menambahkan elemen pada indeks tertentu */
void dl_insert_at(DynamicList* dl, DlEltype value, int idx){
    // Kalau penuh, ukurannya ditambah satu
    if (dl_is_full(*dl)){
        dl_resize_list(dl, 1);
    }

    // Geser ke kanan
    __dl_shift_right(dl, idx);

    // Masukkan value ke idx
    dl_elmt(*dl, idx) = value;

    // Tambahkan nEff
    dl->nEff++;
}

/* Menambahkan elemen pada akhir list */
void dl_insert_last(DynamicList* dl, DlEltype value){
    dl_insert_at(dl, value, dl->nEff);
}

/**
 * I.S. idxStart bukan 0
 * F.S. Isi *dl yang dimulai dari index 
 *      idxStart digeser ke kiri sekali.
 */
void __dl_shift_left(DynamicList* dl, int idxStart){
    int i;
    for (i = idxStart; i < dl->nEff; i++){
        dl_elmt(*dl, i - 1) = dl_elmt(*dl, i);
    }
}

/* Menghapus elemen di awal list.

   I.S. List tidak kosong

   F.S. Elemen pertama dihapus. Bila deletedValue tidak bernilai NULL,
   alamat yang ditunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus. */
void dl_delete_first(DynamicList* dl, DlEltype* deletedValue){
    dl_delete_at(dl, deletedValue, 0);
}

/* Menghapus elemen di awal list.

   I.S. Indeks idx < length list.

   F.S. Elemen pada index idx dihapus, bila deletedValue tidak bernilai NULL,
   alamat yang dithunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus. */
void dl_delete_at(DynamicList* dl, DlEltype* deletedValue, int idx){
    *deletedValue = dl_elmt(*dl, idx);
    __dl_shift_left(dl, idx + 1);
    dl->nEff -= 1;
}

/* Menghapus elemen pada akhir list.

   I.S. List tidak kosong.

   F.S. Elemen terakhir dihapus. Bila deletedValue tidak bernilai NULL,
   alamat yang ditunjuk oleh deletedValue akan diassign dengan nilai
   yang sebelumnya dihapus.*/
void dl_delete_last(DynamicList* dl, DlEltype* deletedValue){
    dl_delete_at(dl, deletedValue, dl->nEff - 1);
}