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
 
    ptrGameMechs = new GameMechs();                            //Default Game Board Size [30x15]
    ptrFood = new Food(ptrGameMechs);
    ptrPlayer = new Player(ptrGameMechs, ptrFood);

    objPosArrayList* playerBody = ptrPlayer->getPlayerPos();   //Getting the reference for the snakes body(the player list) 
    ptrFood->generateFood(playerBody);                         //Generate food but not on the snakes body
} 

void GetInput(void)
{
    ptrGameMechs->getInput();            //takes input from the user
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
    objPos board;                           //object for each coordinate on the board
    objPos tempObj;
    objPosArrayList* playerBody;            
    objPosArrayList* foodBucket;
    bool drawBody;                         //indicator for if an element from the snakes body has been printed or not
    bool isFood;
    int foodIndex, bodyIndex, column, row;

    foodBucket = ptrFood->getFoodPos();           //copying the food object as an objPos object
    
    playerBody = ptrPlayer->getPlayerPos(); //gets the reference for the entire snake body (the array list)


    for(row = 0; row < ptrGameMechs->getBoardSizeY(); row++)
    {
        for(column = 0; column < ptrGameMechs->getBoardSizeX(); column++)
        {
            board.setObjPos(column, row, ' ');              //Intializing the board obj to the current x and y coordinate, with a space as its symbol                            
            drawBody = false;  
            isFood = false;

            //iterate through each element in the list (the snakes body)
            for(bodyIndex = 0; bodyIndex < playerBody->getSize(); bodyIndex++)
            {
                playerBody->getElement(tempObj, bodyIndex); //gets the information for each element of the snakes body
                if(tempObj.isPosEqual(&board))              //if the current body element has the same coordinates of the current board coordinates, print that body element
                {
                    cout << tempObj.getSymbol();    
                    drawBody = true;
                    break;
                }
            }

            //If an element of the snakes body has been printed onto the board, skip the rest of the actions below and go to the next coordinate of the board
            if(drawBody)
            {
                continue;
            }

            //Itereate through each food element inside the list (foodBucket)
            for(foodIndex = 0; foodIndex < foodBucket->getSize(); foodIndex++)
            {
                foodBucket->getElement(tempObj, foodIndex);                        
                if(tempObj.isPosEqual(&board))
                {
                    cout << tempObj.getSymbol();
                    isFood = true;
                    break;
                }
            }

            //If a food object was printed from the foodBucket, skip and continue to next coordinate of the board
            if(isFood)
            {
                continue;
            }

            //Printing the border of the game board
            if(board.y == 0 || board.y == ptrGameMechs->getBoardSizeY() - 1 || board.x == 0 || board.x == ptrGameMechs->getBoardSizeX() - 1)            
            {    
                board.setObjPos(column, row, '#');                                                                                              
                cout << board.getSymbol();
            }

            else                                                  //If neither food or snake element is supposed to printed, just print the space
            {
                cout << board.getSymbol();
            }
            
        }
        cout << endl;
    }
    cout << "Score: " << ptrGameMechs->getScore() << endl;

    if(ptrGameMechs->getSuperFoodStatus())                       //Display message if super food was eaten
    {
        cout << "YOU ATE A SUPER FOOD >:D!!!" << endl;
    }

    if(ptrGameMechs->getLoseFlagStatus() == true)                 //If lose status is true (snake self-collision), print out the lose message and exit game
    {   
        cout << endl;
        cout << "Uh Oh you lost :(" << endl;
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{ 

    delete ptrGameMechs;
    delete ptrPlayer;
    delete ptrFood;
  
    MacUILib_uninit();
}
