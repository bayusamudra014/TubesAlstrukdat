#include <stdio.h>
#include "buy_page.h"


void show_page_buy(StatusGame *s_status_game){

    Gadget gadget;
    
    printf("Uang Anda Sekarang: %d\n",s_status_game->uang_mobita);
    printf("Gadget yang tersedia: \n");
    
    printf("1. Kain Pembungkus Waktu (800 Yen)\n");
    printf("2. Senter Pembesar (1200 Yen)\n");
    printf("3. Pintu Kemana Saja (1500 Yen)\n");
    printf("4. Mesin Waktu (3000 Yen)\n");
    
    int command;
    boolean beli = false;

    do{
        printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");
        printf("\n");
        printf("ENTER COMMAND: ");
        scanf("%d",&command);
        printf("\n");

        if(command == 1){
            g_set_gadget(&gadget,command);
            if(s_status_game->uang_mobita >= gadget.price){
                printf("Kain Pembungkus Waktu berhasil dibeli!\n");
                s_status_game->uang_mobita -= gadget.price;
                printf("Uang Anda sekarang: %d Yen\n",s_status_game->uang_mobita);
                ig_add_item(&s_status_game->inventory_gadget,gadget);
                beli = true;
            }else{
                printf("Uang tidak cukup untuk membeli gadget!\n");
            }

        }else if(command == 2){
            g_set_gadget(&gadget,command);
            if(s_status_game->uang_mobita >= gadget.price){
                printf("Senter Pembesar berhasil dibeli!\n");
                s_status_game->uang_mobita -= gadget.price; 
                printf("Uang Anda sekarang: %d Yen\n",s_status_game->uang_mobita);
                ig_add_item(&s_status_game->inventory_gadget,gadget);
                beli = true;
            }else{
                printf("Uang tidak cukup untuk membeli gadget!\n");
            }

        }else if(command == 3){
            g_set_gadget(&gadget,command);
            if(s_status_game->uang_mobita >= gadget.price){
                printf("Pintu Kemana Saja berhasil dibeli!\n");
                s_status_game->uang_mobita -= gadget.price; 
                printf("Uang Anda sekarang: %d Yen\n",s_status_game->uang_mobita);
                ig_add_item(&s_status_game->inventory_gadget,gadget);
                beli = true;
            }else{
                printf("Uang tidak cukup untuk membeli gadget!\n");
            }

        }else if(command == 4){
            g_set_gadget(&gadget,command);
            if(s_status_game->uang_mobita >= gadget.price){
                printf("Mesin Waktu berhasil dibeli!\n");
                s_status_game->uang_mobita -= gadget.price; 
                printf("Uang Anda sekarang: %d Yen\n",s_status_game->uang_mobita);
                ig_add_item(&s_status_game->inventory_gadget,gadget);
                beli = true;
            }else{
                printf("Uang tidak cukup untuk membeli gadget!\n");
            }
        }
    }while(command != 0 && !beli);
}