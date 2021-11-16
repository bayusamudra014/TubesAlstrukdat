#include "mainmenu.h"

void show_main_menu() {
  clear_screen();

  cm_modal_error("Ini adalah contoh error.");
  cm_modal_warning("Ini adalah contoh warning.");
  cm_modal_info("Ini adalah contoh info.");
}