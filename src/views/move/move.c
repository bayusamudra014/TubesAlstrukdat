#include "move.h"

void move(StatusGame *s,int mv, boolean gadget_used, boolean bring_heavy){
    Map m = s->peta_game;
    if (gadget_used = false){
        if (mv <= dl_length(reachable(m))){
            s->posisi_sekarang = dl_elmt(reachable(m), mv-1);
            if (bring_heavy){
                s->Waktu_Permainan += 1;
            }
            else{
                s->Waktu_Permainan += 2;
            }
        }
        else{
            printf("Lokasi tidak terjangkau");
        }
    }
    else{
        if (mv <= dl_length(m.buildinglist)){
            s->posisi_sekarang = dl_elmt(m.buildinglist, mv-1);
            if (bring_heavy){
                s->Waktu_Permainan += 1;
            }
            else{
                s->Waktu_Permainan += 2;
            }
        }
        else{
            printf("Lokasi tidak ada");
        }
    }
}

void move_boost(StatusGame *s,int mv, int curr_move){
    Map m = s->peta_game;
    if (mv <= dl_length(reachable(m))){
        s->posisi_sekarang = dl_elmt(reachable(m), mv-1);
        if (curr_move % 2 == 0){
            s->Waktu_Permainan += 1;
        }
    }
}