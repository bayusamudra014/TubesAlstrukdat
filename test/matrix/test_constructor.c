#include <check.h>

#include "test.h"

START_TEST(tc_m_konstruktor_1)
{
    Matrix m;

    m_create_matrix(&m, 30, 30);

    ck_assert_int_eq(m_rows_num(m), 30);
    ck_assert_int_eq(m_cols_num(m), 30);
}
END_TEST

START_TEST(tc_m_konstruktor_2)
{
    Matrix m;

    m_create_matrix(&m, 20, 15);

    ck_assert_int_eq(m_rows_num(m), 20);
    ck_assert_int_eq(m_cols_num(m), 15);
}
END_TEST

START_TEST(tc_m_konstruktor_3)
{
    Matrix m;

    m_create_matrix(&m, 25, 25);

    ck_assert_int_eq(m_rows_num(m), 25);
    ck_assert_int_eq(m_cols_num(m), 25);
}
END_TEST

TCase *test_m_constructor()
{
    TCase *tc = tcase_create("Tes Konstruktor");
    tcase_add_test(tc, tc_m_konstruktor_1);
    tcase_add_test(tc, tc_m_konstruktor_2);
    tcase_add_test(tc, tc_m_konstruktor_3);

    return tc;
}