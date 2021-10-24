/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Edited by: Bayu Samudra
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

void set_color(Color color) { printf("%s", color); }

void set_text_color(Color color) { set_color(color); }

void set_bg_color(Color color) { set_color(color); }

void print_color(Color color, const char* string) {
  set_text_color(color);
  printf("%s", string);
  reset_color();
}

void reset_color() { printf("%s", __RESET_COLOR); }

void print_colored_char(Color color, char c) {
  set_text_color(color);
  printf("%c", c);
  reset_color();
}

Color create_text_color(unsigned char r, unsigned char g, unsigned char b) {
  char* result = malloc(sizeof(char) * 30);
  snprintf(result, 30, "\x1B[38;2;%u;%u;%um", r, g, b);

  return result;
}

Color create_bg_color(unsigned char r, unsigned char g, unsigned char b) {
  char* result = malloc(sizeof(char) * 30);
  snprintf(result, 30, "\x1B[48;2;%u;%u;%um", r, g, b);

  return result;
}

Color create_text_color_cd(unsigned color) {
  unsigned char r, g, b;
  unsigned mask = (1 << 8) - 1;
  r = (color & mask << 16) >> 16;
  g = (color & mask << 8) >> 8;
  b = (color & mask);

  return create_text_color(r, g, b);
}

Color create_bg_color_cd(unsigned color) {
  unsigned char r, g, b;
  unsigned mask = (1 << 8) - 1;
  r = (color & mask << 16) >> 16;
  g = (color & mask << 8) >> 8;
  b = (color & mask);

  return create_bg_color(r, g, b);
}

void delete_color(Color color) { free(color); }