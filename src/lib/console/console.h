/**
 * Filename: console.h
 * Description: Console related Utility
 *
 * Created by Bayu Samudra (21/10/2021)
 **/

#include "pcolor/pcolor.h"

#ifndef H_CONSOLE
#define H_CONSOLE

/*
  Clean the screen
*/

typedef char* Decorator;

#define DECORATOR_UNDERLINE "\x1b[4m"
#define DECORATOR_REVERSED "\x1b[7m"
#define DECORATOR_BOLD "\x1b[1m"

void set_decorator(Decorator dec);
void reset_decorator();
void clear_screen();

#endif
