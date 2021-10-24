#include "modal.h"

#include "stdio.h"

/* Helper Procedure
   Prosedur ini mncetak modal dengan warna umum
*/
void __cm_print_modal(Color headerColor, const char* title,
                      const char* message) {
  set_decorator(DECORATOR_REVERSED);
  set_text_color(headerColor);

  printf(" %s ", title);

  reset_color();

  printf("\n%s\n\n", message);
}

void cm_modal_error(const char* message) {
  Color header = create_text_color_cd(0xd62828);
  __cm_print_modal(header, "Error", message);

  delete_color(header);
}

void cm_modal_info(const char* message) {
  Color header = create_text_color_cd(0x2a9d8f);
  __cm_print_modal(header, "Info", message);

  delete_color(header);
}

void cm_modal_warning(const char* message) {
  Color header = create_text_color_cd(0xe76f51);

  __cm_print_modal(header, "Warning", message);

  delete_color(header);
}