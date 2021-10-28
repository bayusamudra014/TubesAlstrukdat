#include "queue.h"

#include <stdio.h>

// /*Konstruktor*/
// /* I.S. sembarang */
// /* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
// /* - Index head bernilai IDX_UNDEF */
// /* - Index tail bernilai IDX_UNDEF */
// /* Proses : Melakukan alokasi, membuat sebuah q kosong */
void q_create_queue(Queue* q) {
  Q_IDX_HEAD(*q) = IDX_UNDEF;
  Q_IDX_TAIL(*q) = IDX_UNDEF;
}

/* Mengirim true jika q kosong: lihat definisi di atas */
boolean q_is_empty(Queue q) {
  return ((Q_IDX_HEAD(q) == IDX_UNDEF) && (Q_IDX_TAIL(q) == IDX_UNDEF));
}

/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai Q_SIZE-1 */
boolean q_is_full(Queue q) {
  return ((Q_IDX_HEAD(q) == 0) && (Q_IDX_TAIL(q) == Q_SIZE - 1));
}

/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
int q_length(Queue q) {
  int q_length;

  if (q_is_empty(q)) {
    q_length = 0;
  } else {
    q_length = (Q_IDX_TAIL(q) - Q_IDX_HEAD(q) + 1);
  }

  return q_length;
}

/* Proses: Menambahkan Order pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. Order menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika pq penuh semu, maka perlu dilakukan aksi penggeseran "maju"
        elemen-elemen pq menjadi rata kiri untuk membuat ruang kosong bagi
        TAIL baru
        prioritas queue berdasarkan waktu kedatangan order.
*/
void q_enqueue(Queue* q, QEltype order) {
  boolean found;

  if (q_is_empty(*q)) {
    Q_IDX_HEAD(*q) = 0;
    Q_IDX_TAIL(*q) = 0;
    Q_TAIL(*q) = order;
  } else {
    // Apabila queue nya penuh semu
    if (Q_IDX_TAIL(*q) == Q_SIZE - 1) {
      for (int i = Q_IDX_HEAD(*q); i <= Q_IDX_TAIL(*q); i++) {
        (*q).buffer[i - Q_IDX_HEAD(*q)] = (*q).buffer[i];
      }
      Q_IDX_TAIL(*q) -= Q_IDX_HEAD(*q);
      Q_IDX_HEAD(*q) = 0;
    }

    int i = Q_IDX_HEAD(*q);
    found = false;

    while ((i <= Q_IDX_TAIL(*q)) && (!found)) {
      if ((*q).buffer[i].incomingTime > order.incomingTime) {
        found = true;
      } else {
        i++;
      }
    }

    Q_IDX_TAIL(*q)++;
    if (!found) {
      Q_TAIL(*q) = order;
    } else {
      for (int j = Q_IDX_TAIL(*q); j >= i; j--) {
        (*q).buffer[j + 1] = (*q).buffer[j];
      }
      (*q).buffer[i] = order;
    }
  }
}

/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD "mundur";
         pq mungkin kosong */
void q_dequeue(Queue* q, QEltype* order) {
  *order = Q_HEAD(*q);
  if (Q_IDX_HEAD(*q) == Q_IDX_TAIL(*q)) {
    Q_IDX_HEAD(*q) = IDX_UNDEF;
    Q_IDX_TAIL(*q) = IDX_UNDEF;
  } else {
    Q_IDX_HEAD(*q)++;
  }
}

/*Getter elemen head dari queue*/
QEltype q_get_head(Queue q) { return (Q_HEAD(q)); }

/*Getter elemen tail dari queue*/
QEltype q_get_tail(Queue q) { return Q_TAIL(q); }