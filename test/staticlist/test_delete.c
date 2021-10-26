#include <stdio.h>

#include "test.h"

START_TEST(tc_sl_delete_1) {
  StaticList s;

  sl_create_list(&s);

  for (int i = 0; i < 5; i++) {
    sl_insert_last(&s, i + 1);
  }

  char ans[] = {1, 2, 3, 4, 5};
  ck_assert_mem_eq(s.buffer, ans, 5);
  ck_assert_int_eq(sl_length(s), 5);

  sl_delete_first(&s, NULL);
  ck_assert_mem_eq(s.buffer, ans + 1, 4);
  ck_assert_int_eq(sl_length(s), 4);

  char val;
  sl_delete_first(&s, &val);
  ck_assert_mem_eq(s.buffer, ans + 2, 3);
  ck_assert_int_eq(sl_length(s), 3);
  ck_assert_int_eq(val, 2);

  sl_delete_first(&s, &val);
  ck_assert_mem_eq(s.buffer, ans + 3, 2);
  ck_assert_int_eq(sl_length(s), 2);
  ck_assert_int_eq(val, 3);

  sl_delete_first(&s, &val);
  ck_assert_mem_eq(s.buffer, ans + 4, 1);
  ck_assert_int_eq(sl_length(s), 1);
  ck_assert_int_eq(val, 4);

  sl_delete_first(&s, NULL);
  ck_assert_int_eq(s.length, 0);
  ck_assert(sl_is_empty(s));
}
END_TEST

START_TEST(tc_sl_delete_2) {
  StaticList s;

  sl_create_list(&s);

  for (int i = 0; i < 5; i++) {
    sl_insert_last(&s, i + 1);
  }

  char ans[] = {1, 2, 3, 4, 5};
  ck_assert_mem_eq(s.buffer, ans, 5);
  ck_assert_int_eq(sl_length(s), 5);

  sl_delete_last(&s, NULL);
  ck_assert_mem_eq(s.buffer, ans, 4);
  ck_assert_int_eq(sl_length(s), 4);

  char val;
  sl_delete_last(&s, &val);
  ck_assert_mem_eq(s.buffer, ans, 3);
  ck_assert_int_eq(sl_length(s), 3);
  ck_assert_int_eq(val, 4);

  sl_delete_last(&s, &val);
  ck_assert_mem_eq(s.buffer, ans, 2);
  ck_assert_int_eq(sl_length(s), 2);
  ck_assert_int_eq(val, 3);

  sl_delete_last(&s, &val);
  ck_assert_mem_eq(s.buffer, ans, 1);
  ck_assert_int_eq(sl_length(s), 1);
  ck_assert_int_eq(val, 2);

  sl_delete_last(&s, NULL);
  ck_assert_int_eq(s.length, 0);
  ck_assert(sl_is_empty(s));
}
END_TEST

START_TEST(tc_sl_delete_3) {
  StaticList s;

  sl_create_list(&s);

  for (int i = 0; i < 5; i++) {
    sl_insert_last(&s, i + 1);
  }

  sl_delete_at(&s, NULL, 2);
  char ans1[] = {1, 2, 4, 5};
  ck_assert_mem_eq(s.buffer, ans1, 4);
  ck_assert_int_eq(sl_length(s), 4);

  char val;
  sl_delete_at(&s, &val, 1);
  char ans2[] = {1, 4, 5};
  ck_assert_mem_eq(s.buffer, ans2, 3);
  ck_assert_int_eq(sl_length(s), 3);
  ck_assert_int_eq(val, 2);
}
END_TEST

TCase* test_sl_delete() {
  TCase* tc = tcase_create("Tes Delete Static List");

  tcase_add_test(tc, tc_sl_delete_1);
  tcase_add_test(tc, tc_sl_delete_2);
  tcase_add_test(tc, tc_sl_delete_3);

  return tc;
}