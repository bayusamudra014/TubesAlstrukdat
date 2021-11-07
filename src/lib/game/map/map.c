#include "map.h"

void alokasiMAP(Map *m,int row, int col){
    m_create_matrix(m, row, col);
    int i,j;
    for(i=0;i<ROW(*m)+2;i++){
        for(j=0;j<COL(*m)+2;j++){
            if(i==0 || i==ROW(*m)+1 || j==0 || j==COL(*m)+1){
                m_elmt(*m,i,j) = '*';
            }else{
                m_elmt(*m,i,j) = ' ';
            }
            
        }
    }
}

boolean m_is_eff(Map m, int x, int y){
    return (x > 0 && x <= m.rowEff) && ( y > 0 && y <= m.colEff);
};
/*
void m_display(Map m){
    int i,j;
    for(i=0;i<m.rowEff+2;i++){
        for(j=0;j<colEff+2;j++){
            if(m_elmt(m,i,j) != '*' && m_elmt(m,i,j) != ' '){
                if(m_elmt(m,i,j) == 'm'){
                    print_yellow(m_elmt(m,i,j));
                }else if(m_elmt(m,i,j) == 'd'){
                    print_blue(m_elmt(m,i,j));
                }else if(m_elmt(m,i,j) == 'p'){
                    print_red(m_elmt(m,i,j));
                }else if(m_elmt(m,i,j) == 'r'){
                    print_green(m_elmt(m,i,j));
                }else{
                    printf("%c",m_elmt(m,i,j));
                }
            }else{
                printf("%c",m_elmt(m,i,j));
            }
            
        }
        printf("\n");
    }
}*/