#include "console.h"

#include <stdio.h>
#include <stdlib.h>

void clear_screen() { system("@cls||clear"); }

void set_decorator(Decorator dec) { printf("%s", dec); }

void reset_decorator() { reset_color(); }