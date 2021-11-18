#include "building.h"

#include <stdio.h>

void b_create_building(Building* B, int x, int y, char lab, char jenis, int i) {
  Point P;
  p_create_point(&P, x, y);
  B->position = P;
  B->label = lab;
  B->tipe = jenis;
  B->index = i;
}

boolean b_is_equal(Building B1, Building B2) {
  return p_is_equal(B1.position, B2.position) && B1.label == B2.label;
}

void b_display(Building B) {
  printf("%c (%d,%d)\n", label(B), Absis(B), Ordinat(B));
}