#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000
#define ROWS 10
#define COLUMNS 20

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  
    objPos border;
    int x, y;
    for(y = 0; y < ROWS; y++)
    {
        for(x = 0; x < COLUMNS; x++)
        {
            border.setObjPos(x, y, '#');
            if(border.y == 0 || border.y == ROWS - 1 || border.x == 0 || border.x == COLUMNS - 1)              // if the cursor is on the left-most or right-most columns of the board (x=0 or x=19) print #
            {                                                      // Similarily if the cursor is on the top-most or bottom-most rows of the board (y=0 or y = 9) print #
                cout << border.getSymbol();
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
