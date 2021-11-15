#include <stdio.h>
#include <stdlib.h>
#include "gadget.h"

void g_set_gadget(Gadget *gadget, int type){
    
    if (type == 1){
        gadget->gadgetID = 1;
        gadget->label = 'K';
        gadget->price = 800;
    }
    else if (type == 2){
        gadget->gadgetID = 2;
        gadget->label = 'S';
        gadget->price = 1200;
    }
    else if (type == 3){
        gadget->gadgetID = 3;
        gadget->label = 'P';
        gadget->price = 1500;
    }
    else if (type == 4){
        gadget->gadgetID = 4;
        gadget->label = 'M';
        gadget->price = 3000;
    }
}

void change_state(int type, StatusGame *s, int mv){
    if (type == 1){
    
    }
    else if (type == 2){
        t_increase_capacity(&s->tas_mobita, t_cap(s->tas_mobita));
    }
    else if (type == 3){
        move(*s, mv, true, false);
    }
    else if (type == 4){
        int tm = s->Waktu_Permainan;
        if (s < 50){
            s = 0;
        }
        else{
            s -= 50;
        }
    }
}

