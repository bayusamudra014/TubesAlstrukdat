#include "test.h"

START_TEST(tc_p_konstruktor_1){
    Point P;
    int x = -1203;
    int y = 108326;
    p_create_point(&P, x, y);

    // Seharusnya sama
    ck_assert_int_eq(p_getX(P), x);
    ck_assert_int_eq(p_getY(P), y);
}END_TEST

TCase* test_p_konstruktor() {
  TCase* tc = tcase_create("Test Konstruktor Point");

  tcase_add_test(tc, tc_p_konstruktor_1);

  return tc;
}