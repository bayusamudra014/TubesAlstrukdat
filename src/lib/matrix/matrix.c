#include "matrix.h"

/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori 
   I.S. row dan cols adalah valid untuk memori matriks yang dibuat 
   F.S. Matriks m sesuai dengan definisi di atas terbentuk */
void m_create_matrix(Matrix *m, int row, int cols)
{
  /* Kamus Lokal */
  /* Algoritma Lokal */
  m->rowEff = row;
  m->colEff = cols;
}

/* Mengembalikan jumlah baris matriks */
int m_rows_num(Matrix m)
{
  return m.rowEff;
}
/* Mengembalikan jumlah kolom matriks */
int m_cols_num(Matrix m)
{
  return m.colEff;
}