/* File: mesin.c */
/* mesin.h implementation */

#include "mesin.h"
#include <stdio.h>

static char configFilename[] = "config.conf";
static char savefileFilename[] = "savefile.dat";

static FILE * savefile;

// Advances until CC is not blank
void ignoreBlank()
{
    // While not blank
    while (CC != EOF && (CC == ' ' || CC == '\n')) ADV();
}

// Advances until CC is not blank
void ignoreBlankSTDIN()
{
    // While not blank
    while (CC != EOF && CC == ' ' ) ADVSTDIN();
}

// readNumber parses input to be an integer
int readNumber()
{
    int n = 0;
    
    ignoreBlank();
    while (!EOP && CC != EOF && CC != ' ' && CC != '\n') {
        n = n*10 + (CC-'0');
        ADV();
    }

    return n;
}

// readSTDIN will input from STDIN and convert it to ADT Word
void readSTDIN(word *input)
{
    STARTSTDIN();
    ignoreBlankSTDIN();

    // Initialize word
    (*input).length = 0;

    while(!EOP && CC!='\n')
    {
        (*input).wordArray[(*input).length] = CC;
        ++(*input).length;
        ADVSTDIN();
    }
}
// readNumberSTDIN returns number from STDIN input
void readNumberSTDIN(int *X)
{
    STARTSTDIN();
    *X = 0;
    while(!EOP && CC!='\n')
    {
        int tmp = CC - '0';
        *X = (*X)*10 + tmp; 
        ADVSTDIN(); 
    }
}


// readConfigFile will read config file and make the structure
void readConfigFile(matrix *M, buildingsArray *arr, graph *G, int * buildingCounter)
{
    // Start reading config file
    START(configFilename);
    ignoreBlank();

    // Read map size
    ignoreBlank();
    int row = readNumber();
    ignoreBlank();
    int col = readNumber();
    colorPrint("Map size: ", GREEN);
    printf(CYAN);
    printf("%dx%d\n", row, col);
    printf(NORMAL);
    
    // Initialize matrix
    createEmptyMatrix(row,col,M);

    // Read building count
    ignoreBlank();
    int t = readNumber();
    *buildingCounter = t;
    colorPrint("Building count: ", GREEN);
    printf(CYAN);
    printf("%d\n", t);
    printf(NORMAL);


    printf("Reading building states...\n");

    // Initialize array size
    makeEmptyArray(arr,t);

    for(int i=1;i<=t;i++)
    {
        // Read building type
        ignoreBlank();
        char buildingType = CC;
        ADV();

        // Construct buildings
        addressBuildings ptr = allocateBuilding();

        if(buildingType=='C')  makeCastle(ptr,0);
        else if(buildingType=='T') makeTower(ptr, 0);
        else if(buildingType=='F') makeFort(ptr, 0);
        else if(buildingType=='V') makeVillage(ptr, 0);

        // Read building coordinate
        ignoreBlank();
        int buildingRow = readNumber();
        ignoreBlank();
        int buildingCol = readNumber();
        
        // Construct and send to array
        Elmt(*arr, i) = makeBuildingCoord(ptr, buildingRow, buildingCol);
        Neff(*arr)++;
        insertStructure(M, Elmt(*arr,i));
        
    }

    printf("Building graph...\n");
    // Initialize graph
    createGraph(G,t);

    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=t;j++)
        {
            ignoreBlank();
            int connection = readNumber();
            if(connection) insertChild(G,i,j);
        }
    }
    const char* completeMessage = "Configuration file loaded!\n";
    colorPrint(completeMessage,GREEN);
    // printGraph(*G);
}

