#include "loadex.h"

// lx_readNumber parses input to be an integer
int lx_readNumber(char *str)
{
  int result;
  int puiss;

  result = 0;
  puiss = 1;
  while (('-' == (*str)) || ((*str) == '+'))
  {
    if (*str == '-')
      puiss = puiss * -1;
    str++;
  }
  while ((*str >= '0') && (*str <= '9'))
  {
    result = (result * 10) + ((*str) - '0');
    str++;
  }
  return (result * puiss);
}


// readConfigFile will read config file and make the structure

// void ldx_newGame(const char *path, StatusGame *status_game);

// void ldx_loadGame(const char *path, StatusGame *status_game);

// void ldx_saveGame(const char *path, StatusGame status_game);
