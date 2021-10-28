#ifndef H_STACK
#define H_STACK

#include "../structure.h"

#define S_MAX_SIZE 100
#define IDX_UNDEF -1

typedef Item SEltype;

typedef struct stack
{
  SEltype buffer[S_MAX_SIZE];
  int idxTop;
} Stack;

/* Akses Selektor */
#define S_IDX_TOP(s) (s).idxTop
#define S_TOP(s) (s).buffer[(s).idxTop]


/*Konstruktor*/
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
void s_create_stack(Stack* s);


/* Mengirim true jika s kosong: lihat definisi di atas */
boolean s_is_empty(Stack s);


/* Mengirim true jika tabel penampung nilai s stack penuh */
boolean s_is_full(Stack s);


/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
void s_push(Stack* s, SEltype item);


/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
void s_pop(Stack* s, SEltype* item);

/*Getter untuk mendapatkan TOP dari Stack(Tas)*/
SEltype s_get_top(Stack s);

#endif