#include <check.h>

#include "test.h"

Suite* suite_dynamic_list() {
  Suite* s = suite_create("Dynamic List Suite");

  // Add All Test Case
  suite_add_tcase(s, test_dl_konstruktor());
  suite_add_tcase(s, test_dl_operasi());

  return s;
}