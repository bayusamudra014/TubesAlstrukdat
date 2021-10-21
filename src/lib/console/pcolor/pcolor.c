/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

#include "pcolor.h"

#include <stdio.h>

void print_red(char c) {
  printf("%s%c", TEXT_RED, c);
  printf("%s", TEXT_NORMAL);
}

void print_green(char c) {
  printf("%s%c", TEXT_GREEN, c);
  printf("%s", TEXT_NORMAL);
}

void print_yellow(char c) {
  printf("%s%c", TEXT_YELLOW, c);
  printf("%s", TEXT_NORMAL);
}

void print_blue(char c) {
  printf("%s%c", TEXT_BLUE, c);
  printf("%s", TEXT_NORMAL);
}

void print_magenta(char c) {
  printf("%s%c", TEXT_MAGENTA, c);
  printf("%s", TEXT_NORMAL);
}

void print_cyan(char c) {
  printf("%s%c", TEXT_CYAN, c);
  printf("%s", TEXT_NORMAL);
}

void set_color(char* color) {
  // Helper function
  printf("%s", color);
}

/* Prosedur ini akan mengatur warna text default saat print pada console.
   Untuk mengatur ke warna default, gunakan prosedur reset_color()

   Contoh pakai:
   set_text_color(TEXT_CYAN);
*/
void set_text_color(char* color) { set_color(color); }

/* Prosedur ini akan mengatur warna background text default saat print pada
 console. Untuk mengatur ke warna default, gunakan prosedur reset_color()

  Contoh pakai:
  set_bg_color(BG_GREEN);
*/
void set_bg_color(char* color) { set_color(color); }

/* Prosedur ini akan print text dengan warna pada console. Setelah prosedur
   ini dijalankan, warna console otomatis tereset.

  Contoh pakai:
  print_color(TEXT_BLUE, "Halo, Dunia");
*/
void print_color(char* color, char* string) {
  set_text_color(color);
  printf("%s", string);
  reset_color();
}

/* Mengembalikan ke warna default */
void reset_color() { printf("%s", _RESET_COLOR); }

/* Prosedur ini akan mencetak karakter berwarna

  Contoh pakai:
  print_colored_char(TEXT_BLUE, 'H');
*/
void print_colored_char(char* color, char c) {
  set_text_color(color);
  printf("%c", c);
  reset_color();
}
