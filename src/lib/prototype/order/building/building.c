#include "building.h"

void b_create_building(Building* B, int x, int y, char lab) {
  Point P;
  p_create_point(&P, x, y);
  B->position = P;
  B->label = lab;
}

boolean b_is_equal(Building B1, Building B2) {
  return p_is_equal(B1.position, B2.position) && B1.label == B2.label;
}