#ifndef H_CHAR_MACHINE
#define H_CHAR_MACHINE

#include <stdio.h>

#include "../lib.h"

#define STREAM_STDIN stdin
#define STREAM_CONSOLE stdin
#define CHAR_WHITESPACE "\x9\xa\xb\xc\xd\x20\x85\xa0"
#define CHAR_LINEBREAK "\xa\xb\xc\xd\x85"

#define SOURCE_FILE 0
#define SOURCE_STRING 1

typedef char BufferSource;

/* Char Engine State */
extern char cm_current_char;
extern boolean cm_eot;

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.

   Stream adalah sumber pita karakter yang akan dibaca, bisa berupa aliran data
   file, stdin, atau byte buffer. Pastikan stream sudah terbuka.

   I.S. : end char dainjurkan sudah diatur.

   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
void cm_start(void* stream);

/* Mengatur Karakter EOT. Karakter EOT boleh lebih dari satu.

   I.S. Sembarang
   F.S. endChar didefinisikan. */
void cm_set_end_char(char* endchar, int length);

/* Pita dimajukan satu karakter.

   I.S. : Karakter pada jendela = currentChar, currentChar != salah satu dari
  end char

   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = salah satu dari end char

          Jika  currentChar = salah satu dari end char maka EOP akan menyala
  (true)
*/
void cm_adv();

/* Mengatur behavior mesin kata saat mencapai EOT. Secara default, mesin kata
   akan menutup stream file.

   Bila autoclose diset true, mesin kata akan menutup setelah mencapai EOT.

   NOTE: Hanya memberikan efek bila menggunakan sumber SOURCE_FILE
 */
void cm_set_autoclose(boolean autoclose);

/* Mengatur sumber buffer yang akan dibaca.

   Nilai yang diekspektasikan adalah
   - SOURCE_FILE, jika sumber dari file
   - SOURCE_STRING, jika buffer adalah bytes of string

   Nilai default sumber buffer: SOURCE_FILE
*/
void cm_set_source(BufferSource src);

#endif