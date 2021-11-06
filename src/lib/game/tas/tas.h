#ifndef H_TAS
#define H_TAS

#include "../game.h"

typedef struct tas {
    Stack isiTas;
    int capacity;
} Tas;

#define t_cap(s) (s).capacity
#define t_isi(s) (s).isiTas

/**
 * I.S. Tas belum didefinisikan
 * F.S. Tas.capacity = 3,
 *      Stack isiTas kosong.
 */
void t_create_tas(Tas* T);

/**
 * I.S. Tas terdefenisi
 * F.S. capacity tas + cap_inc
 *      Kalau tas + cap_inc > 100, 
 *      capacitynya jadi 100
 */
void t_increase_capacity(Tas* T, int cap_inc);

/**
 * I.S. Tas terdefenisi
 * F.S. buffer isiTas bertambah item baru
 */
void t_add_item(Tas* T, Item item);

boolean t_is_empty(Tas T);
/**
 * Fungsi take item
 *
 * Dari tas yang tidak kosong, mengambil
 * item teratas kemudian me-return-nya.
 *
 * Tasnya tidak kosong.
 */
Item t_take_item(Tas* T);
#endif
