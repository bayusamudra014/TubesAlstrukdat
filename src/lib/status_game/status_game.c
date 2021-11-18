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
  Order *buffer = mobita.isiTas.buffer;

  for (int i = 0; i <= mobita.isiTas.idxTop; i++) {
    if (buffer[i].expiredTime <= s_status_game.Waktu_Permainan) {
      pl_delete_by_order(&SG_PL(s_status_game), buffer[i]);

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

  Building reachable[30];
  int cnt;
  m_clear_reachable(&SG_MAP(s_status_game));
  m_get_accessable_b(SG_MAP(s_status_game), SG_POS(s_status_game), reachable, &cnt);
  for (int i = 0; i<cnt;i++){
    Building b = reachable[i];
    dl_insert_last(&SG_MAP(s_status_game).reachable,b);
  }

  
  
}
