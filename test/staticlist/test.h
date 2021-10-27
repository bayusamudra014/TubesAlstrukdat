#include <check.h>

#include "../../src/lib/lib.h"

#ifndef H_STATIC_LIST_TEST
#define H_STATIC_LIST_TEST

TCase* test_sl_konstruktor();
TCase* test_sl_insert();
TCase* test_sl_delete();
TCase* test_sl_attribut();

Suite* suite_static_list();

void test_kesamaan(char* a, char* b, int length);

#endif