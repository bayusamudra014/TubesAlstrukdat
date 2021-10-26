#include <stdio.h>

#include "test.h"

START_TEST(tc_sl_attribut_1) {
  StaticList s;

  sl_create_list(&s);
  for (int i = 0; i < SL_CAPACITY; i++) {
    sl_insert_last(&s, i);
  }

  ck_assert(sl_is_full(s));
  ck_assert(!sl_is_empty(s));
  ck_assert_int_eq(sl_length(s), SL_CAPACITY);
}
END_TEST

START_TEST(tc_sl_attribut_2) {
  StaticList s;

  sl_create_list(&s);

  ck_assert(!sl_is_full(s));
  ck_assert(sl_is_empty(s));
  ck_assert_int_eq(sl_length(s), 0);
}
END_TEST

START_TEST(tc_sl_attribut_3) {
  StaticList s;

  sl_create_list(&s);
  for (int i = 0; i < 3; i++) {
    sl_insert_last(&s, i);
  }

  ck_assert(!sl_is_full(s));
  ck_assert(!sl_is_empty(s));
  ck_assert_int_eq(sl_length(s), 3);
}
END_TEST

TCase* test_sl_attribut() {
  TCase* tc = tcase_create("Tes Attribut Static List");

  tcase_add_test(tc, tc_sl_attribut_1);
  tcase_add_test(tc, tc_sl_attribut_2);
  tcase_add_test(tc, tc_sl_attribut_3);

  return tc;
}