#ifndef H_MATRIX
#define H_MATRIX

#define M_MAX_SIZE 30

#include "../lib.h"

typedef boolean MEltype;
typedef struct matrix {
  int rowEff;
  int colEff;
  MEltype buffer[M_MAX_SIZE][M_MAX_SIZE];
} Matrix;

void m_create_matrix(Matrix* m, int row, int cols);

#define m_elmt(M, i, j) (M).contents[(i)][(j)]

/* Mengembalikan jumlah baris matriks */
int m_rows_num(Matrix m);

/* Mengembalikan jumlah kolom matriks */
int m_cols_num(Matrix m);

#endif