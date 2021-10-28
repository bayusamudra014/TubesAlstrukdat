
#include "stack.h"

#include "stdio.h"

/*Konstruktor*/
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
void s_create_stack(Stack* s) { S_IDX_TOP(*s) = IDX_UNDEF; }

/* Mengirim true jika s kosong: lihat definisi di atas */
boolean s_is_empty(Stack s) { return (S_IDX_TOP(s) == IDX_UNDEF); }

/* Mengirim true jika tabel penampung nilai s stack penuh */
boolean s_is_full(Stack s) { return (S_IDX_TOP(s) == S_MAX_SIZE - 1); }

/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
void s_push(Stack* s, SEltype item) {
  S_IDX_TOP(*s)++;
  S_TOP(*s) = item;
}

/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
void s_pop(Stack* s, SEltype* item) {
  *item = S_TOP(*s);
  S_IDX_TOP(*s)--;
}

/*Getter untuk mendapatkan TOP dari Stack(Tas)*/
SEltype s_get_top(Stack s) { return S_TOP(s); }