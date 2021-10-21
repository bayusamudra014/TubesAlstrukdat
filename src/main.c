#include <stdio.h>

#include "lib/console/console.h"

int main() {
  clear_screen();
  printf("Halo, Dunia\n");

  set_text_color(TEXT_BLUE);
  printf("Teks ini bakalan berwarna biru.\n");
  reset_color();

  printf("Text ini Normal.\n");

  print_color(TEXT_RED, "Halo, Dunia aku warna merah\n");

  print_colored_char(TEXT_BLACK, 'R');
  print_colored_char(TEXT_RED, 'R');
  print_colored_char(TEXT_GREEN, 'A');
  print_colored_char(TEXT_YELLOW, 'I');
  print_colored_char(TEXT_BLUE, 'N');
  print_colored_char(TEXT_MAGENTA, 'B');
  print_colored_char(TEXT_CYAN, 'O');
  print_colored_char(TEXT_WHITE, 'W');

  printf("\n");

  print_colored_char(TEXT_GRAY, 'R');
  print_colored_char(TEXT_BRIGHT_RED, 'A');
  print_colored_char(TEXT_BRIGHT_GREEN, 'I');
  print_colored_char(TEXT_BRIGHT_YELLOW, 'N');
  print_colored_char(TEXT_BRIGHT_BLUE, 'B');
  print_colored_char(TEXT_BRIGHT_CYAN, 'O');
  print_colored_char(TEXT_BRIGHT_MAGENTA, 'W');
  print_colored_char(TEXT_BRIGHT_WHITE, 'W');

  printf("\n\n");

  set_bg_color(BG_BLUE);
  set_text_color(TEXT_BLACK);
  printf("   Testing   ");
  reset_color();

  printf("\nOKEY\n");

  Color warnaku = create_text_color(253, 200, 253);
  print_color(warnaku, "Halo, ini warnanya unik.\n");

  Color warnaWarni = create_text_color_cd(0xCBFF4D);
  set_decorator(DECORATOR_UNDERLINE);
  print_color(warnaWarni, "Halo, ini juga baru.\n\n");
  reset_decorator();

  return 0;
}
