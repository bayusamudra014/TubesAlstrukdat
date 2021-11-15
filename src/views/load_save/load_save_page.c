#include "./load_save_page.h"
#include <stdio.h>
#include <string.h>

void show_save_game(StatusGame s_status_game)
{
    char file_name[50];
    scanf(" %[^\n]s",file_name);
    printf("%s", file_name);


}

void show_load_game(StatusGame *s_status_game)
{
    char file_name[50];
    scanf(" %[^\n]s",file_name);
    printf("%s", file_name);

    
}
