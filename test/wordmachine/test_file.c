#include <stdio.h>

#include "test.h"

START_TEST(tc_wm_file_1) {
  // Setting endchar
  FILE* f;

  f = tmpfile();

  if (f) {
    char str[] = "HALO       DUNIA APA     KABAR    .";
    fputs(str, f);

    rewind(f);

    cm_set_end_char(".", 1);
    wm_start_word(f);

    ck_assert_int_eq(wm_current_word.capacity, 50);

    int i = 0;
    char ans[][10] = {"HALO", "DUNIA", "APA", "KABAR"};

    while (!wm_end_word) {
      wm_current_word.contents[wm_current_word.length] = '\0';
      ck_assert_str_eq(wm_current_word.contents, ans[i]);

      wm_adv_word();
      i++;
    }

    ck_assert(wm_end_word);
    ck_assert_int_eq(wm_current_word.capacity, 0);
  } else {
    ck_abort_msg("Gagal membuat file");
  }
}
END_TEST

START_TEST(tc_wm_file_2) {
  // Long Test
  FILE* f;

  f = tmpfile();

  if (f) {
    char str[] =
        "  123 561192490958435429085611924909584354290856119249095843542908 "
        "5611924909584354290856119249095843542908561192490958435429085611924909"
        "58435429085611924909584354290856119249095843542908 "
        "56119249095843542908.";
    fputs(str, f);

    rewind(f);

    cm_set_end_char(".", 1);
    wm_start_word(f);

    ck_assert_int_eq(wm_current_word.capacity, 50);

    int i = 0;
    char ans[][200] = {
        "123", "561192490958435429085611924909584354290856119249095843542908",
        "5611924909584354290856119249095843542908561192490958435429085611924909"
        "58435429085611924909584354290856119249095843542908",
        "56119249095843542908"};

    int resize1 = WM_INIT_CAPACITY * WM_SIZE_EXPAND;
    int resize2 = resize1 * WM_SIZE_EXPAND;

    int cpTest[] = {WM_INIT_CAPACITY, resize1, resize2, WM_INIT_CAPACITY};

    while (!wm_end_word) {
      wm_current_word.contents[wm_current_word.length] = '\0';
      ck_assert_str_eq(wm_current_word.contents, ans[i]);

      ck_assert_int_eq(wm_current_word.capacity, cpTest[i]);

      wm_adv_word();

      i++;
    }

    ck_assert(wm_end_word);
    ck_assert_int_eq(wm_current_word.capacity, 0);
  } else {
    ck_abort_msg("Gagal membuat file");
  }
}
END_TEST

START_TEST(tc_wm_file_3) {
  // Long Test
  FILE* f;

  f = tmpfile();

  if (f) {
    char str[] = "   HALO,,,   HALOBANDUNG,, ,,,, IBUKOTA    PERHIANGAN      .";
    fputs(str, f);

    rewind(f);

    cm_set_end_char(".", 1);
    wm_set_blank(" ,", 2);
    wm_start_word(f);

    ck_assert_int_eq(wm_current_word.capacity, 50);

    int i = 0;
    char ans[][20] = {"HALO", "HALOBANDUNG", "IBUKOTA", "PERHIANGAN"};

    while (!wm_end_word) {
      wm_current_word.contents[wm_current_word.length] = '\0';
      ck_assert_str_eq(wm_current_word.contents, ans[i]);

      wm_adv_word();

      i++;
    }

    ck_assert(wm_end_word);
    ck_assert_int_eq(wm_current_word.capacity, 0);
  } else {
    ck_abort_msg("Gagal membuat file");
  }
}
END_TEST

START_TEST(tc_wm_file_4) {
  // Setting endchar
  FILE* f;

  f = tmpfile();

  if (f) {
    char str[] = "HALO       DUNIA APA     KABAR    ";
    fputs(str, f);

    rewind(f);

    // fflush(f);

    cm_set_end_char(".", 1);
    wm_start_word(f);

    ck_assert_int_eq(wm_current_word.capacity, 50);

    int i = 0;
    char ans[][10] = {"HALO", "DUNIA", "APA", "KABAR"};

    while (!wm_end_word) {
      wm_current_word.contents[wm_current_word.length] = '\0';
      ck_assert_str_eq(wm_current_word.contents, ans[i]);

      wm_adv_word();
      i++;
    }

    ck_assert(wm_end_word);
    ck_assert_int_eq(wm_current_word.capacity, 0);
  } else {
    ck_abort_msg("Gagal membuat file");
  }
}
END_TEST

START_TEST(tc_wm_file_5) {
  // Setting endchar
  FILE* f;

  f = tmpfile();

  if (f) {
    cm_set_end_char(".", 1);
    wm_start_word(f);

    ck_assert(wm_end_word);
    ck_assert_int_eq(wm_current_word.capacity, 0);
  } else {
    ck_abort_msg("Gagal membuat file");
  }
}
END_TEST

START_TEST(tc_wm_file_6) {
  // Setting endchar
  FILE* f;

  f = tmpfile();

  if (f) {
    char str[] = "     .          ";
    fputs(str, f);

    rewind(f);

    cm_set_end_char(".", 1);
    wm_start_word(f);

    ck_assert(wm_end_word);
    ck_assert_int_eq(wm_current_word.capacity, 0);
  } else {
    ck_abort_msg("Gagal membuat file");
  }
}
END_TEST

START_TEST(tc_wm_file_7) {
  // Setting endchar
  FILE* f;

  f = tmpfile();

  if (f) {
    char str[] = "HALO.";
    fputs(str, f);

    rewind(f);

    cm_set_end_char(".", 1);
    wm_start_word(f);

    ck_assert_int_eq(wm_current_word.capacity, 50);

    int i = 0;
    char ans[][10] = {"HALO"};

    while (!wm_end_word) {
      wm_current_word.contents[wm_current_word.length] = '\0';
      ck_assert_str_eq(wm_current_word.contents, ans[i]);

      wm_adv_word();
      i++;
    }

    ck_assert(wm_end_word);
    ck_assert_int_eq(wm_current_word.capacity, 0);
  } else {
    ck_abort_msg("Gagal membuat file");
  }
}
END_TEST

TCase* test_wm_file() {
  TCase* tc = tcase_create("Word Machine Test for File");

  tcase_add_test(tc, tc_wm_file_1);
  tcase_add_test(tc, tc_wm_file_2);
  tcase_add_test(tc, tc_wm_file_3);
  tcase_add_test(tc, tc_wm_file_4);
  tcase_add_test(tc, tc_wm_file_5);
  tcase_add_test(tc, tc_wm_file_6);
  tcase_add_test(tc, tc_wm_file_7);

  return tc;
}