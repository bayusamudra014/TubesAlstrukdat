#include "./to_do.h"

ToDoList td_list;

void show_to_do() {
    /* Kamus */
    int num = 1;
    struct node *p;
    Item i;
    Order o;
    /* Algoritma */


    td_list = s_status_game.to_do_list;

    if (td_is_empty(td_list)){
        printf("To do list kosong\n");
    } else {
        
        p = FIRST(td_list);
        printf("Pesanan pada To Do List:\n");
        while(p != NULL) {
            o = INFO(p);
            i = o.item;
            printf("%d. %c -> %c ", num, o.pickUp.label, o.dropOff.label, o.item.type);
            switch (i.type)
            {
            case 'N':
                printf("(Normal Item)\n");
                break;
            case 'H':
                printf("(Heavy Item)\n");
                break;
            case 'P':
                printf("(Perishable Item) (Expired time: %d)\n", i.expired);
                break;
            case 'V':
                printf("(VIP Item)\n");
                break;
            }
            num += 1;
            p = NEXT(p);
        }
    }
}