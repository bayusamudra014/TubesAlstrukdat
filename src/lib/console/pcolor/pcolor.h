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

/* Foreground */
#define TEXT_NORMAL "\x1B[0m"
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

#define _RESET_COLOR TEXT_NORMAL

void print_red(char c);
void print_green(char c);
void print_yellow(char c);
void print_blue(char c);
void print_magenta(char c);
void print_cyan(char c);

void set_text_color(char* color);
void set_bg_color(char* color);
void print_color(char* color, char* string);
void reset_color();
void print_colored_char(char* color, char c);

#endif