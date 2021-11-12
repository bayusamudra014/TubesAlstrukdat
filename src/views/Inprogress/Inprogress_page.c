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