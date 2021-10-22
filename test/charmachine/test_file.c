#include <stdio.h>

#include "test.h"

START_TEST(tc_cm_file_1) {
  // Setting endchar
  FILE* f;

  f = tmpfile();

  if (f) {
    char str[] = "HALO DUNIA APA KABAR.";
    fputs(str, f);

    rewind(f);

    cm_set_end_char(".", 1);
    cm_start(f);

    int i = 0;
    char hasil[20];

    while (!cm_eot) {
      hasil[i] = cm_current_char;
      cm_adv();
      i++;
    }

    hasil[i] = '\0';
    ck_assert_str_eq("HALO DUNIA APA KABAR", hasil);

    ck_assert_int_eq(i, 20);

  } else {
    ck_abort_msg("Gagal membuat file");
  }
}
END_TEST

START_TEST(tc_cm_file_2) {
  // Setting endchar
  FILE* f;

  f = tmpfile();

  if (f) {
    char str[] = "HALO DUNIA, APA KABAR.";
    fputs(str, f);

    rewind(f);

    cm_set_end_char(".,", 2);
    cm_start(f);

    int i = 0;
    char hasil[20];

    while (!cm_eot) {
      hasil[i] = cm_current_char;
      cm_adv();
      i++;
    }

    hasil[i] = '\0';
    ck_assert_str_eq(hasil, "HALO DUNIA");

    ck_assert_int_eq(i, 10);

  } else {
    ck_abort_msg("Gagal membuat file");
  }
}
END_TEST

START_TEST(tc_cm_file_3) {
  // Setting endchar
  FILE* f;

  f = tmpfile();

  if (f) {
    char str[] = "HALO DUNIA APA KABARNYA HEHE";
    fputs(str, f);

    rewind(f);

    cm_set_end_char(".,", 2);
    cm_start(f);

    int i = 0;
    char hasil[20];

    while (!cm_eot) {
      hasil[i] = cm_current_char;
      cm_adv();
      i++;
    }

    hasil[i] = '\0';
    ck_assert_str_eq(hasil, "HALO DUNIA APA KABARNYA HEHE");
  } else {
    ck_abort_msg("Gagal membuat file");
  }
}
END_TEST

TCase* test_cm_file() {
  TCase* tc = tcase_create("Test Char Machine for STDIN");

  tcase_add_test(tc, tc_cm_file_1);
  tcase_add_test(tc, tc_cm_file_2);
  tcase_add_test(tc, tc_cm_file_3);

  return tc;
}