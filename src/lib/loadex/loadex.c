#include "loadex.h"

#include "mesinkar.h"

// static char configFilename[] = "config.conf";
// static char savefileFilename[] = "savefile.dat";

static FILE *savefile;

void ignoreBlank()
{
  while (CC != EOF && (CC == ' ' || CC == '\n'))
    ADV();
}

// Advances until CC is not blank
void ignoreBlankSTDIN()
{
  // While not blank
  while (CC != EOF && CC == ' ')
    ADVSTDIN();
}

// readNumber parses input to be an integer
int readNumber()
{
  int n = 0;

  ignoreBlank();
  while (!EOP && CC != EOF && CC != ' ' && CC != '\n')
  {
    n = n * 10 + (CC - '0');
    ADV();
  }

  return n;
}

// readSTDIN will input from STDIN and convert it to ADT Word
void readSTDIN(word *input)
{
  STARTSTDIN();
  ignoreBlankSTDIN();

  // Initialize word
  (*input).length = 0;

  while (!EOP && CC != '\n')
  {
    (*input).wordArray[(*input).length] = CC;
    ++(*input).length;
    ADVSTDIN();
  }
}

// readNumberSTDIN returns number from STDIN input
void readNumberSTDIN(int *X)
{
  STARTSTDIN();
  *X = 0;
  while (!EOP && CC != '\n')
  {
    int tmp = CC - '0';
    *X = (*X) * 10 + tmp;
    ADVSTDIN();
  }
}

// readConfigFile will read config file and make the structure
void readConfigFile(char configFilename[])
{
  // Persiapan untuk status Game
  ProgressList progress_list;
  ToDoList to_do_list;
  Tas tas_mobita;
  OrderList order_list;
  inventory_gadget inventory_gadget;
  Time Waktu_Permainan;
  Building posisi_sekarang;
  Map peta_game;
  int uang_mobita;

  // Persiapan Lain
  int i, j;
  ol_create_orederlist(&order_list);

  START(configFilename);
  ignoreBlank();

  // Read map size
  printf("map size..\n");
  ignoreBlank();
  int row = readNumber();
  ignoreBlank();
  int col = readNumber();

  // Membuat building List
  DynamicList buildingList;
  ignoreBlank();
  int buildingN = readNumber();
  buildingN += 1;
  dl_create_list(&buildingList, buildingN);
  printf("building list..\n");
  // alokasi map
  m_allocate(&peta_game, row, col, buildingList);
  
  // Read HQ
  Building HQ;
  ignoreBlank();
  int x = readNumber();
  ignoreBlank();
  int y = readNumber();
  b_create_building(&HQ, x, y, '8', '#');
  map_elmt(peta_game, x, y) = '8';
  dl_insert_last(&peta_game.buildinglist, HQ);

  printf("read HQ\n");

  // Proses memasukkan building"
  char buildingLabel;
  printf("baca building..\n");
  for (i = 1; i <= buildingN; i++)
  {
    printf("building ke %d\n", i);
    // Membaca label Building
    ignoreBlank();
    buildingLabel = CC;
    ADV();

    // membaca coordinate building
    ignoreBlank();
    x = readNumber();
    ignoreBlank();
    y = readNumber();

    // Mengubah peta
    map_elmt(peta_game, x, y) = buildingLabel;

    // membuat building
    Building currentBuilding;
    b_create_building(&currentBuilding, x, y, buildingLabel, '#');

    // memasukkannya ke dalam list building
    dl_insert_last(&peta_game.buildinglist, currentBuilding);
  }

  Matrix adjMatrix;
  m_create_matrix(&adjMatrix, buildingN, buildingN);
  printf("adj matrix\n");
  for (i = 0; i <= buildingN; i++)
  {
    for (j = 0; j <= buildingN; j++)
    {
      ignoreBlank();
      x = readNumber();
      m_elmt(adjMatrix, i, j) = x;
    }
  }

  peta_game.adj = adjMatrix;

  // Membaca orderlist
  printf("order list\n");
  ignoreBlank();
  int orderN = readNumber();

  int waktuPesanan, expTime;
  char pickUp, dropOff, tipeItem;
  Building P, D;

  for (i = 1; i <= orderN; i++)
  {
    printf("order ke %d\n", i);
    ignoreBlank();
    waktuPesanan = readNumber();

    ignoreBlank();
    pickUp = CC;
    ADV();
    for (j = 1; j <= buildingN; j++)
    {
      if (loc(peta_game, j).label == pickUp)
      {
        P = loc(peta_game, j);
      }
    }

    ignoreBlank();
    dropOff = CC;
    ADV();
    for (j = 1; j <= buildingN; j++)
    {
      if (loc(peta_game, j).label == dropOff)
      {
        D = loc(peta_game, j);
      }
    }

    ignoreBlank();
    tipeItem = CC;
    ADV();

    expTime = -1;
    if (tipeItem == 'P')
    {
      ignoreBlank();
      expTime = readNumber;
    }

    Item item;
    i_create_item(&item, tipeItem, expTime);

    Order order;
    o_create_order(&order, item, P, D, waktuPesanan);

    ol_add_order(&order_list, order);
  }
  ignoreBlank();

  printf("Finishing..\n");
  // Finishing
  pl_create_progress(&progress_list);
  td_create(&to_do_list);
  t_create_tas(&tas_mobita);
  // o_create_order();
  ig_create_ig(&inventory_gadget);
  Waktu_Permainan = 0;
  posisi_sekarang = HQ;
  // peta_game
  uang_mobita = 0;
  printf("uang mobita\n");

  // mengubah status game
  s_status_game->progress_list = progress_list;
  s_status_game->to_do_list = to_do_list;
  s_status_game->tas_mobita = tas_mobita;
  s_status_game->order_list = order_list;
  s_status_game->inventory_gadget = inventory_gadget;
  s_status_game->Waktu_Permainan = Waktu_Permainan;
  s_status_game->posisi_sekarang = posisi_sekarang;
  s_status_game->peta_game = peta_game;
  s_status_game->uang_mobita = uang_mobita;

  printf("%d",s_status_game->uang_mobita);
  printf("mengubah status game..\n");
}

// Print ASCII of character (for debugging purposes)
void printASCIIFile() {}

// Print word
void printWord(word W) {}

// Save to file
void saveToFile()
{
  savefile = fopen("halo.txt", "w");
  // Output map size
  fprintf(savefile, "Halo");

  fclose(savefile);
}

// Load from file
void loadFromFile(StatusGame *s_status_game) {}

// Word to int converter
int intConverter(word W)
{
  int result = 0;
  int temp;
  for (int i = 0; i < W.length; i++)
  {
    temp = (int)W.wordArray[i] - '0';
    result = result * 10 + temp;
  }
  return result;
}

// Word Compare
boolean wordCompare(word W, char *S)
{
  boolean result = true;
  int i;
  for (i = 0; i < W.length; i++)
  {
    char temp = (char)W.wordArray[i];
    if (temp != S[i])
    {
      result = false;
    }
  }
  int a = strlen(S);
  if (W.length != a)
  {
    result = false;
  }
  return result;
}

// void ldx_newGame(const char *path, StatusGame *status_game);

// void ldx_loadGame(const char *path, StatusGame *status_game);

// void ldx_saveGame(const char *path, StatusGame status_game);
