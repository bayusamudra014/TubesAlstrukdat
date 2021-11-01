#include <check.h>

#include "test.h"


START_TEST(tc_td_konstruktor_1)
{
    ToDoList testList;

    td_create(&testList);

    ck_assert(FIRST(testList) == NULL);
}
END_TEST

TCase *test_td_constructor()
{
    TCase *tc = tcase_create("Tes Konstruktor");
    tcase_add_test(tc, tc_td_konstruktor_1);

    return tc;
}