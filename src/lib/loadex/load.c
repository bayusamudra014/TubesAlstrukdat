#include "loadex.h"

void lx_loadSaveFile(char saveFileName[])
{
  printf("LOADING......");
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
  int back_to_sender;

  // Persiapan Lain

  static FILE *pita;
  pita = fopen(saveFileName, "r");
  wm_start_word(pita);

  wm_adv_word(); // MAP

  // Read map size
  // printf("map size..\n");
  int row = lx_readNumber(wm_current_word.contents);
  wm_adv_word();
  int col = lx_readNumber(wm_current_word.contents);

  // printf("%d %d\n", row,col);

  wm_adv_word(); // BLD
  // Membuat building List
  DynamicList buildingList;
  wm_adv_word();
  int buildingN = lx_readNumber(wm_current_word.contents);
  // printf("%d\n",buildingN);
  buildingN += 1;
  dl_create_list(&buildingList, buildingN);

  // alokasi map
  m_allocate(&peta_game, row, col, buildingList);

  // Read HQ
  Building HQ;
  wm_adv_word();
  // printf("halo %s halo\n",wm_current_word.contents);
  int x = lx_readNumber(wm_current_word.contents);
  wm_adv_word();

  int y = lx_readNumber(wm_current_word.contents);
  // printf("%d %d\n",x,y);
  b_create_building(&HQ, x, y, '8', '#', 0);
  map_elmt(peta_game, x, y) = '8';
  dl_insert_last(&peta_game.buildinglist, HQ);

  // Proses memasukkan building"
  char buildingLabel;
  // printf("baca building..\n");
  for (int i = 1; i < buildingN; i++)
  {
    // printf("building ke %d\n", i);
    // Membaca label Building
    wm_adv_word();
    buildingLabel = *wm_current_word.contents;

    // membaca coordinate building
    wm_adv_word();
    x = lx_readNumber(wm_current_word.contents);
    wm_adv_word();
    y = lx_readNumber(wm_current_word.contents);
    wm_adv_word();
    char bTipe = *wm_current_word.contents;

    // printf("%c %d %d\n",buildingLabel,x,y);
    // Mengubah peta
    map_elmt(peta_game, x, y) = buildingLabel;

    // membuat building
    Building currentBuilding;
    b_create_building(&currentBuilding, x, y, buildingLabel, bTipe, i);

    // memasukkannya ke dalam list building
    dl_insert_last(&peta_game.buildinglist, currentBuilding);
  }

  // wm_adv_word();

  //Adj Matriks
  Matrix adjMatrix;
  m_create_matrix(&adjMatrix, buildingN, buildingN);

  for (int i = 0; i < buildingN; i++)
  {
    for (int j = 0; j < buildingN; j++)
    {
      wm_adv_word();
      // printf("%c",*wm_current_word.contents);
      x = *wm_current_word.contents - '0';
      // printf("%d ",x);
      m_elmt(adjMatrix, i, j) = x;
    }
    // printf("\n");
  }

  peta_game.adj = adjMatrix;

  //reachable
  wm_adv_word(); //REACHABLE
      // printf("%s\n",wm_current_word.contents);

  DynamicList reachable;
  wm_adv_word();
  int reachN = lx_readNumber(wm_current_word.contents);
  // printf("%d\n",reachN);
  dl_create_list(&reachable, buildingN - 1);
  for (int i = 0; i < reachN; i++)
  {
    Building reachB;
    wm_adv_word();

    char reachLabel = *wm_current_word.contents;
    // printf("%s\n",wm_current_word.contents);
    for (int j = 1; j <= buildingN; j++)
    {
      if (loc(peta_game, j).label == reachLabel)
      {
        reachB = loc(peta_game, j);
        dl_insert_last(&reachable, reachB);
      }
    }
  }
  peta_game.reachable = reachable;

  //Current Position
  wm_adv_word(); //CURRENT_POSITION
  wm_adv_word();
  char currPos = *wm_current_word.contents;
  for (int j = 0; j < buildingN; j++)
  {
    if (loc_elmt(peta_game, j) == currPos)
    {
      posisi_sekarang = loc(peta_game, j);
    }
  }

  wm_adv_word(); // ORD

  // Membaca orderlist
  ol_create_orederlist(&order_list);
  wm_adv_word();
  int orderN = lx_readNumber(wm_current_word.contents);

  for (int i = 1; i <= orderN; i++)
  {
    int waktuPesanan, ordID, itemID;
    Time expTime, ordExpTime;
    char pickUp, dropOff, tipeItem;
    Building P, D;

    wm_adv_word();
    ordID = lx_readNumber(wm_current_word.contents);

    wm_adv_word();
    waktuPesanan = lx_readNumber(wm_current_word.contents);

    wm_adv_word();
    pickUp = *wm_current_word.contents;
    for (int j = 1; j <= buildingN; j++)
    {
      if (loc(peta_game, j).label == pickUp)
      {
        P = loc(peta_game, j);
      }
    }

    wm_adv_word();
    dropOff = *wm_current_word.contents;
    for (int j = 1; j <= buildingN; j++)
    {
      if (loc(peta_game, j).label == dropOff)
      {
        D = loc(peta_game, j);
      }
    }

    wm_adv_word();
    ordExpTime = lx_readNumber(wm_current_word.contents);
    // printf("%d",ordExpTime);

    __wm_free();
    __wm_allocate();

    wm_adv_word();
    itemID = lx_readNumber(wm_current_word.contents);
    // printf("%s",wm_current_word.contents);

    wm_adv_word();
    tipeItem = *wm_current_word.contents;

    expTime = -1;
    if (tipeItem == 'P')
    {
      wm_adv_word();
      expTime = lx_readNumber(wm_current_word.contents);
    }
    Item item;
    item.expired = expTime;
    item.itemID = itemID;
    item.type = tipeItem;

    Order order;
    order.dropOff = D;
    order.expiredTime = ordExpTime;
    order.incomingTime = waktuPesanan;
    order.item = item;
    order.orderID = ordID;
    order.pickUp = P;

    ol_add_order(&order_list, order);
  }

  // Current time
  wm_adv_word(); // CURRENT_TIME
  wm_adv_word();
  Waktu_Permainan = lx_readNumber(wm_current_word.contents);

  // uang nobita
  wm_adv_word(); // CURRENT_MONEY
  wm_adv_word();
  uang_mobita = lx_readNumber(wm_current_word.contents);

  // back to sender
  wm_adv_word(); // BACK_TO_SENDER
  wm_adv_word();
  back_to_sender = lx_readNumber(wm_current_word.contents);
  

  // INVENTORY_GADGET
  wm_adv_word(); // INVENTORY_GADGET
  ig_create_ig(&inventory_gadget);
  wm_adv_word();
  int igN = lx_readNumber(wm_current_word.contents);
  for (int i = 0; i < igN; i++)
  {
    Gadget gadget;
    int gPrice, gId;
    char gLabel;
    wm_adv_word();
    gId = lx_readNumber(wm_current_word.contents);
    wm_adv_word();
    gLabel = *wm_current_word.contents;
    wm_adv_word();
    gPrice = lx_readNumber(wm_current_word.contents);
    gadget.gadgetID = gId;
    gadget.label =gLabel;
    gadget.price = gPrice;

    ig_add_item(&inventory_gadget, gadget);
  }

  // TAS NOBITA
  wm_adv_word(); // TAS_MOBITA
  t_create_tas(&tas_mobita);
  wm_adv_word();
  int tasCap = lx_readNumber(wm_current_word.contents);
  tas_mobita.capacity = tasCap;
  wm_adv_word();
  int tasN = lx_readNumber(wm_current_word.contents);

  for (int i = 0; i < tasN; i++)
  {
    int waktuPesanan, ordID, itemID;
    Time expTime, ordExpTime;
    char pickUp, dropOff, tipeItem;
    Building P, D;

    wm_adv_word();
    ordID = lx_readNumber(wm_current_word.contents);

    wm_adv_word();
    waktuPesanan = lx_readNumber(wm_current_word.contents);

    wm_adv_word();
    pickUp = *wm_current_word.contents;
    for (int j = 1; j <= buildingN; j++)
    {
      if (loc(peta_game, j).label == pickUp)
      {
        P = loc(peta_game, j);
      }
    }

    wm_adv_word();
    dropOff = *wm_current_word.contents;
    for (int j = 1; j <= buildingN; j++)
    {
      if (loc(peta_game, j).label == dropOff)
      {
        D = loc(peta_game, j);
      }
    }

    wm_adv_word();
    ordExpTime = lx_readNumber(wm_current_word.contents);
    // printf("%d",ordExpTime);

    __wm_free();
    __wm_allocate();

    wm_adv_word();
    itemID = lx_readNumber(wm_current_word.contents);
    printf("%s", wm_current_word.contents);

    wm_adv_word();
    tipeItem = *wm_current_word.contents;

    expTime = -1;
    if (tipeItem == 'P')
    {
      wm_adv_word();
      expTime = lx_readNumber(wm_current_word.contents);
    }
    Item item;
    item.expired = expTime;
    item.itemID = itemID;
    item.type = tipeItem;

    Order order;
    order.dropOff = D;
    order.expiredTime = ordExpTime;
    order.incomingTime = waktuPesanan;
    order.item = item;
    order.orderID = ordID;
    order.pickUp = P;

    t_add_item(&tas_mobita, order);
  }

  //To Do List
  wm_adv_word(); // TO_DO_LIST
  td_create(&to_do_list);
  wm_adv_word();
  int tdlN = lx_readNumber(wm_current_word.contents);

  for (int i = 0; i < tdlN; i++)
  {
    int waktuPesanan, ordID, itemID;
    Time expTime, ordExpTime;
    char pickUp, dropOff, tipeItem;
    Building P, D;

    wm_adv_word();
    ordID = lx_readNumber(wm_current_word.contents);

    wm_adv_word();
    waktuPesanan = lx_readNumber(wm_current_word.contents);

    wm_adv_word();
    pickUp = *wm_current_word.contents;
    for (int j = 1; j <= buildingN; j++)
    {
      if (loc(peta_game, j).label == pickUp)
      {
        P = loc(peta_game, j);
      }
    }

    wm_adv_word();
    dropOff = *wm_current_word.contents;
    for (int j = 1; j <= buildingN; j++)
    {
      if (loc(peta_game, j).label == dropOff)
      {
        D = loc(peta_game, j);
      }
    }

    wm_adv_word();
    ordExpTime = lx_readNumber(wm_current_word.contents);
    // printf("%d",ordExpTime);

    __wm_free();
    __wm_allocate();

    wm_adv_word();
    itemID = lx_readNumber(wm_current_word.contents);
    printf("%s", wm_current_word.contents);

    wm_adv_word();
    tipeItem = *wm_current_word.contents;

    expTime = -1;
    if (tipeItem == 'P')
    {
      wm_adv_word();
      expTime = lx_readNumber(wm_current_word.contents);
    }
    Item item;
    item.expired = expTime;
    item.itemID = itemID;
    item.type = tipeItem;

    Order order;
    order.dropOff = D;
    order.expiredTime = ordExpTime;
    order.incomingTime = waktuPesanan;
    order.item = item;
    order.orderID = ordID;
    order.pickUp = P;

    td_insertTask(&to_do_list, order);
  }

  //PROGRESS LIST
  wm_adv_word(); // PROGRESS_LIST
  pl_create_progress(&progress_list);
  wm_adv_word();
  int plN = lx_readNumber(wm_current_word.contents);

  for (int i = 0; i < plN; i++)
  {
    int waktuPesanan, ordID, itemID;
    Time expTime, ordExpTime;
    char pickUp, dropOff, tipeItem;
    Building P, D;

    wm_adv_word();
    ordID = lx_readNumber(wm_current_word.contents);

    wm_adv_word();
    waktuPesanan = lx_readNumber(wm_current_word.contents);

    wm_adv_word();
    pickUp = *wm_current_word.contents;
    for (int j = 1; j <= buildingN; j++)
    {
      if (loc(peta_game, j).label == pickUp)
      {
        P = loc(peta_game, j);
      }
    }

    wm_adv_word();
    dropOff = *wm_current_word.contents;
    for (int j = 1; j <= buildingN; j++)
    {
      if (loc(peta_game, j).label == dropOff)
      {
        D = loc(peta_game, j);
      }
    }

    wm_adv_word();
    ordExpTime = lx_readNumber(wm_current_word.contents);
    // printf("%d",ordExpTime);

    __wm_free();
    __wm_allocate();

    wm_adv_word();
    itemID = lx_readNumber(wm_current_word.contents);
    printf("%s", wm_current_word.contents);

    wm_adv_word();
    tipeItem = *wm_current_word.contents;

    expTime = -1;
    if (tipeItem == 'P')
    {
      wm_adv_word();
      expTime = lx_readNumber(wm_current_word.contents);
    }
    Item item;
    item.expired = expTime;
    item.itemID = itemID;
    item.type = tipeItem;

    Order order;
    order.dropOff = D;
    order.expiredTime = ordExpTime;
    order.incomingTime = waktuPesanan;
    order.item = item;
    order.orderID = ordID;
    order.pickUp = P;

    ll_insert_first(&progress_list, order);
  }


  

  // mengubah status game
  SG_PL(s_status_game) = progress_list;
  SG_TDL(s_status_game) = to_do_list;
  SG_TAS(s_status_game) = tas_mobita;
  SG_OL(s_status_game) = order_list;
  SG_IG(s_status_game) = inventory_gadget;
  SG_TIME(s_status_game) = Waktu_Permainan;
  SG_POS(s_status_game) = posisi_sekarang;
  SG_MAP(s_status_game) = peta_game;
  SG_MONEY(s_status_game) = uang_mobita;
  SG_S_BTS(s_status_game) = back_to_sender;
}