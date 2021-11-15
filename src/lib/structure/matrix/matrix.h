#ifndef H_MATRIX
#define H_MATRIX

#define M_MAX_SIZE 30

#include "../structure.h"

typedef int MEltype;
typedef struct matrix {
  int rowEff;
  int colEff;
  MEltype buffer[M_MAX_SIZE][M_MAX_SIZE];
} Matrix;

/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di
   "ujung kiri" memori I.S. row dan cols adalah valid untuk memori matriks yang
   dibuat F.S. Matriks m sesuai dengan definisi di atas terbentuk */
void m_create_matrix(Matrix* m, int row, int cols);

/* Selektor untuk mengakses element matriks pada baris i dan kolom j */
#define m_elmt(M, i, j) (M).buffer[(i)][(j)]

/* Mengembalikan jumlah baris matriks */
int m_rows_num(Matrix m);

/* Mengembalikan jumlah kolom matriks */
int m_cols_num(Matrix m);

#endif