#ifndef H_STATUS_GAME
#define H_STATUS_GAME

#include <stdio.h>

#include "../game/game.h"

typedef struct StatusGame {
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

} StatusGame;

#define SG_TDL(StatusGame) (StatusGame).to_do_list
#define SG_TAS(StatusGame) (StatusGame).tas_mobita
#define SG_TIME(StatusGame) (StatusGame).Waktu_Permainan
#define SG_OL(StatusGame) (StatusGame).order_list
#define SG_MONEY(StatusGame) (StatusGame).uang_mobita
#define SG_IG(StatusGame) (StatusGame).inventory_gadget
#define SG_PL(StatusGame) (StatusGame).progress_list
#define SG_IG(StatusGame) (StatusGame).inventory_gadget
#define SG_POS(StatusGame) (StatusGame).posisi_sekarang
#define SG_S_BTS(StatusGame) (StatusGame).back_to_sender
#define SG_MAP(StatusGame) (StatusGame).peta_game

extern StatusGame s_status_game;

/* Menginisialisasi state awal */
void sg_create_state();

/*Berfungsi untuk mereset waktu*/
void sg_reset_time();

/*Berfungsi untuk increment waktu*/
void sg_inc_time();

/* mengubah state game berdasarkan gadget yang diinputkan */
/* masih menunggu beberapa adt game selesai */
void g_change_state(int type, int mv, StatusGame s_status_game);

/* Mereload status game setelah waktu ditambahkan */
void sg_reload_status();

#endif
