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
    //nothing created on heap through food class
}

void Food::generateFood(objPosArrayList* blockOff)
{
    srand(time(NULL));

    int xCandidate = 0;
    int yCandidate = 0;
    bool is_pos = false;                                                      //condition for if coordinates have been generated or not
    objPos bodyElement;

    while(is_pos == false)                                                    //checking if the food object has been given a valid random coordinate yet
    {
        xCandidate = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1; 
        yCandidate = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
        objPos tempPos(xCandidate, yCandidate, 'o');                          //created a tempPos object that has the random coordinates 

        for(int bodyIndex = 0; bodyIndex < blockOff->getSize(); bodyIndex++)                          //iterating through each element within the snakes body (the list)
        {
            blockOff->getElement(bodyElement, bodyIndex);
            if(tempPos.isPosEqual(&bodyElement) == true)                      //Checking if the coordinates of the randomly generated coordinates are the same as the current body element
            {
                is_pos = false;                                               //If it is the same, generate new set of coordinates
                break;
            }
            is_pos = true;
        }

        if(is_pos == true)                                                    //If it is NOT the same, set it as the coordinates of the food item
        {
            foodPos.setObjPos(tempPos);
        }
    }

}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos);
}