#include "gadget.h"

Gadget g_get_name(int type){
    if (type == 1){
        return "K";
    }
    else if (type == 2){
        return "S";
    }
    else if (type == 3){
        return "P";
    }
    else if (type == 4){
        return "M";
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

