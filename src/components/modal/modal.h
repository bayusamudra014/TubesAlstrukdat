/* Komponen untuk menampilkan modal */

#ifndef H_C_MODAL
#define H_C_MODAL

#include "../../lib/console/console.h"

/* Menampilkan pesan error pada layar */
void cm_modal_error(const char* message);

/* Menampilkan pesan informasi pada layar */
void cm_modal_info(const char* message);

/* Menampilkan pesan peringatan pada layar */
void cm_modal_warning(const char* message);

#endif