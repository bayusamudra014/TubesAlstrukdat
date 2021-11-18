#include "status_game.h"

#include <stdio.h>
#include <string.h>

StatusGame s_status_game;

void sg_create_state() { SG_S_BTS(s_status_game) = 0; }

void sg_reset_time() { s_status_game.Waktu_Permainan = 0; }

void sg_inc_time() {
  s_status_game.Waktu_Permainan++;
  sg_reload_status();
}

void sg_reload_status() {
  // Menghapus semua item Perishable yang sudah tak berlaku
  Tas mobita = SG_TAS(s_status_game);
  Order* buffer = mobita.isiTas.buffer;

  for (int i = 0; i <= mobita.isiTas.idxTop; i++) {
    if (buffer[i].expiredTime <= s_status_game.Waktu_Permainan) {
      pl_delete_by_order(SG_PL(s_status_game), buffer[i]);

      for (int j = i; j < mobita.isiTas.idxTop - 1; j++) {
        buffer[j] = buffer[j + 1];
      }
    }
  }

  SG_TAS(s_status_game) = mobita;

  // Menambah order pada ToDoList
  while (ol_get_head(SG_OL(s_status_game)).incomingTime <=
         s_status_game.Waktu_Permainan) {
    Order res = ol_dequeue_order(&SG_OL(s_status_game));
    td_insertTask(&SG_TDL(s_status_game), res);
  }
}

void g_change_state(int type, int mv, StatusGame s_status_game) {
  if (type == 1) {
    Time curr = ol_get_head(SG_OL(s_status_game)).expiredTime;
    curr =
        SG_TIME(s_status_game) + ol_get_head(SG_OL(s_status_game)).item.expired;
  } else if (type == 2) {
    t_increase_capacity(&(s_status_game.tas_mobita),
                        t_cap(s_status_game.tas_mobita));
  } else if (type == 3) {
    move(s_status_game, mv, true, false);
  } else if (type == 4) {
    int tm = s_status_game.Waktu_Permainan;
    if (tm < 50) {
      s_status_game.Waktu_Permainan = 0;
    } else {
      s_status_game.Waktu_Permainan -= 50;
    }
  }
}
