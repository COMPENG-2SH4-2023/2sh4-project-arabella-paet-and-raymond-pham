#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *ptrGameMechs;
Food *ptrFood;
objPos player;

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
    ptrFood = new Food();


    player.setObjPos(1, 1, '*');

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
            case 'p':
                ptrFood->generateFood(player, ptrGameMechs);
                break;
            default:
                break;
        }
    }

    ptrGameMechs->clearInput();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    objPos board;
    objPos foodPos;
    ptrFood->getFoodPos(foodPos);   //copying the food object as an objPos object
    int x, y;

    for(y = 0; y < ptrGameMechs->getBoardSizeY(); y++)
    {
        for(x = 0; x < ptrGameMechs->getBoardSizeX(); x++)
        {
            board.setObjPos(x, y, ' ');
            if(board.y == 0 || board.y == ptrGameMechs->getBoardSizeY() - 1 || board.x == 0 || board.x == ptrGameMechs->getBoardSizeX() - 1)            
            {    
                board.setObjPos(x, y, '#');                                                                                              
                cout << board.getSymbol();
            }
            else if(foodPos.isPosEqual(&board))                   //if the food has the same coordinates as the current board object 
            {
                cout << foodPos.getSymbolIfPosEqual(&board);      //if yes, print the food
            }
            else
            {
                cout << board.getSymbol();
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
    //delete ptrFood;
  
    MacUILib_uninit();
}
