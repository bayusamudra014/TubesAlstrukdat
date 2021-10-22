#ifndef H_WORD_MACHINE
#define H_WORD_MACHINE

#include "../lib.h"
#include <stdio.h>

#define WORD_MACHINE_CAPACITY 200
#define WORD_MACHINE_BLANK ' '

typedef struct {
   int length;
   char contents[WORD_MACHINE_CAPACITY]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
} Word;

/* Word Engine State */
extern boolean wm_end_word;
extern Word wm_current_word;

/* Mengabaikan satu atau beberapa BLANK

   I.S. : currentChar sembarang 

   F.S. : currentChar ≠ BLANK atau currentChar = salah satu mark */
void wm_ignore_blank();

/* Mempersiapkan mesin kata.
   
   Stream adalah sumber dari pita karakter yang akan dibaca.

   I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = salah satu mark; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void wm_start_word(FILE* stream);

/* Melakukan proses akuisisi Kata selanjutnya

   I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi

   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		 

   Proses : Akuisisi kata menggunakan procedure copyWord */
void wm_adv_word();

/* Mengakuisisi kata, menyimpan dalam currentWord

   I.S. : currentChar adalah karakter pertama dari kata

   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
void wm_copy_word();

#endif