// Save to file
void saveToFile(matrix *M, buildingsArray *arr, graph *G, int turn, boolean ignore, boolean critical, boolean extraTurn, queue *Q1, queue *Q2, boolean criticalP1, boolean criticalP2, boolean isShieldActiveP1, boolean shieldActivatedP1, boolean isShieldActiveP2, boolean shieldActivatedP2, int counterShieldP1, int counterShieldP2, int lengthFlagAttack, int lengthFlagMove, int * arrFlagAttack, int * arrFlagMove)
{
    colorPrint("Saving to ", NORMAL);
    colorPrint("savefile.dat", UNDERSCORE);
    colorPrint("...", NORMAL);
    
    savefile = fopen(savefileFilename, "w");
    // Output map size
    fprintf(savefile,"%d %d\n", nRowEff(*M)-1, nColEff(*M)-1);

    // Output building count
    int t=MaxEl(*arr);
    fprintf(savefile,"%d\n", t);

    // Output all bulding with its state
    // Format : type rb cb owner level troops defense
    for(int i=1;i<=t;i++)
    {
        char type;
        if(type(*build(*Elmt(*arr,i)))==1) type='C';
        else if(type(*build(*Elmt(*arr,i)))==2) type='T';
        else if(type(*build(*Elmt(*arr,i)))==3) type='F';
        else if(type(*build(*Elmt(*arr,i)))==4) type='V';

        fprintf(savefile, "%c %d %d %d %d %d %d\n", type, row(*Elmt(*arr,i)), col(*Elmt(*arr,i)), owner(*build(*Elmt(*arr,i))), level(*build(*Elmt(*arr,i))), troops(*build(*Elmt(*arr,i))), defense(*build(*Elmt(*arr,i))));
    }

    // Output graph representation in adjacency list form
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=t;j++) fprintf(savefile, "%d ", isConnected(*G, i, j) ? 1 : 0);
        fprintf(savefile,"\n");
    }

    // Output for whose turn it is
    fprintf(savefile, "%d\n", turn);
    // Output ignore defense state
    fprintf(savefile, "%d\n", ignore);
    // Output ignore critical state
    fprintf(savefile, "%d\n", ignore);
    // Output extra turn state
    fprintf(savefile, "%d\n", extraTurn);
    // Output criticalP1
    fprintf(savefile, "%d\n", criticalP1);
    // Output criticalP2
    fprintf(savefile, "%d\n", criticalP2);
    // Output isShieldActiveP1
    fprintf(savefile, "%d\n", isShieldActiveP1);
    // Output shieldActivatedP1
    fprintf(savefile, "%d\n", shieldActivatedP1); 
    // Output isShieldActiveP2
    fprintf(savefile, "%d\n", isShieldActiveP2);
    // Output shieldActivatedP2
    fprintf(savefile, "%d\n", shieldActivatedP2);
    // Output counterShieldP1
    fprintf(savefile, "%d\n", counterShieldP1);
    // Output counterShieldP2
    fprintf(savefile, "%d\n", counterShieldP2);
    // Output skill queue for player 1
    if(isEmptyQueue(*Q1)) for(int i=1;i<=10;i++) fprintf(savefile,"0 ");
    else
    {
        int count=0;
        for(int i=Head(*Q1);count<10;i=(i%10)+1) {
            if((*Q1).T[i] == 1 || (*Q1).T[i] == 2 || (*Q1).T[i] == 3 || (*Q1).T[i] == 4 || (*Q1).T[i] == 5 || (*Q1).T[i] == 6 || (*Q1).T[i] == 7){
                fprintf(savefile, "%d ", (*Q1).T[i]);
            }
            else{
                fprintf(savefile, "0 ");
            }
            ++count;
        }
    }
    fprintf(savefile, "\n");
    
    // Output skill queue for player 2
    if(isEmptyQueue(*Q2)) for(int i=1;i<=10;i++) fprintf(savefile,"0 ");
    else
    {
        int count=0;
        for(int i=Head(*Q2);count<10;i=(i%10)+1) {
            if((*Q2).T[i] == 1 || (*Q2).T[i] == 2 || (*Q2).T[i] == 3 || (*Q2).T[i] == 4 || (*Q2).T[i] == 5 || (*Q2).T[i] == 6 || (*Q2).T[i] == 7){
                fprintf(savefile, "%d ", (*Q1).T[i]);
            }
            else{
                fprintf(savefile, "0 ");
            }
            ++count;
        }
    }
    fprintf(savefile, "\n");
    // Output buildings inside flagAttack
    fprintf(savefile, "%d\n", lengthFlagAttack);
    // Output flagAttack
    for(int i = 1; i <= lengthFlagAttack; i++){
        fprintf(savefile, "%d ", arrFlagAttack[i]);
    }
    fprintf(savefile, "\n");
    //Output buildings inside flagMove
    fprintf(savefile, "%d\n", lengthFlagMove);
    // Output flagMove
    for(int i = 1; i <= lengthFlagMove; i++){
        fprintf(savefile, "%d ", arrFlagMove[i]);
    }
    fprintf(savefile, "\n");
    // Close stream
    fclose(savefile);
}

