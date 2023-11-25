#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *ptrGameMechs;
Food *ptrFood;
Player *ptrPlayer;

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
 
    ptrGameMechs = new GameMechs();      //Default Game Board Size [30x15]
    ptrFood = new Food(ptrGameMechs);
    ptrPlayer = new Player(ptrGameMechs);

    objPos tempPos(-1, -1, '0');
    ptrFood->generateFood(tempPos);
}

void GetInput(void)
{
    ptrGameMechs->getInput();
}

void RunLogic(void)
{
    ptrPlayer->updatePlayerDir();        //takes input from user for the player objects direction
    ptrPlayer->movePlayer();             //move player object and head wraparound logic
    
    ptrGameMechs->clearInput();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    objPos board;
    
    objPos foodPos;
    ptrFood->getFoodPos(foodPos);   //copying the food object as an objPos object
    
    objPos player;
    ptrPlayer->getPlayerPos(player);

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
            else if(foodPos.isPosEqual(&board))                   //if the food has the same coordinates as the current board object, print thr food object
            {
                cout << foodPos.getSymbolIfPosEqual(&board);      
            }
            else if (player.isPosEqual(&board))                   //if the player object has the same coordinates as the current board object, print the player object
            {
                cout << player.getSymbolIfPosEqual(&board);
            }
            else
            {
                cout << board.getSymbol();
            }
        }
        cout << endl;
    }

    cout << "Score: " << ptrGameMechs->getScore() << endl;
    cout << "Player Position: (" << player.x << ", " << player.y << ")" << endl;
    cout << "Food Position: (" << foodPos.x << ", " << foodPos.y << ")" << endl;

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
    delete ptrPlayer;

    delete ptrFood;
  
    MacUILib_uninit();
}
