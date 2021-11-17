#include "status_game.h"

#include <stdio.h>

StatusGame s_status_game;

void sg_create_state() { SG_S_BTS(s_status_game) = 0; }

void sg_reset_time() { s_status_game.Waktu_Permainan = 0; }

void sg_inc_time() { s_status_game.Waktu_Permainan++; }

void g_change_state(int type, int mv, StatusGame s_status_game) {
  if (type == 1) {
    Time curr = ol_get_head(SG_OL(s_status_game)).expiredTime;
    curr = SG_TIME(s_status_game) + ol_get_head(SG_OL(s_status_game)).item.expired;
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
