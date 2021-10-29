#include "stdio.h"
#include "../structure.h"


SEltype CreateItem(){

    SEltype item;

    int ItemID;
    int Expired;
    char type;

    scanf("%d %d %c", &ItemID, &Expired, &type);

    item.itemID = ItemID;
    item.expired = Expired;
    item.type = type;

    return item;
}


int main(){

    Stack Tas;
    SEltype Isi;
    boolean penuh;
    
    int N;
    
    s_create_stack(&Tas);
    
    printf("Masukkan jumlah item (maksimal 3) : \n");
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        Isi = CreateItem();
        s_push(&Tas, Isi);
    }

    printf("\n");
    printf("Ini adalah isi tas Mobita : \n");

    int id;
    int expired;
    char type;

    for (int i = S_IDX_TOP(Tas); i >= 0 ;i--){
        
        id = Tas.buffer[i].itemID;
        expired = Tas.buffer[i].expired;
        type = Tas.buffer[i].type;

        printf("%d. itemID : %d , itemExpired : %d, TypeItem : %c", ((S_IDX_TOP(Tas)-i)+1), id, expired, type);
        printf("\n");
    }
    
    printf("\n");
    SEltype top;
    printf("Item teratas dari Tas Mobita adalah : \n");
    top = s_get_top(Tas); 
    printf("itemID : %d , itemExpired : %d, TypeItem : %c", top.itemID, top.expired, top.type);
    printf("\n");

    printf("\n");
    printf("Status Isi Tas Mobita\n");

    if (s_is_empty(Tas)){
        printf("Tas Mobita Kosong\n");
    }else if(s_is_full(Tas)){
        printf("Tas Mobita penuh\n");
    }else{
        printf("Tas Mobita masih memiliki ruang penyimpanan\n");
    }

    printf("\n");
    
    SEltype item;
    printf("Isi Tas Mobita setelah berhasil melakukan satu kali pengiriman\n");
    s_pop(&Tas, &item);
    for (int i = S_IDX_TOP(Tas); i >= 0 ;i--){
        
        id = Tas.buffer[i].itemID;
        expired = Tas.buffer[i].expired;
        type = Tas.buffer[i].type;

        printf("%d. itemID : %d , itemExpired : %d, TypeItem : %c", ((S_IDX_TOP(Tas)-i)+1), id, expired, type);
        printf("\n");
    }



    return 0;
}