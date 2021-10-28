#ifndef H_BUILDING
#define H_BUILDING

#include "../lib.h"

typedef struct building {
  Point position;
  char label;
} Building;

/**
 * Dibuat untuk testing point dan dynamic list
 * 
 * Membuat Building dengan koordinat x, y dan
 * memiliki label lab
 */
void b_create_building(Building* B, int x, int y, char lab);

/**
 * Diperlukan di fungsi dl_index_of
 * 
 * Menghasilkan true jika Koordinat dan
 * Label kedua building sama
 */
boolean b_is_equal(Building B1, Building B2);

#endif