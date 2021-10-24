#include "wordmachine.h"

#include <stdlib.h>

static char* __wm_blank = " ";
static int __wm_blank_len = 1;
static boolean __wm_allocated = false;

Word wm_current_word;
boolean wm_end_word;

void __wm_copy_word();

/* Helper Function
   Memeriksa apakah sebuah karakter termasuk blank atau bukan
 */
boolean __wm_is_blank(char c) {
  boolean isBlank = false;
  int i = 0;

  while (!isBlank && i < __wm_blank_len) {
    isBlank = (c == __wm_blank[i]);
    i++;
  }

  return isBlank;
}

/* Helper Proceudre
   Melakukan dealokasi current word
*/
void __wm_free() {
  if (__wm_allocated) {
    free(wm_current_word.contents);
    wm_current_word.contents = NULL;
    wm_current_word.capacity = 0;
    wm_current_word.length = 0;

    __wm_allocated = false;
  }
}

/* Helper Procedure
   Memeriksa state dari wm_end_word.

   I.S. Sembarang
   F.S. wm_end_word akan disamakan dengan cm_eot. Bila keduanya
        bernilai true, Word didealokasi
*/
void __wm_set_status() {
  wm_end_word = cm_eot;

  if (wm_end_word) {
    __wm_free();
  }
}

/* Helper Proceudre
   Melakukan alokasi current word
*/
void __wm_allocate() {
  char* str = malloc(WM_INIT_CAPACITY * sizeof(char));

  if (str) {
    wm_current_word.contents = str;
    wm_current_word.capacity = WM_INIT_CAPACITY;
    __wm_allocated = true;
  } else {
    wm_current_word.contents = NULL;
    wm_current_word.capacity = 0;
  }

  wm_current_word.length = 0;
}

/* Helper Proceudre
   Melakukan realokasi current word sesuai dengan ukuran size.

   Bila ukuran baru lebih kecil daripada WM_INIT_CAPACITY, akan direalokasikan
   dengan ukuran WM_INIT_CAPACITY
*/
void __wm_reallocate(int size) {
  int newSize = size < WM_INIT_CAPACITY ? WM_INIT_CAPACITY : size;

  if (newSize != wm_current_word.capacity) {
    char* str = realloc(wm_current_word.contents, newSize * sizeof(char));

    if (str) {
      wm_current_word.contents = str;
      wm_current_word.capacity = newSize;
    }
  }
}

void wm_set_blank(char* blank, int length) {
  __wm_blank = blank;
  __wm_blank_len = length;
}

/* Mengabaikan satu atau beberapa BLANK

   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = salah satu mark */
void __wm_ignore_blank() {
  while (!cm_eot && __wm_is_blank(cm_current_char)) {
    cm_adv();
  }
}

void wm_start_word(void* stream) {
  cm_start(stream);
  wm_end_word = false;

  if (!__wm_allocated) {
    __wm_allocate();
  }

  wm_adv_word();
}

void wm_adv_word() {
  __wm_ignore_blank();
  __wm_set_status();
  __wm_copy_word();
}

/* Mengakuisisi kata, menyimpan dalam currentWord

   I.S. : currentChar adalah karakter pertama dari kata

   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong
*/
void __wm_copy_word() {
  wm_current_word.length = 0;

  while (!cm_eot && !__wm_is_blank(cm_current_char)) {
    if (wm_current_word.capacity * WM_SIZE_MAX_FACTOR <
        wm_current_word.length) {
      __wm_reallocate(wm_current_word.capacity * WM_SIZE_EXPAND);
    } else if (wm_current_word.capacity * WM_SIZE_MIN_FACTOR >
               wm_current_word.length) {
      __wm_reallocate(wm_current_word.capacity * WM_SIZE_SHRINK);
    }

    if (wm_current_word.length < wm_current_word.capacity) {
      wm_current_word.contents[wm_current_word.length] = cm_current_char;
      cm_adv();
      wm_current_word.length++;
    }
  }
}