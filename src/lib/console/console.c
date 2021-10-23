#include "console.h"

#include <stdio.h>
#include <stdlib.h>

#include "../lib.h"

void clear_screen() {
  if (!system("@cls||clear")) {
    printf("\x1B[1J");
  }
}

void set_decorator(Decorator dec) { printf("%s", dec); }

void reset_decorator() { reset_color(); }

/* Menghilangkan sisa input sebelumnya */
void __c_flush_input() {
  cm_set_end_char("\n", 1);
  cm_start(stdin);

  while (!cm_eot) {
    cm_adv();
  }
}

void read_word(char* word, int length) {
  cm_set_end_char(CHAR_WHITESPACE, sizeof(CHAR_WHITESPACE) - 1);

  wm_start_word(stdin);
  if (cm_current_char != '\n') __c_flush_input();

  int i;
  for (i = 0; i < length - 1 && i < wm_current_word.length; i++) {
    word[i] = wm_current_word.contents[i];
  }

  word[i] = '\0';
}

void read_line(char* word, int length) {
  cm_set_end_char(CHAR_LINEBREAK, sizeof(CHAR_LINEBREAK) - 1);
  wm_set_blank("", 0);

  wm_start_word(stdin);

  int i;
  for (i = 0; i < length - 1 && i < wm_current_word.length; i++) {
    word[i] = wm_current_word.contents[i];
  }

  word[i] = '\0';
}