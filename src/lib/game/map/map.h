#ifndef H_MAP
#define H_MAP

#include "../../lib.h"

typedef struct map{
    DynamicList buildinglist;
    DynamicList reachable;
    Matrix adj;
    char loc[22][32];
    int row;
    int col;
} Map;

typedef Matrix adj;

#define Row(M) (M).row
#define Col(M) (M).col
#define loc(M,i) (M).buildinglist.buffer[(i)]
#define loc_elmt(M,i) (M).buildinglist.buffer[(i)].label
#define loc_type(M,i) (M).buildinglist.buffer[(i)].tipe
#define map_elmt(M,i,j) (M).loc[(i)][(j)]
#define reachable(M) (M).reachable
#define loc_nEff(M) (M).buildinglist.nEff
#define reach_nEff(M) (M).reachable.nEff
#define adj_elmt(M,i,j) (M).adj[(i)][(j)]
#define m_elmt_x(M,i) (M).buildinglist.buffer[(i)].position.x
#define m_elmt_y(M,i) (M).buildinglist.buffer[(i)].position.y



/*I.S. Sembarang
 *F.S. Map teralokasi dengan ukuran row dan col */
void m_allocate(Map *m,int row, int col, DynamicList bl);

/*I.S. ada building yang akan diassign dan map terdefinisi
 *F.S. building sudah terassign */
void m_assign(Map *m);
/* mengembalikan indeks bangunan di list bangunan */
int m_get_idx(Map m, char b);

/*I.S. Map sudah teralokasi
 *F.S. Map tercetak ke layar */
void m_display(Map m);

/*I.S. Map sudah teralokasi
 *F.S. lokasi yang terjangkau tercetak ke layar */
void m_display_reachable(Map m);

void m_clear_reachable(Map *m);

#endif