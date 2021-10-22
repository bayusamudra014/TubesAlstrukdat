#include "console.h"

#include <stdio.h>
#include <stdlib.h>

void clear_screen() {
  if (!system("@cls||clear")) {
    printf("\x1B[1J");
  }
}

void set_decorator(Decorator dec) { printf("%s", dec); }

void reset_decorator() { reset_color(); }