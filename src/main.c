#include <stdio.h>

#include "components/components.h"
#include "lib/lib.h"

int main() {
  clear_screen();

  cm_modal_error("Ini adalah contoh error.");
  cm_modal_warning("Ini adalah contoh warning.");
  cm_modal_info("Ini adalah contoh info.");

  return 0;
}
