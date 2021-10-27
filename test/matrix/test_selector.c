#include <check.h>

#include "test.h"

START_TEST(tc_m_selektor_1)
{
    Matrix m;

    m_create_matrix(&m, 30, 30);

    for (int i = 0; i < m_rows_num(m); i++)
    {
        for (int j = 0; i < m_cols_num(m); j++)
        {
            if (i == j)
            {
                m_elmt(m, i, j) = 1;
            }
            else
            {
                m_elmt(m, i, j) = 0;
            }
        }
    }

    ck_assert_int_eq(m_elmt(m, 18, 18), 1);
    ck_assert_int_eq(m_elmt(m, 16, 14), 0);
}
END_TEST

TCase *test_m_selector()
{
    TCase *tc = tcase_create("Tes Selector");
    tcase_add_test(tc, tc_m_selektor_1);
   

    return tc;
}