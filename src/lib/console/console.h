/**
 * Filename: console.h
 * Description: Console related Utility
 *
 * Created by Bayu Samudra (21/10/2021)
 **/

#include "pcolor/pcolor.h"

#ifndef H_CONSOLE
#define H_CONSOLE

typedef char* Decorator;

#define DECORATOR_UNDERLINE "\x1b[4m"
#define DECORATOR_REVERSED "\x1b[7m"
#define DECORATOR_BOLD "\x1b[1m"

/* Mengatur decorator teks saat melakukan printing ke console.

   Contoh: set_decorator(DECORATOR_UNDERLINE);
*/
void set_decorator(Decorator dec);

/* Mereset decorator dan warna pada console */
void reset_decorator();

/*
  Membersihkan Console
*/
void clear_screen();

/* Membaca sebuah kata pada console.

   I.S. word sudah dialokasikan.
   F.S. Menyalin sebuah kata pertama pada console yang telah diinputkan dan
   hasilnya disalin ke dalam word dengan maksimal jumlah karakter max.
   Jika ukuran string yang diterima melebihi max, maka akan dipotong. */
void read_word(char* word, int length);

/* Membaca sebuah baris pada console.

*/
void read_line(char* word, int length);

/**
 * Membaca sebuah baris, convert ke integer
 *
 * scanf meninggalkan newline, sehingga __ask_input
 * mengira itu sebagai inputan kosong. Oleh karena itu, 
 * diganti dengan yang tidak meninggalkan newline
 */
void read_int_line(int* num, int digits);
#endif
