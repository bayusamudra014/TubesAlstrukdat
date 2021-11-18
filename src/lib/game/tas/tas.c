#include "tas.h"

void t_create_tas(Tas *T) {
  s_create_stack(&(t_isi(*T)));
  t_cap(*T) = 3;
}

void t_increase_capacity(Tas *T, int cap_inc) {
  if (t_cap(*T) + cap_inc <= 100) {
    t_cap(*T) = t_cap(*T) + cap_inc;
  } else {
    t_cap(*T) = 100;
  }
}

void t_add_item(Tas *T, Order item) {
  /**
   * idx stack dimulai dari 0, jadi
   * Tas dengan capacity 3 penuh saat
   * idxTop = 2
   */
  if (!t_is_full(*T)) {
    s_push(&(t_isi(*T)), item);
  } else {
    // Do something
    printf("Tas penuh!\n");
  }
}

boolean t_is_full(Tas T) { return t_cap(T) < (S_IDX_TOP(t_isi(T)) + 1); }

boolean t_is_empty(Tas T) { return s_is_empty(t_isi(T)); }

Order t_take_item(Tas *T) {
  Order I;
  s_pop(&(t_isi(*T)), &I);
  return I;
}

int t_num_heavy(Tas T) {
  Stack isi = T.isiTas;
  int cnt = 0;

  for (int i = 0; i <= isi.idxTop; i++) {
    if (i_is_heavy(isi.buffer[i].item)) {
      cnt++;
    }
  }

  return cnt;
}