#include <check.h>

#include "test.h"

Suite* suite_td() {
  Suite* s = suite_create("To Do List Suite");

  // Add All Test Case
  suite_add_tcase(s, test_td_constructor());
  suite_add_tcase(s, test_td_insert_remove());
  
  return s;
}