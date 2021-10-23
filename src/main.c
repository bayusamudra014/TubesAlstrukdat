#include <stdio.h>

#include "lib/lib.h"

int main() {
  clear_screen();

  FILE* f;

  f = tmpfile();

  if (f) {
    char str[] = "HALO       DUNIA APA     KABAR    ";
    fputs(str, f);

    rewind(f);

    // fflush(f);

    cm_set_end_char(".", 1);
    wm_start_word(f);

    int i = 0;
    char ans[][10] = {"HALO", "DUNIA", "APA", "KABAR"};

    while (!wm_end_word) {
      wm_current_word.contents[wm_current_word.length] = '\0';

      wm_adv_word();
      i++;
    }

  } else {
    printf("Gagal membuat file");
  }

  return 0;
}
