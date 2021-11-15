#ifndef H_BUILDING
#define H_BUILDING

#include "../../../boolean.h"
#include "point/point.h"

typedef struct building {
  Point position;
  char label;
  char tipe;
} Building;

#define label(b) (b).label
#define Absis(b) (b).position.x
#define Ordinat(b) (b).position.y

/**
 * Dibuat untuk testing point dan dynamic list
 *
 * Membuat Building dengan koordinat x, y dan
 * memiliki label lab
 */
void b_create_building(Building* B, int x, int y, char lab, char jenis);

/**
 * Diperlukan di fungsi dl_index_of
 *
 * Menghasilkan true jika Koordinat dan
 * Label kedua building sama
 */
boolean b_is_equal(Building B1, Building B2);

void b_display(Building B);

#endif