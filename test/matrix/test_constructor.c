// #include <check.h>
// #include <stdlib.h>

// #include "../../src/matrix.h"
// #include "test.h"

// void test() {
//   Matrix s;
//   int row = (rand() + 1.0) / RAND_MAX * 100;
//   int col = (rand() + 1.0) / RAND_MAX * 100;

//   CreateMatrix(row, col, &s);

//   ck_assert_int_eq(ROWS(s), row);
//   ck_assert_int_eq(COLS(s), col);
// }

// START_TEST(tc_konstruktor_1) { test(); }
// END_TEST

// START_TEST(tc_konstruktor_2) { test(); }
// END_TEST

// START_TEST(tc_konstruktor_3) { test(); }
// END_TEST

// TCase* test_constructor_matrix() {
//   TCase* tc = tcase_create("Tes Konstruktor");
//   tcase_add_test(tc, tc_konstruktor_1);
//   tcase_add_test(tc, tc_konstruktor_2);
//   tcase_add_test(tc, tc_konstruktor_3);

//   return tc;
// }