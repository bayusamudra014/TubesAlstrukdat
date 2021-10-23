#ifndef H_POINT
#define H_POINT

#include "../lib.h"

typedef struct { 
	int x; /* absis   */
	int y; /* ordinat */
  char label;
} Point;

/* Konstruktor Point */
/* Membuat Point dengan koponen di dalamnya */
void p_create_point(Point* titik,int x, int y, char label);


/* Selektor */
#define p_getX(p) p.x
#define p_getY(p) p.y
#define p_getLabel(p) p.label

#endif