#include "../lib.h"

void p_create_point(Point * titik, int x, int y){
    p_getX(*titik) = x;
    p_getY(*titik) = y;
}

boolean p_is_equal(Point P1, Point P2){
    return (p_getX(P1) == p_getX(P2)) && (p_getY(P1) == p_getY(P2));
}