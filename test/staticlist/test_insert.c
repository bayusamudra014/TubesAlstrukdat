#include <stdio.h>

#include "test.h"

START_TEST(tc_sl_insertf_1) {
  StaticList s;

  sl_create_list(&s);
  for (int i = 0; i < 5; i++) {
    sl_insert_first(&s, i);
  }

  char ans[] = {4, 3, 2, 1, 0};
  ck_assert_mem_eq(s.buffer, ans, 5);
  ck_assert_int_eq(sl_length(s), 5);
}
END_TEST

START_TEST(tc_sl_insertf_2) {
  StaticList s;

  sl_create_list(&s);
  for (int i = 0; i < 3; i++) {
    sl_insert_first(&s, i);
  }

  char ans[] = {2, 1, 0};
  ck_assert_mem_eq(s.buffer, ans, 3);
  ck_assert_int_eq(sl_length(s), 3);
}
END_TEST

START_TEST(tc_sl_insertf_3) {
  StaticList s;

  sl_create_list(&s);
  for (int i = 0; i < 5; i++) {
    sl_insert_last(&s, i + 1);
  }

  char ans[] = {1, 2, 3, 4, 5};
  ck_assert_mem_eq(s.buffer, ans, 5);
  ck_assert_int_eq(sl_length(s), 5);
}
END_TEST

START_TEST(tc_sl_insertf_4) {
  StaticList s;

  sl_create_list(&s);
  for (int i = 0; i < 3; i++) {
    sl_insert_last(&s, i + 1);
  }

  sl_insert_at(&s, 10, 2);
  sl_insert_at(&s, 20, 1);

  char ans[] = {1, 20, 2, 10, 3};
  ck_assert_mem_eq(s.buffer, ans, 5);
  ck_assert_int_eq(sl_length(s), 5);
}
END_TEST

TCase* test_sl_insert() {
  TCase* tc = tcase_create("Tes Insert Static List");

  tcase_add_test(tc, tc_sl_insertf_1);
  tcase_add_test(tc, tc_sl_insertf_2);
  tcase_add_test(tc, tc_sl_insertf_3);
  tcase_add_test(tc, tc_sl_insertf_4);
  return tc;
}