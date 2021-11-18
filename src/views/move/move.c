#include "move_page.h"

void move(StatusGame *s, int mv, boolean gadget_used, int heavy_cnt) {
  Map m = s->peta_game;

  int cnt;
  Building reachable[30];

  m_get_accessable_b(m, SG_POS(*s), reachable, &cnt);

  if (gadget_used == false) {
    if (mv < cnt && 0 <= mv) {
      s->posisi_sekarang = reachable[mv];
      s->Waktu_Permainan += 1 + heavy_cnt;
    } else {
      printf("\nLokasi tidak terjangkau");
    }
  } else {
    if (mv < cnt && 0 <= mv) {
      s->posisi_sekarang = dl_elmt(m.buildinglist, mv - 1);
      s->Waktu_Permainan += 1 + heavy_cnt;
    } else {
      printf("\nLokasi tidak ada");
    }
  }
}

void move_boost(StatusGame *s, int mv, int curr_move) {
  Map m = s->peta_game;

  int cnt;
  Building reachable[30];

  m_get_accessable_b(m, SG_POS(*s), reachable, &cnt);

  if (mv < cnt) {
    s->posisi_sekarang = reachable[mv];
    if (curr_move % 2 == 0) {
      s->Waktu_Permainan += 1;
    }
  }
}

void show_move(StatusGame *s) {
  Map curr_map = s->peta_game;
  m_display_reachable(curr_map, s->posisi_sekarang);
  printf("Tuliskan ");
  print_yellow('0');
  printf(" kalau kamu ingin membatalkan aksi.\n");

  printf("\nPosisi yang dipilih: ");
  int mv;
  read_int_line(&mv, 3);

  if (mv != 0) {
    move(s, mv - 1, false, t_num_heavy(s->tas_mobita));
  }

  printf("\nNobita sekarang berada di titik ");
  Building pos = s->posisi_sekarang;
  print_yellow(pos.label);

  printf(" (%d, %d)\n", pos.position.x, pos.position.y);

  printf("🕑 Waktu: %u\n", SG_TIME(*s));
  sg_reload_status();
}
