#include "./load_save_page.h"
#include <stdio.h>
#include <string.h>

void show_save_game()
{
    printf("\n");
    char *saveFilePath = __ask_input("Path to save file: ");
    lx_saveToFile(saveFilePath);
}

void show_load_game()
{
    printf("\n");
    char *saveFilePath = __ask_input("Path to save file: ");

    lx_loadSaveFile(saveFilePath);
}
