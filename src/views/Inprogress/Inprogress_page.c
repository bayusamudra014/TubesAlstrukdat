#include "Inprogress_page.h"
#include <stdio.h>

ProgressList progress_list;

void show_progress(StatusGame s_status_game){

    Item item;
    Order order;
    Building tujuan;
    struct node *p;
    int num = 1;
    
    progress_list = s_status_game.progress_list;

    if (pl_is_empty(progress_list)){
        printf("Tidak ada pesanan yang sedang di antarkan!");
        printf("\n");

    }else{
        p = FIRST(progress_list);
        
        printf("Pesanan yang sedang diantarkan: \n");

        while (p != NULL){
            order = INFO(p);
            item = order.item;
            tujuan = order.dropOff;
            
            printf("%d. ",num);

            switch (item.type)
            {
            case 'N':
                printf("Normal Item");
                break;
            case 'H':
                printf("Heavy Item");
                break;
            case 'P':
                printf("Perishable Item (Expired time: %d)",item.expired);
                break;
            case 'V':
                printf("VIP Item");
                break;
            }

            printf(" (Tujuan : %c)\n",tujuan.label);

            num++;
            p = NEXT(p);

        }
    }
}

void progress_dropoff(StatusGame *s_status_game){
    Order order;
    
    pl_delete_first(&s_status_game->progress_list, &order);
    
    if(order.item.type == 'P'){
        t_increase_capacity(&s_status_game->tas_mobita, 100);
        s_status_game->uang_mobita = s_status_game->uang_mobita + 400;
    }else if(order.item.type == 'H'){
        s_status_game->uang_mobita = s_status_game->uang_mobita + 400;

    }else if(order.item.type == 'N'){
        s_status_game->uang_mobita = s_status_game->uang_mobita + 200;

    }else if(order.item.type == 'V'){
        s_status_game->uang_mobita = s_status_game->uang_mobita + 600;

    }
}

void progress_pickUp(StatusGame *s_status_game, Order order){

    pl_insert_last(&s_status_game->progress_list,order);
    if(order.item.type == 'N'){

    }else if(order.item.type == 'H'){

    }else if(order.item.type == 'P'){

    }else if(order.item.type == 'V'){

    }

}