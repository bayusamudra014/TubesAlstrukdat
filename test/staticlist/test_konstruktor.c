#include <stdio.h>

#include "test.h"

START_TEST(tc_sl_konstruktor_1) {
  StaticList s;

  sl_create_list(&s);
  ck_assert_int_eq(s.length, 0);
  ck_assert(sl_is_empty(s));
}
END_TEST

TCase* test_sl_konstruktor() {
  TCase* tc = tcase_create("Tes Konstruktor Static List");

  tcase_add_test(tc, tc_sl_konstruktor_1);
  return tc;
}