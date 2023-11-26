#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include "objPosArrayList.h"

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
    ptrPlayer = new Player(ptrGameMechs, ptrFood);
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
    ptrFood->getFoodPos(foodPos);           //copying the food object as an objPos object

    objPosArrayList* playerBody;
    playerBody = ptrPlayer->getPlayerPos(); //gets the reference for the entire snake body (the array list)
    objPos tempBody;

    bool draw_body;

    int bodyIndex, column, row;

    for(row = 0; row < ptrGameMechs->getBoardSizeY(); row++)
    {
        for(column = 0; column < ptrGameMechs->getBoardSizeX(); column++)
        {
            board.setObjPos(column, row, ' ');
            draw_body = false;

            //iterate through each element in the list (the snakes body)
            for(bodyIndex = 0; bodyIndex < playerBody->getSize(); bodyIndex++)
            {
                playerBody->getElement(tempBody, bodyIndex); //gets the information for each section of the snakes body
                if(tempBody.isPosEqual(&board))
                {
                    cout << tempBody.getSymbol();    //if the current body element has the same coordinates of the current board coordinates, print that body element
                    draw_body = true;
                    break;
                }
            }

            //If an element of the snakes body has been printed onto the board, skip the rest of the actions below and go to the next coordinate of the board
            if(draw_body == true)
            {
                continue;
            }

            if(board.y == 0 || board.y == ptrGameMechs->getBoardSizeY() - 1 || board.x == 0 || board.x == ptrGameMechs->getBoardSizeX() - 1)            
            {    
                board.setObjPos(column, row, '#');                                                                                              
                cout << board.getSymbol();
            }

            else if(foodPos.isPosEqual(&board))                   //if the food has the same coordinates as the current board object, print thr food object
            {
                cout << foodPos.getSymbol();      
            }

            else
            {
                cout << board.getSymbol();
            }
        }
        cout << endl;
    }
    cout << "Score: " << ptrGameMechs->getScore() << endl;
    cout << "List Size: " << playerBody->getSize() << endl;
    cout << "Food Position: (" << foodPos.x << ", " << foodPos.y << ")" << endl;
    cout << "Snake Body Positions: " << endl;
    for(int i = 0; i < playerBody->getSize(); i++)
    {
        playerBody->getElement(tempBody, i);
        cout << "Snake[" << i + 1 << "]: (" << tempBody.x << ", " << tempBody.y << ")" << endl;
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
    delete ptrPlayer;

    delete ptrFood;
  
    MacUILib_uninit();
}
