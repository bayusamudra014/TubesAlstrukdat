#ifndef H_POINT
#define H_POINT

#include "../lib.h"

typedef struct point {
  int x;
  int y;
} Point;

/* Konstruktor Point */
/* Membuat Point dengan koponen di dalamnya */
void p_create_point(Point* titik, int x, int y);

/* Selektor */
#define p_getX(p) (p).x
#define p_getY(p) (p).y

/**
 * Return true jika 
 * x dan y dari P1 dan P2 sama
 */
boolean p_is_equal(Point P1, Point P2);
#endif