#include "../views.h"

/* I.S. s, m terdefinisi, mv positif
   F.S. lokasi pemain pada status game berpindah sesuai dengan pilihan mv */

void move(StatusGame *s, int mv, boolean gadget_used, boolean bring_heavy);

void move_boost(StatusGame *s, int mv, int curr_move );

void show_move(StatusGame *s);