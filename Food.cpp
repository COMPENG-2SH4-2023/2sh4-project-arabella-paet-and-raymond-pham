#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include <iostream>

using namespace std;

Food::Food(GameMechs* thisGMRef)
{
    foodPos.setObjPos(-1, -1, 'o');     //intialize the foodPos outside the game board
    mainGameMechsRef = thisGMRef;
}

Food::~Food()
{

}

void Food::generateFood(objPos blockOff)
{
    srand(time(NULL));
    int xCandidate = 0;
    int yCandidate = 0;
    bool is_pos = false;

    while(is_pos == false)                                                    //checking if the food object has been given a random coordinate yet
    {
        xCandidate = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1; 
        yCandidate = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
        objPos tempPos(xCandidate, yCandidate, 'o');                          //created a tempPos object that has the random coordinates 

        if(tempPos.isPosEqual(&blockOff) == false)                            //Checking if the coordinates if tempPos and the player object are the same
        {
            foodPos.setObjPos(tempPos);                                       //if they are not the same, set the coordinates of foodPos the same as the tempPos
            is_pos = true; 
        }
    }

}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos);
}