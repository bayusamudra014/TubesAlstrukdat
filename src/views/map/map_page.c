#include "map_page.h"

void show_map(StatusGame s_status_game) {
  m_display(s_status_game.peta_game, SG_TDL(s_status_game),
            SG_PL(s_status_game), SG_POS(s_status_game));
}