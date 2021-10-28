#include "test.h"

START_TEST(tc_p_equality_1){
    Point P1, P2;
    p_create_point(&P1, 10, 20);
    p_create_point(&P2, 10, 20);
    ck_assert(p_is_equal(P1, P2));
}END_TEST

START_TEST(tc_p_equality_2){
    Point P1, P2;
    int x = 10;
    int y = 10;
    p_create_point(&P1, x, y);
    p_create_point(&P2, y, x);
    ck_assert(p_is_equal(P1, P2));
}END_TEST

START_TEST(tc_p_equality_3){
    Point P1, P2;
    int x = 10;
    int y = 30;
    p_create_point(&P1, x, y);
    p_create_point(&P2, y, x);
    ck_assert(!p_is_equal(P1, P2));
}END_TEST

TCase* test_p_equality() {
  TCase* tc = tcase_create("Test Equality Point");

  tcase_add_test(tc, tc_p_equality_1);
  tcase_add_test(tc, tc_p_equality_2);
  tcase_add_test(tc, tc_p_equality_3);

  return tc;
}