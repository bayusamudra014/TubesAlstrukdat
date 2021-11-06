#include "gadget.h"

char g_get_name(int type){
    if (type == 1){
        return "Kain Pembungkus Waktu";
    }
    else if (type == 2){
        return "Senter Pembesar";
    }
    else if (type == 3){
        return "Pintu Kemana Saja";
    }
    else if (type == 4){
        return "Mesin Waktu";
    }
}

int g__get_price(int type){
    if (type == 1){
        return 800;
    }
    else if (type == 2){
        return 1200;
    }
    else if (type == 3){
        return 1500;
    }
    else if (type == 4){
        return 3000;
    }
}