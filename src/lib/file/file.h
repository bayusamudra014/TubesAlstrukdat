#ifndef H_FILE
#define H_FILE

#include "../boolean.h"

/**
 * Menghasilkan panjang file path
 */
int f_len_file(const char *path);

/**
 * Membaca file ke array dari malloc
 *
 * Menghasilkan pointer ke array of strings. 
 * Tiap elemen merupakan baris dari file
 */
char** f_read_file_to_buffer(const char *path);

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

#endif
