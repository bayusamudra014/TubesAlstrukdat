// #include <check.h>

// #include "../../src/matrix.h"
// #include "test.h"

// Matrix arrayToMatrix(int* matrix, int rows, int cols) {
//   Matrix r;
//   r.colEff = cols;
//   r.rowEff = rows;

//   for (int i = 0; i < rows; i++) {
//     for (int j = 0; j < cols; j++) {
//       r.contents[i][j] = *(matrix + i * cols + j);
//     }
//   }

//   return r;
// }

// void isEqualTC(Matrix a, Matrix b) {
//   if (ROWS(a) == ROWS(b) && COLS(a) == COLS(b)) {
//     for (int i = 0; i < ROWS(a); i++) {
//       for (int j = 0; j < COLS(a); j++) {
//         ck_assert_int_eq(a.contents[i][j], b.contents[i][j]);
//       }
//     }
//   } else {
//     ck_assert(0);
//   }
// }