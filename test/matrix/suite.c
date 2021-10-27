#include <check.h>

#include "test.h"

Suite* suite_matrix() {
  Suite* s = suite_create("Matrix Suite");

  // Add All Test Case
  suite_add_tcase(s, test_m_selector());
  suite_add_tcase(s, test_m_constructor());
  return s;
}