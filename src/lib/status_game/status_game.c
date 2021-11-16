#include "status_game.h"

#include <stdio.h>

StatusGame s_status_game;

void sg_reset_time() { s_status_game.Waktu_Permainan = 0; }

void sg_inc_time() { s_status_game.Waktu_Permainan++; }

void g_change_state(int type, int mv) {
  if (type == 1) {
  } else if (type == 2) {
    t_increase_capacity(&(s_status_game.tas_mobita),
                        t_cap(s_status_game.tas_mobita));
  } else if (type == 3) {
    // move(*s, mv, true, false);
  } else if (type == 4) {
    int tm = s_status_game.Waktu_Permainan;
    if (tm < 50) {
      s_status_game.Waktu_Permainan = 0;
    } else {
      s_status_game.Waktu_Permainan -= 50;
    }
  }
}
