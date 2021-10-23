#include <check.h>

#include "test.h"

Suite* suite_word_machine() {
  Suite* s = suite_create("Word Machine Suite");

  // Add All Test Case
  suite_add_tcase(s, test_wm_file());

  return s;
}