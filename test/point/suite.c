#include <check.h>

#include "test.h"

Suite* suite_point() {
  Suite* s = suite_create("Point Suite");

  // Add All Test Case
  suite_add_tcase(s, test_p_konstruktor());
  suite_add_tcase(s, test_p_equality());

  return s;
}