// Load from file
void loadFromFile(matrix *M, buildingsArray *arr, graph *G, int *turn, boolean *ignore, boolean *critical, boolean *extraTurn, queue *Q1, queue *Q2, int *buildingCounter, boolean *criticalP1, boolean *criticalP2, boolean *isShieldActiveP1, boolean *shieldActivatedP1, boolean *isShieldActiveP2, boolean *shieldActivatedP2, int *counterShieldP1, int *counterShieldP2, int * lengthFlagAttack_, int * lengthFlagMove_, int ** arrFlagAttack, int ** arrFlagMove)
{
    // Start reading filename
    START(savefileFilename);
    ignoreBlank();

    // Read map size
    ignoreBlank();
    int row = readNumber();
    ignoreBlank();
    int col = readNumber();

    // Initialize matrix
    createEmptyMatrix(row,col,M);

    // Read building count
    ignoreBlank();
    int t = readNumber();
    *buildingCounter = t;

    colorPrint("Map size: ", BRIGHT);
    printf("%dx%d\n", row, col);
    colorPrint("Building count: ", BRIGHT);
    printf("%d\n", t);

    colorPrint("Reading building states...\n", BRIGHT);

    // Initialize array size
    makeEmptyArray(arr,t);

    for(int i=1;i<=t;i++)
    {
        // Read building type
        ignoreBlank();
        char buildingType = CC;
        ADV();

        // Construct buildings
        addressBuildings ptr = allocateBuilding();

        if(buildingType=='C')  makeCastle(ptr,0);
        else if(buildingType=='T') makeTower(ptr, 0);
        else if(buildingType=='F') makeFort(ptr, 0);
        else if(buildingType=='V') makeVillage(ptr, 0);

        // Read building coordinate
        ignoreBlank();
        int buildingRow = readNumber();
        ignoreBlank();
        int buildingCol = readNumber();
        
        //Read building owner
        ignoreBlank();
        int buildingOwner = readNumber();
        owner(*ptr) = buildingOwner;

        //Read building level
        ignoreBlank();
        int buildingLevel = readNumber();
        level(*ptr) = buildingLevel;

        //Read building troops
        ignoreBlank();
        int buildingTroops = readNumber();
        troops(*ptr) = buildingTroops;

        //Read building defense state
        ignoreBlank();
        int buildingDefense = readNumber();
        defense(*ptr) = buildingDefense;

        // Construct and send to array
        Elmt(*arr, i) = makeBuildingCoord(ptr, buildingRow, buildingCol);
        ++Neff(*arr);
        insertStructure(M, Elmt(*arr,i));
        
    }

    colorPrint("Building graph...\n", BRIGHT);
    // Initialize graph
    createGraph(G,t);

    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=t;j++)
        {
            ignoreBlank();
            int connection = readNumber();
            if(connection) insertChild(G,i,j);
        }
    }

    // Read turn state
    ignoreBlank();
    *turn = readNumber();
    // Read ignore state
    ignoreBlank();
    *ignore = readNumber();
    // Read critical state
    ignoreBlank();
    *critical = readNumber();
    // Read extra turn state
    ignoreBlank();
    *extraTurn = readNumber();
    // Read critical P1
    *criticalP1 = readNumber();
    // Read critical P2
    *criticalP2 = readNumber();
    // Read isShieldActiveP1
    *isShieldActiveP1 = readNumber();
    // Read shieldActivatedP1
    *shieldActivatedP1 = readNumber();
    // Read isShieldActiveP2
    *isShieldActiveP2 = readNumber();
    // Read shieldActivatedP2
    *shieldActivatedP2 = readNumber();
    // Read counterShieldP1
    *counterShieldP1 = readNumber();
    // Read counterShieldP2
    *counterShieldP2 = readNumber();

    // Input to queue
    int tempHead = unDef;
    int tempTail = unDef;

    createQueue(Q1,10);
    int counter = 1;
    for(int i=1;i<=10;i++) 
    {
        ignoreBlank();
        int tempSkill1 = readNumber();
        if(tempSkill1 != 0){
            Add(Q1, tempSkill1);
            tempHead = 1;
            tempTail = counter;
            counter++;
        }
    }
    Head(*Q1) = tempHead;
    Tail(*Q1) = tempTail;

    // Input to queue
    createQueue(Q2, 10);
    counter = 0;
    for(int i=1;i<=10;i++) 
    {
        ignoreBlank();
        int tempSkill2 = readNumber();
        if(tempSkill2 != 0){
            tempHead = 1;
            tempTail = counter;
            counter++;
        }
    }
    Head(*Q2) = tempHead;
    Tail(*Q2) = tempTail;

    // Input to flagAttack
    int lengthFlagAttack = readNumber();
    *arrFlagAttack = (int *) malloc((lengthFlagAttack+1) * sizeof(int));
    for(int i = 1; i <= lengthFlagAttack; i++){
        ignoreBlank();
        (*arrFlagAttack)[i] = readNumber();
    }
    // Input to flagMove
    int lengthFlagMove = readNumber();
    *arrFlagMove = (int *) malloc((lengthFlagMove+1) * sizeof(int));
    for(int i = 1; i <= lengthFlagMove; i++){
        ignoreBlank();
        (*arrFlagMove)[i] = readNumber();
    }
    // Output
    *lengthFlagAttack_ = lengthFlagAttack;
    *lengthFlagMove_ = lengthFlagMove;
    colorPrint("Save file loaded, ready to play!\n", GREEN);
}

/* -=-=-=-=-=-=-=- FOR DEBUGGING PURPOSES -=-=-=-=-=-=-=- */

void printASCIIFile()
{
    START(configFilename);
    while(!EOP)
    {
        int n = readNumber();
        printf("%d ", n);
    }
}

// Print word
void printWord(word W)
{
    for(int i=0;i<W.length;i++) printf("%c",W.wordArray[i]);
    printf("\n");
}

int intConverter(word W){
    int result = 0;
    int temp;
    for(int i = 0; i < W.length; i++){
        temp = (int) W.wordArray[i] - '0';
        result = result * 10 + temp;
    }
    return result;
}

boolean wordCompare(word W, char * S){
    boolean result = true;
    int i;
    for(i = 0; i < W.length; i++){
        char temp = (char) W.wordArray[i];
        if(temp != S[i]){
            result = false;
        }
    }
    int a = strlen(S);
    if(W.length != a){
        result = false;
    }
    return result;
}
