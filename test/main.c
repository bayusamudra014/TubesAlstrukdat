#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "charmachine/test.h"
#include "wordmachine/test.h"

int main() {
  int no_failed = 0;

  Suite* s0 = suite_char_machine();
  SRunner* run = srunner_create(s0);

  srunner_add_suite(run, suite_word_machine());

  srunner_run_all(run, CK_NORMAL);
  no_failed = srunner_ntests_failed(run);
  srunner_free(run);

  return no_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
