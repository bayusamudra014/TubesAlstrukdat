#include "map.h"

#include <ctype.h>

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

Building m_get_building(Map m, char b) {
  int i = 0;

  for (i = 0; i < loc_nEff(m); i++) {
    if (loc_elmt(m, i) == b) {
      break;
    }
  }

  return loc(m, i);
}

void m_display(Map m, ToDoList tdl, ProgressList pl, Building pos) {
  int i, j;
  for (i = 0; i < Row(m) + 2; i++) {
    for (j = 0; j < Col(m) + 2; j++) {
      char curr = map_elmt(m, i, j);
      if (curr != '*' && curr != ' ') {
        Building idx;
        idx = m_get_building(m, curr);
        if (b_is_equal(idx, pos)) {
          print_yellow(curr);
        } else if (m_is_dropoff(m, tdl, idx)) {
          print_blue(curr);
        } else if (m_is_pickup(m, pl, idx)) {
          print_red(curr);
        } else if (m_is_accessible(m, pos, idx)) {
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

void m_display_reachable(Map m, Building pos) {
  Building hasil[30];
  int jumlah;
  m_get_accessable_b(m, pos, hasil, &jumlah);

  for (int i = 0; i < jumlah; i++) {
    printf("%d. ", i + 1);
    b_display(hasil[i]);
  }
}

void m_get_accessable_b(Map m, Building pos, Building *arr, int *res_cnt) {
  int i = 0, cnt = 0;
  int length = dl_length(m.buildinglist);

  while (i < length) {
    if (m_is_accessible(m, pos, dl_elmt(m.buildinglist, i))) {
      arr[cnt] = dl_elmt(m.buildinglist, i);
      cnt++;
    }

    i++;
  }

  *res_cnt = cnt;
}

void m_clear_reachable(Map *m) {
  DlEltype temp;
  while (!dl_is_empty(reachable(*m))) {
    dl_delete_last(&reachable(*m), &temp);
  }
}

boolean m_is_accessible(Map m, Building source, Building dest) {
  Matrix data = m.adj;
  return m_elmt(data, source.index, dest.index);
}

boolean m_is_pickup(Map m, ToDoList tdl, Building building) {
  LinkedList l = tdl;
  boolean isPickup = false;

  while (l && !isPickup) {
    if (b_is_equal(l->payload.pickUp, building)) {
      isPickup = true;
    } else {
      l = l->next;
    }
  }

  return isPickup;
}

boolean m_is_dropoff(Map m, ProgressList pl, Building building) {
  LinkedList l = pl;
  boolean isPickup = false;

  while (l && !isPickup) {
    if (b_is_equal(l->payload.pickUp, building)) {
      isPickup = true;
    } else {
      l = l->next;
    }
  }

  return isPickup;
}
