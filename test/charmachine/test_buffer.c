#include <stdio.h>

#include "test.h"

START_TEST(tc_cm_buffer_1) {
  char* buffer = "HALO DUNIA APA KABARNYA.";
  cm_set_end_char(".", 1);
  cm_set_source(SOURCE_STRING);

  cm_start(buffer);

  char hasil[30];
  int i = 0;

  while (!cm_eot) {
    hasil[i] = cm_current_char;
    cm_adv();

    i++;
  }

  ck_assert_str_eq(hasil, "HALO DUNIA APA KABARNYA");
  ck_assert(cm_eot);
}
END_TEST

START_TEST(tc_cm_buffer_2) {
  char* buffer = "HALO DUNIA APA KABARNYA.";
  cm_set_source(SOURCE_STRING);

  cm_start(buffer);

  char hasil[30];
  int i = 0;

  while (!cm_eot) {
    hasil[i] = cm_current_char;
    cm_adv();

    i++;
  }

  hasil[i] = '\x0';

  ck_assert_str_eq(hasil, "HALO DUNIA APA KABARNYA.");
  ck_assert(cm_eot);
}
END_TEST

START_TEST(tc_cm_buffer_3) {
  char* buffer = "";
  cm_set_source(SOURCE_STRING);

  cm_start(buffer);

  char hasil[30];
  int i = 0;

  while (!cm_eot) {
    hasil[i] = cm_current_char;
    cm_adv();

    i++;
  }

  hasil[i] = '\x0';

  ck_assert_str_eq(hasil, "");
  ck_assert(cm_eot);
}
END_TEST

TCase* test_cm_buffer() {
  TCase* tc = tcase_create("Test Char Machine for buffer source");

  tcase_add_test(tc, tc_cm_buffer_1);
  tcase_add_test(tc, tc_cm_buffer_2);
  tcase_add_test(tc, tc_cm_buffer_3);

  return tc;
}