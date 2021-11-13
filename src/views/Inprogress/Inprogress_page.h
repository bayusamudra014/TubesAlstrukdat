#ifndef H_PROGRESS_VIEWS
#define H_PROGRESS_VIEWS

#include "../views.h"

void show_progress(StatusGame s_status_game);
void progress_dropoff(StatusGame *s_status_game);
void progress_pickUp(StatusGame *s_status_game, Order order);
#endif