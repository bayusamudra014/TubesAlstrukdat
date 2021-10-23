#include "charmachine.h"

char cm_current_char;
boolean cm_eot;

static char* __cm_end_char;
static int __cm_end_char_ln = -1;
static boolean __cm_autoclose = false;
static FILE* __cm_tape;
static int __cm_retval;

/* Helper Function
    Memeriksa apakah sebuah karakter merupakan karakter EOP
*/
boolean __cm_isEndChar(char c) {
  boolean isEndChar = false;
  int i = 0;

  while (!isEndChar && i < __cm_end_char_ln) {
    isEndChar = (c == __cm_end_char[i]);
    i++;
  }

  return isEndChar;
}

void cm_start(FILE* stream) {
  __cm_tape = stream;
  cm_eot = false;
  cm_adv();
}

void cm_adv() {
  __cm_retval = fscanf(__cm_tape, "%c", &cm_current_char);
  cm_eot = __cm_isEndChar(cm_current_char) || __cm_retval == EOF;
  if (cm_eot && __cm_autoclose) {
    fclose(__cm_tape);
  }
}

void cm_set_end_char(char* endchar, int length) {
  __cm_end_char = endchar;
  __cm_end_char_ln = length;
}

void cm_set_autoclose(boolean autoclose) { __cm_autoclose = autoclose; }