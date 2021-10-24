#include <check.h>

#include "../../src/lib/lib.h"

#ifndef H_CHAR_MACHINE_TEST
#define H_CHAR_MACHINE_TEST

TCase* test_cm_file();
TCase* test_cm_buffer();

Suite* suite_char_machine();

#endif