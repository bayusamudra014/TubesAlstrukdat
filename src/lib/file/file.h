#ifndef H_FILE
#define H_FILE

#include "../boolean.h"

/* Membaca file yang berada di path
  
  I.S. File harus tersedia dan memiliki akses untuk membaca
  F.S. Sebanyak size byte akan dibaca dari file lalu disimpan di buffer.

  Proses pembacaan menggunakan mesin kata.
*/
void f_read_file(const char* path, char* buffer, int size);

/* Menulis file pada path.

   I.S. Path harus writeable
   F.S. Sebanyak size byte dari buffer akan ditulis ke file.

*/
void f_write_file(const char* path, const char* buffer, int size);

/* Mengembalikan true bila file path tersedia */
boolean f_exist(const char* path); 

/* Mengembalikan true bila path writeable */
boolean f_writeable(const char* path);

/* Mengembalikan true bila path bisa ditulis */
boolean f_readable(const char* path);

/* Mengembalikan true bila path merupakan file */
boolean f_is_file(const char* path);
#endif