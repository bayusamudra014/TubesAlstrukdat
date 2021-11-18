#include "loadex.h"

void lx_readConfigFile_silent(char configFilename[]) {
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
  int i, j;
  ol_create_orederlist(&order_list);
  wm_set_blank(" \n", 2);

  static FILE *pita;
  pita = fopen(configFilename, "r");
  wm_start_word(pita);

  wm_adv_word();

  // Read map size
  // printf("map size..\n");
  int row = lx_readNumber(wm_current_word.contents);
  wm_adv_word();
  int col = lx_readNumber(wm_current_word.contents);

  // printf("%d %d\n", row,col);

  wm_adv_word();
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
  for (i = 1; i <= buildingN - 1; i++) {
    // printf("building ke %d\n", i);
    // Membaca label Building
    wm_adv_word();
    buildingLabel = *wm_current_word.contents;

    // membaca coordinate building
    wm_adv_word();
    x = lx_readNumber(wm_current_word.contents);
    wm_adv_word();
    y = lx_readNumber(wm_current_word.contents);

    // printf("%c %d %d\n",buildingLabel,x,y);
    // Mengubah peta
    map_elmt(peta_game, x, y) = buildingLabel;

    // membuat building
    Building currentBuilding;
    b_create_building(&currentBuilding, x, y, buildingLabel, '#', i);

    // memasukkannya ke dalam list building
    dl_insert_last(&peta_game.buildinglist, currentBuilding);
  }

  wm_adv_word();

  Matrix adjMatrix;
  m_create_matrix(&adjMatrix, buildingN, buildingN);
  for (i = 0; i < buildingN; i++) {
    for (j = 0; j < buildingN; j++) {
      wm_adv_word();
      x = lx_readNumber(wm_current_word.contents);
      m_elmt(adjMatrix, i, j) = x;
    }
  }

  peta_game.adj = adjMatrix;

  // reachable
  DynamicList reachable;
  dl_create_list(&reachable, buildingN - 1);
  for (int i = 0; i < buildingN; i++) {
    if (m_elmt(adjMatrix, 0, i) == 1) {
      Building bIsReachable = dl_elmt(buildingList, i);
      dl_insert_last(&reachable, bIsReachable);
    }
  }
  peta_game.reachable = reachable;

  wm_adv_word();
  // Membaca orderlist
  wm_adv_word();
  int orderN = lx_readNumber(wm_current_word.contents);
  int waktuPesanan, expTime;
  char pickUp, dropOff, tipeItem;
  Building P, D;

  for (i = 1; i <= orderN; i++) {
    wm_adv_word();
    waktuPesanan = lx_readNumber(wm_current_word.contents);

    wm_adv_word();
    pickUp = *wm_current_word.contents;
    for (j = 1; j <= buildingN; j++) {
      if (loc(peta_game, j).label == pickUp) {
        P = loc(peta_game, j);
      }
    }

    wm_adv_word();
    dropOff = *wm_current_word.contents;
    for (j = 1; j <= buildingN; j++) {
      if (loc(peta_game, j).label == dropOff) {
        D = loc(peta_game, j);
      }
    }

    wm_adv_word();
    tipeItem = *wm_current_word.contents;

    expTime = -1;
    if (tipeItem == 'P') {
      wm_adv_word();
      expTime = lx_readNumber(wm_current_word.contents);
    }
    Item item;
    i_create_item(&item, tipeItem, expTime);

    Order order;
    o_create_order(&order, item, P, D, waktuPesanan);

    ol_add_order(&order_list, order);
  }

  // Finishing
  pl_create_progress(&progress_list);
  td_create(&to_do_list);
  t_create_tas(&tas_mobita);
  ig_create_ig(&inventory_gadget);
  Waktu_Permainan = 1;
  posisi_sekarang = HQ;
  // uang nobita
  uang_mobita = 0;

  // back to sender
  back_to_sender = 0;

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
