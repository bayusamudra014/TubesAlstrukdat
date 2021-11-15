#ifndef H_PROGRESS_VIEWS
#define H_PROGRESS_VIEWS

#include "../views.h"

/*I.S. Sembarang*/
/*F.S. Menampilkan isi dari progress list ke layar*/
void show_progress(StatusGame s_status_game);



/*I.S. Sembarang*/
/*F.S. drop off order ketika sudah berada di lokasi drop off yang tepat,
melakukan delete first pada progress list kemudian mobita mendapatkan reward
sesusai dengan jenis barang*/
void progress_dropoff(StatusGame *s_status_game);



/*I.S. sembarang, progress list mungking kosong*/
/*F.S. element dari progress list bertambah, dan efek dari tiap item aktif */
void progress_pickUp(StatusGame *s_status_game, Order order);
#endif