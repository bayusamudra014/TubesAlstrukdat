#include "file.h"

#include <stdio.h>
#include <stdlib.h>

#include "../wordmachine/wordmachine.h"

void f_read_file(const char* path, char* buffer, int size) {
  FILE* fp;
  fp = fopen(path, "r");

  buffer[size];
  int i = 0;
  wm_start_word(fp);
  while (!wm_end_word) {
    buffer[i] = wm_current_word.contents;
    i += 1;
    wm_adv_word();
  }
  fclose(fp);
}

int f_len_file(const char* path) {
  FILE* fp;
  fp = fopen(path, "r");
  int len = 0;
  wm_start_word(fp);
  while (!wm_end_word) {
    len += 1;
    wm_adv_word();
  }
  fclose(fp);
  return len;
}

char* __mm_copyWord(Word str) {
  char* res = (char*)malloc(sizeof(char) * (str.length + 1));
  int i;
  for (i = 0; i < str.length; i++) {
    res[i] = str.contents[i];
  }
  res[i] = '\0';
  return res;
}

char** f_read_file_to_buffer(const char* path) {
  // Buka file dengan mode read
  FILE* fp;
  fp = fopen(path, "r");

  // Inisialisasi Array of pointers
  // buffer akan menyimpan pointer ke strings
  char** buffer = (char**)malloc(f_len_file(path) * sizeof(char*));

  int i = 0;
  wm_start_word(fp);
  while (!wm_end_word) {
    // buffer[i] berisi pointer ke array
    // yang isinya wm_current_word.contents
    buffer[i] = __mm_copyWord(wm_current_word);
    i += 1;
    wm_adv_word();
  }
  fclose(fp);

  // Hasilnya adalah array per line
  return buffer;
}

void f_write_file(const char* path, const char* buffer, int size) {
  buffer[size];
  FILE* fp;
  fp = fopen(path, "w");
  fputs(buffer, fp);
  fclose(fp);
}

boolean f_exist(const char* path) {
  FILE* fp;
  fp = fopen(path, "r");
  if(fp){
      fclose(fp);
      return true;
  } else {
      return false;
  }
}
