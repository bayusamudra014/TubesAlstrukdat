#include "map.h"

void m_allocate(Map *m, int row, int col, DynamicList bl) {
  (*m).buildinglist = bl;
  Row(*m) = row;
  Col(*m) = col;
  int i, j;
  for (i = 0; i < Row(*m) + 2; i++) {
    for (j = 0; j < Col(*m) + 2; j++) {
      if (i == 0 || j == 0 || i == Row(*m) + 1 || j == Col(*m) + 1) {
        map_elmt(*m, i, j) = '*';
      } else {
        map_elmt(*m, i, j) = ' ';
      }
    }
  }
}

void m_assign(Map *m) {
  int i;
  for (i = 0; i < loc_nEff(*m); i++) {
    map_elmt(*m, m_elmt_x(*m, i), m_elmt_y(*m, i)) = loc_elmt(*m, i);
  }
  dl_create_list(&reachable(*m), loc_nEff(*m));
}

int m_get_idx(Map m, char b) {
  for (int i = 0; i < loc_nEff(m); i++) {
    if (loc_elmt(m, i) == b) {
      return i;
    }
  }
}

void m_display(Map m) {
  int i, j;
  for (i = 0; i < Row(m) + 2; i++) {
    for (j = 0; j < Col(m) + 2; j++) {
      char curr = map_elmt(m, i, j);
      if (curr != '*' && curr != ' ') {
        int idx;
        idx = m_get_idx(m, curr);
        if (loc_type(m, idx) == 'm') {
          print_yellow(curr);
        } else if (loc_type(m, idx) == 'p') {
          print_red(curr);
        } else if (loc_type(m, idx) == 'd') {
          print_blue(curr);
        } else if (loc_type(m, idx) == 'r') {
          print_green(curr);
        } else {
          printf("%c", curr);
        }
      } else {
        printf("%c", curr);
      }
    }
    printf("\n");
  }
}

void m_display_reachable(Map m) {
  int i;
  printf("Tempat yang bisa dicapai: \n");
  for (i = 1; i <= reach_nEff(m); i++) {
    printf("%d. ", i);
    b_display(dl_elmt(reachable(m), i));
  }
}
