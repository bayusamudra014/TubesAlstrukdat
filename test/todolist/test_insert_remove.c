#include <check.h>

#include "test.h"

START_TEST(tc_td_insert_from_empty)
{
    ToDoList testList;
    Order o1;
    td_create(&testList);
    o1.orderID = 1;

    td_insertTask(&testList, o1);

    ck_assert_int_eq(td_getOrder(testList, 0).orderID, 1);
}
END_TEST

START_TEST(tc_td_insert)
{
    ToDoList testList;
    Order o1, o2;
    td_create(&testList);
    o1.orderID = 1;
    o2.orderID = 2;

    td_insertTask(&testList, o1);
    td_insertTask(&testList, o2);

    ck_assert_int_eq(td_getOrder(testList, 1).orderID, 2);
}
END_TEST

START_TEST(tc_td_remove)
{ 
    ToDoList testList;
    Order o1, o2, oVal;
    td_create(&testList);
    o1.orderID = 1;
    o2.orderID = 2;

    td_insertTask(&testList, o1);
    td_insertTask(&testList, o2);

    td_removeTask(&testList, &oVal, 2);

    ck_assert_int_eq(oVal.orderID, 2);
    ck_assert_int_eq(td_length(testList), 1);
}
END_TEST

START_TEST(tc_td_remove_into_empty)
{ 
    ToDoList testList;
    Order o1, oVal;
    td_create(&testList);
    o1.orderID = 1;

    td_insertTask(&testList, o1);

    td_removeTask(&testList, &oVal, 1);

    ck_assert_int_eq(oVal.orderID, 1);
    ck_assert_int_eq(td_length(testList), 0);
}
END_TEST

START_TEST(tc_td_remove_then_insert)
{ 
    ToDoList testList;
    Order o1, o2, o3, oVal;
    td_create(&testList);
    o1.orderID = 1;
    o2.orderID = 2;
    o3.orderID = 3;

    td_insertTask(&testList, o1);
    td_insertTask(&testList, o2);
    

    td_removeTask(&testList, &oVal, 2);

    td_insertTask(&testList, o3);
    ck_assert_int_eq(td_length(testList), 2);

    td_removeTask(&testList, &oVal, 3);
    ck_assert_int_eq(oVal.orderID, 3);
}
END_TEST

START_TEST(tc_td_remove_idx)
{ 
    ToDoList testList;
    Order o1, o2, o3, oVal;
    td_create(&testList);
    o1.orderID = 1;
    o2.orderID = 2;
    o3.orderID = 3;

    td_insertTask(&testList, o1);
    td_insertTask(&testList, o2);
    

    td_removeTaskByIdx(&testList, &oVal, 1);

    td_insertTask(&testList, o3);
    ck_assert_int_eq(td_length(testList), 2);

    td_removeTaskByIdx(&testList, &oVal, 0);
    ck_assert_int_eq(oVal.orderID, 1);
}
END_TEST

TCase *test_td_insert_remove()
{
    TCase *tc = tcase_create("Tes insert remove");
    tcase_add_test(tc, tc_td_insert_from_empty);
    tcase_add_test(tc, tc_td_insert);
    tcase_add_test(tc, tc_td_remove);
    tcase_add_test(tc, tc_td_remove_into_empty);
    tcase_add_test(tc, tc_td_remove_then_insert);
    tcase_add_test(tc, tc_td_remove_idx);

    return tc;
}