#ifndef H_PROGRESS_LIST
#define H_PROGRESS_LIST

#include "game.h"

typedef LinkedList ProgressList;
 
typedef struct daftar {

    Order order;

}Daftar;


void p_create_progress(ProgressList *pl);
void p_display_progress(ProgressList pl);







#endif