/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

#include "pcolor.h"

#include <stdio.h>
#include <stdlib.h>

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

void set_color(Color color) {
  // Helper function
  printf("%s", color);
}

/* Prosedur ini akan mengatur warna text default saat print pada console.
   Untuk mengatur ke warna default, gunakan prosedur reset_color()

   Contoh pakai:
   set_text_color(TEXT_CYAN);
*/
void set_text_color(Color color) { set_color(color); }

/* Prosedur ini akan mengatur warna background text default saat print pada
 console. Untuk mengatur ke warna default, gunakan prosedur reset_color()

  Contoh pakai:
  set_bg_color(BG_GREEN);
*/
void set_bg_color(Color color) { set_color(color); }

/* Prosedur ini akan print text dengan warna pada console. Setelah prosedur
   ini dijalankan, warna console otomatis tereset.

  Contoh pakai:
  print_color(TEXT_BLUE, "Halo, Dunia");
*/
void print_color(Color color, char* string) {
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
void print_colored_char(Color color, char c) {
  set_text_color(color);
  printf("%c", c);
  reset_color();
}

/**
 * Membuat warna custom warna teks sesuai dengan warna rgb
 *
 * Contoh : create_text_color(102,255,121);
 */
Color create_text_color(unsigned char r, unsigned char g, unsigned char b) {
  char* result = malloc(sizeof(char) * 30);
  snprintf(result, 30, "\x1B[38;2;%u;%u;%um", r, g, b);

  return result;
}

/**
 * Membuat warna custom warna background teks sesuai dengan warna rgb
 *
 * Contoh : create_bg_color(102,255,121);
 */
Color create_bg_color(unsigned char r, unsigned char g, unsigned char b) {
  char* result = malloc(sizeof(char) * 30);
  snprintf(result, 30, "\x1B[48;2;%u;%u;%um", r, g, b);

  return result;
}

/*
  Buat warna teks dari kode heksadesimal

  Contoh : create_text_color_cd(0x6BAA75)
*/
Color create_text_color_cd(unsigned color) {
  unsigned char r, g, b;
  unsigned mask = (1 << 8) - 1;
  r = (color & mask << 16) >> 16;
  g = (color & mask << 8) >> 8;
  b = (color & mask);

  return create_text_color(r, g, b);
}

/*
  Buat warna background dari kode heksadesimal

  Contoh : create_bg_color_cd(0x6BAA75)
*/
Color create_bg_color_cd(unsigned color) {
  unsigned char r, g, b;
  unsigned mask = (1 << 8) - 1;
  r = (color & mask << 16) >> 16;
  g = (color & mask << 8) >> 8;
  b = (color & mask);

  return create_bg_color(r, g, b);
}