#include <check.h>

#include "test.h"

Suite* suite_char_machine() {
  Suite* s = suite_create("Char Machine Suite");

  // Add All Test Case
  suite_add_tcase(s, test_cm_file());

  return s;
}