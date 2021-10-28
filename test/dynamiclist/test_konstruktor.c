#include "test.h"

START_TEST(tc_dl_konstruktor_1){
    DynamicList D1;
    int dlSize = 20;
    dl_create_list(&D1, dlSize);

    ck_assert_int_eq(dl_length(D1), 0);
    ck_assert_int_eq(dl_capacity(D1), dlSize);

    dl_free_list(&D1);    
}END_TEST

START_TEST(tc_dl_konstruktor_2){
    DynamicList D1;
    int dlSizeOld = 20;
    dl_create_list(&D1, dlSizeOld);

    ck_assert_int_eq(dl_length(D1), 0);
    ck_assert_int_eq(dl_capacity(D1), dlSizeOld);

    int dlSizeAdd = 7;

    dl_resize_list(&D1, dlSizeAdd);

    ck_assert_int_eq(dl_length(D1), 0);
    ck_assert_int_eq(dl_capacity(D1), dlSizeOld + dlSizeAdd);

    dl_free_list(&D1);
}END_TEST

TCase* test_dl_konstruktor() {
  TCase* tc = tcase_create("Test Konstruktor Dynamic List");

  tcase_add_test(tc, tc_dl_konstruktor_1);
  tcase_add_test(tc, tc_dl_konstruktor_2);

  return tc;
}