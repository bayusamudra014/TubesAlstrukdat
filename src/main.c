#include <stdio.h>

#include "lib/lib.h"

int main() {
  // clear_screen();
  char str[20];

  read_line(str, 20);
  printf("Yang dibaca line: %s\n", str);

  read_word(str, 20);
  printf("Yang dibaca word: %s\n", str);

  read_line(str, 20);
  printf("Yang dibaca line: %s\n", str);

  return 0;
}
