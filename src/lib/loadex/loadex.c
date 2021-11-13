#include "loadex.h"
#include "mesinkar.h"
// Advances until CC is not blank
static char configFilename[] = "config.conf";
static char savefileFilename[] = "savefile.dat";

static FILE *savefile;

void ignoreBlank()
{
    while (CC != EOF && (CC == ' ' || CC == '\n'))
        ADV();
}

// Advances until CC is not blank
void ignoreBlankSTDIN()
{
    // While not blank
    while (CC != EOF && CC == ' ')
        ADVSTDIN();
}

// readNumber parses input to be an integer
int readNumber()
{
    int n = 0;

    ignoreBlank();
    while (!EOP && CC != EOF && CC != ' ' && CC != '\n')
    {
        n = n * 10 + (CC - '0');
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

    while (!EOP && CC != '\n')
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
    while (!EOP && CC != '\n')
    {
        int tmp = CC - '0';
        *X = (*X) * 10 + tmp;
        ADVSTDIN();
    }
}

// readConfigFile will read config file and make the structure
void readConfigFile(StatusGame *s_status_game)
{
    START(configFilename);
    ignoreBlank();

    //Read map size
    ignoreBlank();
    int row = readNumber();
    ignoreBlank();
    int col = readNumber();

    // alokasi map
    Map map;
    m_allocate(&map, row, col);

    // Read HQ
    Building HQ;
    
    int x = readNumber();
    ignoreBlank();
    int y = readNumber();
    b_create_building(&HQ,x,y,'8');


    // Read building count
    ignoreBlank();
    int t = readNumber();
    


    ignoreBlank();
}

// Print ASCII of character (for debugging purposes)
void printASCIIFile();

// Print word
void printWord(word W);

// Save to file
void saveToFile(StatusGame s_status_game);

// Load from file
void loadFromFile(StatusGame *s_status_game);

// Word to int converter
int intConverter(word W);

// Word Compare
boolean wordCompare(word W, char *S);

void ldx_newGame(const char *path, StatusGame *status_game);

void ldx_loadGame(const char *path, StatusGame *status_game);

void ldx_saveGame(const char *path, StatusGame status_game);
