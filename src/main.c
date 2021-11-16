#include <stdio.h>

#include "views/views.h"

int main()
{
  StatusGame s_status_game;

  char file_name[50];
  scanf(" %[^\n]s", file_name);

  printf("loading...\n");
  readConfigFile(file_name, &s_status_game);
  printf("loading selesai\n");

  printf("%d",s_status_game.uang_mobita);
  return 0;
}
