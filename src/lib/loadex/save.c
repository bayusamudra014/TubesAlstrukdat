#include "loadex.h"
static FILE *saveFile;
// Save to file

void lx_saveToFile(char saveFilename[])
{
    printf("MEMULAI SAVE......");
    Order order;
    Item item;
    saveFile = fopen(saveFilename, "w");
    // Output map size
    fprintf(saveFile, "MAP");
    lx_wNl();
    lx_wNum(Row(SG_MAP(s_status_game)));
    lx_wSpace();
    lx_wNum(Col(SG_MAP(s_status_game)));
    lx_wNl();
    // printf("MAP\n");
    // printf("%d %d\n", Row(SG_MAP(s_status_game)),Col(SG_MAP(s_status_game)));

    // Write Building List
    fprintf(saveFile, "BLD");
    lx_wNl();
    int buildingN = loc_nEff(SG_MAP(s_status_game)) - 1;
    lx_wNum(buildingN);
    lx_wNl();
    // printf("BLD\n");
    // printf("%d\n",buildingN);

    //Write HQ coordinate
    Building HQ;
    HQ = loc(SG_MAP(s_status_game), 0);
    lx_wNum(Absis(HQ));
    lx_wSpace();
    lx_wNum(Ordinat(HQ));
    lx_wNl();

    // printf("%d %d\n",Absis(HQ),Ordinat(HQ));

    //Write all Building
    for (int i = 1; i <= buildingN; i++)
    {
        Building spot;
        spot = loc(SG_MAP(s_status_game), i);
        fprintf(saveFile, "%c", label(spot));
        lx_wSpace();
        lx_wNum(Absis(spot));
        lx_wSpace();
        lx_wNum(Ordinat(spot));
        lx_wSpace();
        fprintf(saveFile, "%c", spot.tipe);
        lx_wNl();
        // printf("%c %d %d %c\n", label(spot),Absis(spot), Ordinat(spot), spot.tipe);
    }
    //   printf("disini\n");

    //Write Adj Matrix
    lx_wAdj(buildingN);

    //REACHABLE
    fprintf(saveFile, "REACHABLE");
    lx_wNl();
    int reachN = reach_nEff(SG_MAP(s_status_game));
    lx_wNum(reachN);
    lx_wNl();
    DynamicList reach;
    reach = reachable(SG_MAP(s_status_game));

    for (int i = 0; i < reachN; i++)
    {
        Building spot;
        spot = dl_elmt(reach, i);
        fprintf(saveFile, "%c", label(spot));
        lx_wNl();
    }

    // Posisi Nobita
    fprintf(saveFile, "CURRENT_POSITION");
    lx_wNl();

    Building spot = SG_POS(s_status_game);
    fprintf(saveFile, "%c", label(spot));
    lx_wNl();

    //Write Order list;
    fprintf(saveFile, "ORD");
    lx_wNl();
    OrderList orderL = SG_OL(s_status_game);
    int orderN = ol_order_count(orderL);
    lx_wNum(orderN);
    lx_wNl();

    for (int i = 0; i < orderN; i++)
    {
        order = ol_dequeue_order(&orderL);
        
        Time time = order.incomingTime;
        Time expTime = order.expiredTime;
        char pickUp = label(order.pickUp);
        char dropOff = label(order.dropOff);
        item = order.item;
        char i_type = item.type;
        int item_id = item.itemID;

        lx_wNum(order.orderID);
        lx_wSpace();
        lx_wNum(time);
        lx_wSpace();
        fprintf(saveFile, "%c", pickUp);
        lx_wSpace();
        fprintf(saveFile, "%c", dropOff);
        lx_wSpace();
        fprintf(saveFile, "%u", expTime);
        lx_wSpace();
        lx_wNum(item_id);
        lx_wSpace();
        fprintf(saveFile, "%c", i_type);
        
        

        if (i_type == 'P')
        {
            lx_wSpace();
            lx_wNum(item.expired);
        }
        lx_wNl();
    }

    //Waktu Sekarang
    fprintf(saveFile, "CURRENT_TIME");
    lx_wNl();
    lx_wNum(SG_TIME(s_status_game));
    lx_wNl();

    //Uang Sekarang
    fprintf(saveFile, "CURRENT_MONEY");
    lx_wNl();
    lx_wNum(SG_MONEY(s_status_game));
    lx_wNl();

    //BACK TO SENDER
    fprintf(saveFile, "BACK_TO_SENDER");
    lx_wNl();
    lx_wNum(SG_S_BTS(s_status_game));
    lx_wNl();

    

    //GADGET MOBITA
    fprintf(saveFile, "INVENTORY_GADGET");
    lx_wNl();
    inventory_gadget ig = SG_IG(s_status_game);
    lx_wNum(sl_length(ig));
    lx_wNl();
    // printf("ini di Save %d\n",sl_length(ig));
    // if (sl_length(ig) == 0)
    //     lx_wNl();
    for (int i = 0; i < sl_length(ig); i++)
    {
        Gadget gadget = sl_elmt(ig, i);
        lx_wNum(gadget.gadgetID);
        lx_wSpace();
        fprintf(saveFile, "%c", gadget.label);
        lx_wSpace();
        lx_wNum(gadget.price);
        lx_wNl();
    }

    //TAS
    fprintf(saveFile, "TAS_MOBITA");
    lx_wNl();
    Tas tas = SG_TAS(s_status_game);
    int tasN = t_cap(tas);
    lx_wNum(tasN);
    lx_wNl();
    Stack isi_tas = t_isi(tas);
    int tasNeff= 0;
    while (!s_is_empty(isi_tas)){
        s_pop(&isi_tas, &order);
        tasNeff++;
    }

    lx_wNum(tasNeff);
    lx_wNl();

    isi_tas = t_isi(tas);
    while (!s_is_empty(isi_tas))
    {
        s_pop(&isi_tas, &order);

        Time time = order.incomingTime;
        Time expTime = order.expiredTime;
        char pickUp = label(order.pickUp);
        char dropOff = label(order.dropOff);
        item = order.item;
        char i_type = item.type;
        int item_id = item.itemID;

        lx_wNum(order.orderID);
        lx_wSpace();
        lx_wNum(time);
        lx_wSpace();
        fprintf(saveFile, "%c", pickUp);
        lx_wSpace();
        fprintf(saveFile, "%c", dropOff);
        lx_wSpace();
        fprintf(saveFile, "%u", expTime);
        lx_wSpace();
        lx_wNum(item_id);
        lx_wSpace();
        fprintf(saveFile, "%c", i_type);

        if (i_type == 'P')
        {

            lx_wSpace();
            lx_wNum(item.expired);
        }
        lx_wNl();
    }

    //To Do List
    fprintf(saveFile, "TO_DO_LIST");
    lx_wNl();
    ToDoList tdList = SG_TDL(s_status_game);
    int tdlN = td_length(tdList);
    lx_wNum(tdlN);
    lx_wNl();
    while (!(td_is_empty(tdList)))
    {

        ll_delete_first(&tdList, &order);
        Time time = order.incomingTime;
        Time expTime = order.expiredTime;
        char pickUp = label(order.pickUp);
        char dropOff = label(order.dropOff);
        item = order.item;
        char i_type = item.type;
        int item_id = item.itemID;

        lx_wNum(order.orderID);
        lx_wSpace();
        lx_wNum(time);
        lx_wSpace();
        fprintf(saveFile, "%c", pickUp);
        lx_wSpace();
        fprintf(saveFile, "%c", dropOff);
        lx_wSpace();
        fprintf(saveFile, "%u", expTime);
        lx_wSpace();
        lx_wNum(item_id);
        lx_wSpace();
        fprintf(saveFile, "%c", i_type);

        if (i_type == 'P')
        {

            lx_wSpace();
            lx_wNum(item.expired);
        }
        lx_wNl();
    }

    //Progress List
    fprintf(saveFile, "PROGRESS_LIST");
    lx_wNl();
    ProgressList pgList = SG_PL(s_status_game);
    int pglN = (pl_length(pgList));
    lx_wNum(pglN);
    lx_wNl();
    while (!(pl_is_empty(pgList)))
    {
        
        pl_delete_first(&pgList, &order);
        Time time = order.incomingTime;
        Time expTime = order.expiredTime;
        char pickUp = label(order.pickUp);
        char dropOff = label(order.dropOff);
        item = order.item;
        char i_type = item.type;
        int item_id = item.itemID;

        lx_wNum(order.orderID);
        lx_wSpace();
        lx_wNum(time);
        lx_wSpace();
        fprintf(saveFile, "%c", pickUp);
        lx_wSpace();
        fprintf(saveFile, "%c", dropOff);
        lx_wSpace();
        fprintf(saveFile, "%u", expTime);
        lx_wSpace();
        lx_wNum(item_id);
        lx_wSpace();
        fprintf(saveFile, "%c", i_type);


        if (i_type == 'P')
        {

            lx_wSpace();
            lx_wNum(item.expired);
        }
        lx_wNl();
    }

    fclose(saveFile);
}

void lx_wNum(int x)
{
    if (x < 10)
    {
        fprintf(saveFile, "0%d", x);
    }
    else
    {
        fprintf(saveFile, "%d", x);
    }
}

void lx_wNl()
{
    fprintf(saveFile, "\n");
}

void lx_wSpace()
{
    fprintf(saveFile, " ");
}

void lx_wAdj(int buildingN)
{
    Matrix adj = SG_MAP(s_status_game).adj;
    for (int i = 0; i <= buildingN; i++)
    {
        for (int j = 0; j <= buildingN; j++)
        {
            fprintf(saveFile, "%d", m_elmt(adj, i, j));
            if (j != buildingN)
            {
                fprintf(saveFile, " ");
            }
            else
            {
                fprintf(saveFile, "\n");
            }
        }
    }
}
