#ifndef H_BUILDINGLIST
#define H_BUILDINGLIST

#include "building.h"
#include "../../structure/dynamiclist/dynamiclist.h"

typedef Building blElType;

typedef struct building_list {
    blElType *buffer;
    int nEff;       
    int capacity; 
} Building_list;

#define IDX_UNDEF -1
#define nEff(l) (l).nEff
#define buffer(l) (l).buffer
#define bl_elmt(l, i) (l).buffer[i]
#define CAP(l) (l).capacity

/* I.S. capacity > 0 */
/* F.S. terbentuk bl kosong dengan capacity (capacity) */
void bl_create(Building_list *bl, int capacity);

/* I.S. bl terdefinisi */
/* F.S. bl terdealokasi */
void bl_free(Building_list *bl);

/*mengembalikan banyaknya elemen dalam list, 0 jika kosong*/
int bl_length(Building_list bl);

/* mengembalikan indeks terakhir list*/
int bl_get_lastidx(Building_list bl);

/* mengembalikan true apabila indeks valid*/
boolean bl_is_idxvalid(Building_list bl, int i);

/* mengembalikan true apabila indeks efektif*/
boolean bl_is_idxeff(Building_list bl, int i);

/* mengembalikan true apabila list kosong*/
boolean bl_is_empty(Building_list bl);

/* mengembalikan true apabila list penuh*/
boolean bl_is_full(Building_list bl);

/* I.S. bl terdefinisi */
/* F.S. isi bl tercetak ke layar */
void bl_display(Building_list bl);

/* I.S. blIn terdefinisi */
/* F.S. blin tersalin blout */
void bl_copy(Building_list blIn, Building_list *blOut);

/* I.S. bl terdefinisi dan tidak penuh */
/* F.S. val menjadi elemen terakhir bl */
void bl_insert_Last(Building_list *bl, blElType val);

/* I.S. bl terdefinisi dan tidak kosong */
/* F.S. elemen terakhir dihapus, disimpan pada val */
void bl_deleteLast(Building_list *bl, blElType *val);

/* I.S. bl terdefinisi */
/* F.S. Ukuran bl berubah sesuai n */
void bl_change_capacity(Building_list *bl, int n);

#endif