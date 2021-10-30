#include <stdio.h>
#include "../structure.h"


LlEltype CreateOrder(){

  Time incomingTime;
  LlEltype order;
  char label1;
  char label2;

  scanf("%d %c %c", &incomingTime, &label1, &label2);

  int orderID = 1;
  Item item;
  item.expired = 9;
  item.itemID = 10;
  item.type = 'N';

  Building PickUp;
  PickUp.label = label1 ;
  PickUp.position.x = 1;
  PickUp.position.y = 2; 

  Building DropOff;
  DropOff.label = label2 ;
  DropOff.position.x = 4;
  DropOff.position.y = 5;

  order.dropOff = DropOff;
  order.pickUp = PickUp;
  order.item = item;
  order.orderID = orderID;
  order.incomingTime = incomingTime;

  return order;

}

int main (){

    LinkedList l1;
    LlEltype order;
    int maksimum;
    int pos1;
    int N;


    ll_create_list(&l1);
    
    printf("Masukkan jumlah elm : \n");
    scanf("%d", &N);
    printf("\n");
    
    printf("Masukkan elemen list : \n");
    for(int i = 0; i < N; i++){
        
        order = CreateOrder();
        
        ll_insert_last(&l1, order);
    }

    ll_display_list(l1);
    printf("\n");


    return 0;
}