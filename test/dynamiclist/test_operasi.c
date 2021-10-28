#include "test.h"

START_TEST(tc_dl_operasi_1){
    DynamicList D1;
    int dlSize = 2;
    dl_create_list(&D1, dlSize);

    Building B1;
    b_create_building(&B1, 7, 3, 'A');
    dl_insert_first(&D1, B1);

    ck_assert(b_is_equal(dl_elmt(D1, 0), B1));
    ck_assert_int_eq(dl_length(D1), 1);
    ck_assert_int_eq(dl_capacity(D1), dlSize);

    Building B2;
    b_create_building(&B2, 9, 11, 'B');
    dl_insert_first(&D1, B2);

    ck_assert(b_is_equal(dl_elmt(D1, 0), B2));
    ck_assert_int_eq(dl_length(D1), 2);
    ck_assert_int_eq(dl_capacity(D1), dlSize);

    Building B3;
    b_create_building(&B3, 9, 13, 'C');
    dl_insert_first(&D1, B3);

    ck_assert(b_is_equal(dl_elmt(D1, 0), B3));
    ck_assert_int_eq(dl_length(D1), 3);
    ck_assert_int_eq(dl_capacity(D1), dlSize + 1);

    dl_free_list(&D1);    
}END_TEST

START_TEST(tc_dl_operasi_2){
    DynamicList D1;
    int dlSize = 2;
    dl_create_list(&D1, dlSize);

    Building B1;
    b_create_building(&B1, 7, 3, 'A');
    dl_insert_last(&D1, B1);

    ck_assert(b_is_equal(dl_elmt(D1, dl_length(D1) - 1), B1));
    ck_assert_int_eq(dl_length(D1), 1);
    ck_assert_int_eq(dl_capacity(D1), dlSize);

    Building B2;
    b_create_building(&B2, 9, 11, 'B');
    dl_insert_last(&D1, B2);

    ck_assert(b_is_equal(dl_elmt(D1, dl_length(D1) - 1), B2));
    ck_assert_int_eq(dl_length(D1), 2);
    ck_assert_int_eq(dl_capacity(D1), dlSize);

    Building B3;
    b_create_building(&B3, 9, 13, 'C');
    dl_insert_last(&D1, B3);

    ck_assert(b_is_equal(dl_elmt(D1, dl_length(D1) - 1), B3));
    ck_assert_int_eq(dl_length(D1), 3);
    ck_assert_int_eq(dl_capacity(D1), dlSize + 1);

    dl_free_list(&D1);    
}END_TEST

START_TEST(tc_dl_operasi_3){
    DynamicList D1;
    int dlSize = 2;
    dl_create_list(&D1, dlSize);

    Building B1;
    b_create_building(&B1, 7, 3, 'A');
    dl_insert_first(&D1, B1);

    ck_assert_int_eq(dl_length(D1), 1);
    ck_assert_int_eq(dl_capacity(D1), dlSize);

    Building B2;
    b_create_building(&B2, 9, 11, 'B');
    dl_insert_last(&D1, B2);

    ck_assert_int_eq(dl_length(D1), 2);
    ck_assert_int_eq(dl_capacity(D1), dlSize);

    Building B3;
    b_create_building(&B3, 9, 13, 'C');
    dl_insert_last(&D1, B3);

    ck_assert_int_eq(dl_length(D1), 3);
    ck_assert_int_eq(dl_capacity(D1), dlSize + 1);

    Building B4;
    b_create_building(&B4, 9, 14, 'D');
    dl_insert_at(&D1, B4, 1);

    ck_assert_int_eq(dl_length(D1), 4);
    ck_assert_int_eq(dl_capacity(D1), dlSize + 2);


    ck_assert(b_is_equal(dl_elmt(D1, 0), B1));
    ck_assert(b_is_equal(dl_elmt(D1, 1), B4));
    ck_assert(b_is_equal(dl_elmt(D1, 2), B2));
    ck_assert(b_is_equal(dl_elmt(D1, 3), B3));

    dl_free_list(&D1);    
}END_TEST

START_TEST(tc_dl_operasi_4){
    DynamicList D1;
    int dlSize = 2;
    dl_create_list(&D1, dlSize);

    Building B1;
    b_create_building(&B1, 7, 3, 'A');
    dl_insert_first(&D1, B1);

    ck_assert(b_is_equal(dl_elmt(D1, 0), B1));
    ck_assert_int_eq(dl_length(D1), 1);
    ck_assert_int_eq(dl_capacity(D1), dlSize);

    Building B2;
    b_create_building(&B2, 7, 9, 'V');
    dl_insert_last(&D1, B2);

    ck_assert(b_is_equal(dl_elmt(D1, 1), B2));
    ck_assert_int_eq(dl_length(D1), 2);
    ck_assert_int_eq(dl_capacity(D1), dlSize);

    ck_assert(dl_is_full(D1));

    Building deletedBuilding1;
    dl_delete_first(&D1, &deletedBuilding1);

    ck_assert(!dl_is_full(D1));
    ck_assert(b_is_equal(deletedBuilding1, B1));
    ck_assert(b_is_equal(dl_elmt(D1, 0), B2));

    Building deletedBuilding2;
    dl_delete_first(&D1, &deletedBuilding2);

    ck_assert(dl_is_empty(D1));
    ck_assert(b_is_equal(deletedBuilding2, B2));

    dl_free_list(&D1);    
}END_TEST

TCase* test_dl_operasi() {
  TCase* tc = tcase_create("Test Konstruktor Dynamic List");

  tcase_add_test(tc, tc_dl_operasi_1);
  tcase_add_test(tc, tc_dl_operasi_2);
  tcase_add_test(tc, tc_dl_operasi_3);
  tcase_add_test(tc, tc_dl_operasi_4);

  return tc;
}