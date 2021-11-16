#include "charmachine.h"

char cm_current_char;
boolean cm_eot;

static char* __cm_end_char = "\n";
static int __cm_end_char_ln = 1;
static boolean __cm_autoclose = false;
static void* __cm_tape;
static int __cm_retval;
static char __cm_stream_source = SOURCE_FILE;

/* Helper Function
    Memeriksa apakah sebuah karakter merupakan karakter EOT
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

/* Helper Method
   Mengembalikan ke settingan default */
void __cm_set_default() {
  __cm_end_char_ln = -1;
  __cm_autoclose = false;
  __cm_tape = NULL;
  __cm_retval = -1;
  __cm_stream_source = SOURCE_FILE;
}

void cm_start(void* buffer) {
  __cm_tape = buffer;
  cm_eot = false;

  if (__cm_stream_source == SOURCE_STRING && __cm_end_char_ln < 1) {
    __cm_end_char = "";
    __cm_end_char_ln = 1;
  }

  cm_adv();
}

/* Melakukan adv pada file */
void __cm_adv_file() {
  __cm_retval = fscanf(__cm_tape, "%c", &cm_current_char);
  cm_eot = __cm_isEndChar(cm_current_char) || __cm_retval == EOF;
  if (cm_eot && __cm_autoclose) {
    fclose(__cm_tape);
  }
}

/* Melakukan adv pada string buffer. */
void __cm_adv_string() {
  char* karakter = (char*)__cm_tape;
  cm_current_char = *karakter;
  cm_eot = __cm_isEndChar(cm_current_char);

  if (!cm_eot) {
    karakter++;
  }

  __cm_tape = karakter;
}

void cm_adv() {
  if (!cm_eot) {
    if (!__cm_stream_source) {
      __cm_adv_file();
    } else {
      __cm_adv_string();
    }
  }

  if (cm_eot) {
    __cm_set_default();
  }
}

void cm_set_end_char(char* endchar, int length) {
  __cm_end_char = endchar;
  __cm_end_char_ln = length;
}

void cm_set_autoclose(boolean autoclose) { __cm_autoclose = autoclose; }

void cm_set_source(BufferSource src) { __cm_stream_source = src; }
