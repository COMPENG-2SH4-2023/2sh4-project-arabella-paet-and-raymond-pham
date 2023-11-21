#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs *ptrGameMechs;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(ptrGameMechs->getExitFlagStatus() == false)  
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

    ptrGameMechs = new GameMechs();
    ptrGameMechs->setExitFalse();
}

void GetInput(void)
{
    if (MacUILib_hasChar())
    {
        ptrGameMechs->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    if(ptrGameMechs->getInput() != 0)  // if not null character
    {
        switch(ptrGameMechs->getInput())
        {                      
            case 27:  // exit
                ptrGameMechs->setExitTrue();
                break;
            // case '1':
            //     ptrGameMechs->incrementScore();    //testing incrementScore() method
            //     break;
            // case '2':
            //     ptrGameMechs->setLoseTrue();
            //     break;
            // case '3':
            //     ptrGameMechs->setLoseFalse();
            //     break;
            default:
                break;
        }
    }

    ptrGameMechs->clearInput();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  
    objPos border;
    int x, y;
    for(y = 0; y < ptrGameMechs->getBoardSizeY(); y++)
    {
        for(x = 0; x < ptrGameMechs->getBoardSizeX(); x++)
        {
            border.setObjPos(x, y, '#');
            if(border.y == 0 || border.y == ptrGameMechs->getBoardSizeY() - 1 || border.x == 0 || border.x == ptrGameMechs->getBoardSizeX() - 1)            
            {                                                                                                  
                cout << border.getSymbol();
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    /*Degbugging prints for the score and winning/losing messages

    // cout << ptrGameMechs->getScore() << endl;

    // if(ptrGameMechs->getLoseFlagStatus())
    // {
    //     ptrGameMechs->setExitTrue();
    //     cout << "Uh oh you lost :(" << endl;
    // }
    // else
    // {
    //     ptrGameMechs->setExitTrue();
    //     cout << "Yay you won :)" << endl;
    // }

    */

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();    

    delete ptrGameMechs;
  
    MacUILib_uninit();
}
