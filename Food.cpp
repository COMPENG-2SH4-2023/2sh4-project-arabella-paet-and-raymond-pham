#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include <iostream>

using namespace std;

Food::Food(GameMechs* thisGMRef)
{
    //intialize the foodPos outside the game board
    mainGameMechsRef = thisGMRef;
    foodBucket = new objPosArrayList();

}

Food::~Food()
{
    delete foodBucket;
    cout << "destrcutor Called" << endl;
}

void Food::generateFood(objPosArrayList* blockOff)
{
    srand(time(NULL));

    int xCandidate = 0;              
    int yCandidate = 0;
    int foodCount = 0;
    int foodIndex;                      
    bool is_pos;                                                                  //condition for if coordinates have been generated or not
    objPos foodElement;

    foodBucket->emptyList();                                                      //"Empty the List" so the foodBucket can overwrite the old foor objs with new food objs

    while(foodCount < NUM_FOOD)                                                   //Keep generating coordinates until each food item has a unique coordinate
    {
        is_pos = false;
        while(is_pos == false)                                                    //First check if the randomly generated coordinates are valid (not same coordinates as snake body)
        {
            xCandidate = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1; 
            yCandidate = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
            objPos tempPos(xCandidate, yCandidate, 'o');                          //created a tempPos object that holds the generated random coordinates 

            for(foodIndex = 0; foodIndex < blockOff->getSize(); foodIndex++)      //iterating through each element within the snakes body (the list)
            {
                blockOff->getElement(foodElement, foodIndex);
                if(tempPos.isPosEqual(&foodElement) == true)                      //Checking if the coordinates of the randomly generated coordinates are the same as the current body element
                {
                    is_pos = false;                                               //If it is the same, generate new set of coordinates
                    break;
                }
                is_pos = true;
            }

            if(is_pos == true)                                                    //If it is NOT the same, set it as the coordinates of the food item
            {
                foodBucket->insertTail(tempPos);
                foodCount++;
            }
        }
    }

}

objPosArrayList* Food::getFoodPos()                                             //returns the food position of the food object
{
    return foodBucket;
}