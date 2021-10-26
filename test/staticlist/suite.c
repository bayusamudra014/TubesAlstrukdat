#include <check.h>

#include "test.h"

Suite* suite_static_list() {
  Suite* s = suite_create("Static List Suite");

  // Add All Test Case
  suite_add_tcase(s, test_sl_konstruktor());
  suite_add_tcase(s, test_sl_insert());
  suite_add_tcase(s, test_sl_delete());
  suite_add_tcase(s, test_sl_attribut());

  return s;
}