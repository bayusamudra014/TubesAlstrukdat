// #include "stdio.h"
#include "queue.h"

// /*Konstruktor*/
// /* I.S. sembarang */
// /* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
// /* - Index head bernilai IDX_UNDEF */
// /* - Index tail bernilai IDX_UNDEF */
// /* Proses : Melakukan alokasi, membuat sebuah q kosong */
void q_create_queue(Queue* q) {
  q->idxHead = 0;
  q->idxTail = 0;
}

// /* Mengirim true jika q kosong: lihat definisi di atas */
// boolean q_is_empty(Queue q){

// }

// /* Mengirim true jika tabel penampung elemen q sudah penuh */
// /* yaitu jika index head bernilai 0 dan index tail bernilai Q_SIZE-1 */
// boolean q_is_full(Queue q){

// }

// /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
// int q_length(Queue q){

// }

// /* Proses: Menambahkan Order pada pq dengan aturan FIFO */
// /* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
// /* F.S. Order menjadi TAIL yang baru, IDX_TAIL "mundur".
//         Jika pq penuh semu, maka perlu dilakukan aksi penggeseran "maju"
//         elemen-elemen pq menjadi rata kiri untuk membuat ruang kosong bagi
//         TAIL baru
//           */
// void q_enqueue(Queue* q, QEltype item){

// }

// /* Proses: Menghapus val pada q dengan aturan FIFO */
// /* I.S. pq tidak mungkin kosong */
// /* F.S. val = nilai elemen HEAD pd
// I.S., HEAD dan IDX_HEAD "mundur";
//         pq mungkin kosong */
// void q_dequeue(Queue* q, QEltype* item){

// }

// /*Getter elemen head dari queue*/
// QEltype q_get_head(Queue q){

// }

// /*Getter elemen tail dari queue*/
// QEltype q_get_tail(Queue q){

// }