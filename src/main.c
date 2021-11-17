#include <stdio.h>

#include "views/views.h"

int main()
{
  // char file_name[50];
  // scanf(" %[^\n]s", file_name);

  printf("loading...\n");
  lx_readConfigFile_silent("config.conf");
  printf("loading selesai\n");
  
  lx_saveToFile("save.conf");
  return 0;
}
