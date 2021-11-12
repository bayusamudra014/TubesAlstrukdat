#include "to_do_page.h"
#include <stdio.h>

ToDoList td_list;

void tdp_printOrder(Order order, int num)
{
    Item item;
    item = order.item;
    printf("%d. %c -> %c ", num, order.pickUp.label, order.dropOff.label);
    switch (item.type)
    {
    case 'N':
        printf("(Normal Item)\n");
        break;
    case 'H':
        printf("(Heavy Item)\n");
        break;
    case 'P':
        printf("(Perishable Item) (Expired time: %d)\n", item.expired);
        break;
    case 'V':
        printf("(VIP Item)\n");
        break;
    }
}

void show_to_do(StatusGame s_status_game)
{
    /* Kamus */
    // s_status_game;
    int num = 1;
    struct node *p;
    Order o;
    /* Algoritma */

    td_list = s_status_game.to_do_list;

    if (td_is_empty(td_list))
    {
        printf("To do list kosong\n");
    }
    else
    {

        p = FIRST(td_list);
        printf("Pesanan pada To Do List:\n");
        while (p != NULL)
        {
            o = INFO(p);

            tdp_printOrder(o, num);

            num += 1;
            p = NEXT(p);
        }
    }
}

