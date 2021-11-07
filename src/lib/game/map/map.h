#ifndef H_MAP
#define H_MAP

#include "../game.h"

typedef Matrix Map;


/*I.S. Sembarang
 *F.S. Map teralokasi dengan ukuran row dan col */
void m_allocate(Map *m,int row, int col);

/* Mengembalikan true apabila indeks map efektif */
boolean m_is_eff(Map m, int x, int y);

/*I.S. Map sudah teralokasi
 *F.S. Map tercetak ke layar */
void m_display(Map m);

/*I.S. ada building yang akan diassign dan map terdefinisi
 *F.S. building sudah terassign
void m_assign(Map *m, building b);
*/

#endif