#include <stdio.h>

#include "../lib.h"


//CreateOrder dummy buat ngetest prioqueue berdasarkan waktu kedatangan
QEltype CreateOrder(){

  Time incomingTime;
  QEltype order;
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



int main() {
  
  int N;
  QEltype order;
  Queue daftarOrder;
  q_create_queue(&daftarOrder);

  printf("Masukkan jumlah order : ");
  scanf("%d", &N);
  
  printf("Masukkan order : \n");
  
  for(int i = 0; i < N; i++){
    order = CreateOrder();
    q_enqueue(&daftarOrder, order);
  }

  printf("Daftar Pesanan \n");

  for(int i = 0 ; i < q_length(daftarOrder); i++){
    printf("%d. %c -> %c (Normal Item)", (i+1), daftarOrder.buffer[i].pickUp.label, daftarOrder.buffer[i].dropOff.label);
    printf("\n");
  }


  return 0;
}