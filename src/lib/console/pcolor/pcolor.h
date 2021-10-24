/**
Filename: pcolor.h
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Edited by: Bayu Samudra
Created at: 17/10/2019
**/

/**
Details

print_xxx(c) will print c with xxx color. Import this header to use the declared
functions. We only provide 8 colors. Feel free to modify/add colors if you want
to.
**/

#ifndef H_PCOLOR
#define H_PCOLOR

typedef char* Color;

#define TEXT_NORMAL "\x1B[0m"
#define __RESET_COLOR TEXT_NORMAL

/* Foreground */
#define TEXT_BLACK "\x1B[30m"
#define TEXT_RED "\x1B[31m"
#define TEXT_GREEN "\x1B[32m"
#define TEXT_YELLOW "\x1B[33m"
#define TEXT_BLUE "\x1B[34m"
#define TEXT_MAGENTA "\x1B[35m"
#define TEXT_CYAN "\x1B[36m"
#define TEXT_WHITE "\x1B[37m"

// Some of color below may not look same as color above
#define TEXT_GRAY "\x1B[90m"
#define TEXT_BRIGHT_RED "\x1B[91m"
#define TEXT_BRIGHT_GREEN "\x1B[92m"
#define TEXT_BRIGHT_YELLOW "\x1B[93m"
#define TEXT_BRIGHT_BLUE "\x1B[94m"
#define TEXT_BRIGHT_MAGENTA "\x1B[95m"
#define TEXT_BRIGHT_CYAN "\x1B[96m"
#define TEXT_BRIGHT_WHITE "\x1B[97m"

/* Background */
#define BG_BLACK "\x1B[40m"
#define BG_RED "\x1B[41m"
#define BG_GREEN "\x1B[42m"
#define BG_YELLOW "\x1B[43m"
#define BG_BLUE "\x1B[44m"
#define BG_MAGENTA "\x1B[45m"
#define BG_CYAN "\x1B[46m"
#define BG_WHITE "\x1B[47m"

#define BG_GRAY "\x1B[100m"
#define BG_BRIGHT_RED "\x1B[101m"
#define BG_BRIGHT_GREEN "\x1B[102m"
#define BG_BRIGHT_YELLOW "\x1B[103m"
#define BG_BRIGHT_BLUE "\x1B[104m"
#define BG_BRIGHT_MAGENTA "\x1B[105m"
#define BG_BRIGHT_CYAN "\x1B[106m"
#define BG_BRIGHT_WHITE "\x1B[107m"

/* Mencetak karakter berwarna merah ke layar */
void print_red(char c);

/* Mencetak karakter berwarna hijau ke layar */
void print_green(char c);

/* Mencetak karakter berwarna kuning (atau jingga) ke layar */
void print_yellow(char c);

/* Mencetak karakter berwarna biru ke layar */
void print_blue(char c);

/* Mencetak karakter berwarna magent ke layar */
void print_magenta(char c);

/* Mencetak karakter berwarna cyan ke layar */
void print_cyan(char c);

/* Prosedur ini akan mengatur warna text default saat print pada console.
   Untuk mengatur ke warna default, gunakan prosedur reset_color()

   Contoh pakai:
   set_text_color(TEXT_CYAN);
*/
void set_text_color(Color color);

/* Prosedur ini akan mengatur warna background text default saat print pada
 console. Untuk mengatur ke warna default, gunakan prosedur reset_color()

  Contoh pakai:
  set_bg_color(BG_GREEN);
*/
void set_bg_color(Color color);

/* Prosedur ini akan print text dengan warna pada console. Setelah prosedur
   ini dijalankan, warna console otomatis tereset.

  Contoh pakai:
  print_color(TEXT_BLUE, "Halo, Dunia");
*/
void print_color(Color color, const char* string);

/* Mengembalikan console ke settingan default */
void reset_color();

/* Prosedur ini akan mencetak karakter berwarna

  Contoh pakai:
  print_colored_char(TEXT_BLUE, 'H');
*/
void print_colored_char(Color color, char c);

/**
 * Membuat warna custom warna teks sesuai dengan warna rgb.
 * 
 * Pastikan melakukan dealokasi warna bila tidak digunakan lagi. Gunakan delete_warna() untuk dealokasi.
 *
 * Contoh : create_text_color(102,255,121);
 */
Color create_text_color(unsigned char r, unsigned char g, unsigned char b);

/**
 * Membuat warna custom warna background teks sesuai dengan warna rgb
 *
 * Pastikan melakukan dealokasi warna bila tidak digunakan lagi. Gunakan delete_warna() untuk dealokasi.
 * 
 * Contoh : create_bg_color(102,255,121);
 */
Color create_bg_color(unsigned char r, unsigned char g, unsigned char b);

/*
  Buat warna teks dari kode heksadesimal

  Pastikan melakukan dealokasi warna bila tidak digunakan lagi. Gunakan delete_warna() untuk dealokasi.

  Contoh : create_text_color_cd(0x6BAA75)
*/
Color create_text_color_cd(unsigned color);

/*
  Buat warna background dari kode heksadesimal

  Pastikan melakukan dealokasi warna bila tidak digunakan lagi. Gunakan delete_warna() untuk dealokasi.

  Contoh : create_bg_color_cd(0x6BAA75)
*/
Color create_bg_color_cd(unsigned color);

/*
  Melalukan dealokasi warna.

  Contoh: delete_color(warna);
*/
void delete_color(Color color);

#endif
