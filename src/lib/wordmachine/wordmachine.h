#ifndef H_WORD_MACHINE
#define H_WORD_MACHINE

#include <stdio.h>

#include "../lib.h"

#define WM_INIT_CAPACITY 50
#define WM_SIZE_MAX_FACTOR 0.85
#define WM_SIZE_MIN_FACTOR 0.25
#define WM_SIZE_EXPAND 2
#define WM_SIZE_SHRINK 0.75

typedef struct word {
  char* contents;
  int length;
  int capacity;
} Word;

/* Word Engine End State */
extern boolean wm_end_word;

/* Word Engine current Word */
extern Word wm_current_word;

/* Mempersiapkan mesin kata.

   Stream adalah sumber dari pita karakter yang akan dibaca.

   I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = salah satu mark;
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void wm_start_word(FILE* stream);

/* Melakukan proses akuisisi Kata selanjutnya

   I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi

   F.S. : currentWord adalah kata yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = false, kecuali sudah melakukan
   akuisisi lagi. */
void wm_adv_word();

/* Mengatur blank dari mesin kata

   Default : blank diset sebagai " " (Spasi)

   I.S. Mesin kata belum dijalankan.
        Blank tidak boleh termasuk karakter-karakter eot.

   F.S. Blank dari mesin kata diset */
void wm_set_blank(char* blank, int length);

#endif