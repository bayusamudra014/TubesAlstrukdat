#include <check.h>

void test_kesamaan(char* a, char* b, int length) {
  for (int i = 0; i < length; i++) {
    ck_assert_uint_eq((unsigned)a[i], (unsigned)b[i]);
  }
}