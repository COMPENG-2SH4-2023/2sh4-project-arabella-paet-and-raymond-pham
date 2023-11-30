#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include "objPos.h"
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
    bool isPos;                                                                  //condition for if coordinates have been generated or not
    objPos playerBody;
    objPos tempFood;

    foodBucket->emptyList();                                                     //"Empty the List" so the foodBucket can overwrite the old foor objs with new food objs

    while(foodCount < NUM_FOOD)                                                  //Keep generating coordinates until each food item has a unique coordinate
    {
        isPos = false;
        while(isPos == false)                                                    //First check if the randomly generated coordinates are valid (not same coordinates as snake body)
        {
            xCandidate = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1; 
            yCandidate = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
            
            if(foodCount == (NUM_FOOD - 1))                                      //Let the last food object created become the Super Food
            {
                tempFood.setObjPos(xCandidate, yCandidate, '@');                 //created a tempPos object that holds the generated random coordinates 
            }
            else
            {
                tempFood.setObjPos(xCandidate, yCandidate, 'o');
            }

            for(int i = 0; i < blockOff->getSize(); i++)                         //iterating through each element within the snakes body (the list)
            {
                blockOff->getElement(playerBody, i);
                if(tempFood.isPosEqual(&playerBody) == true)                     //Checking if the coordinates of the randomly generated coordinates are the same as the current body element
                {
                    isPos = false;                                               //If it is the same, generate new set of coordinates
                    break;
                }
                isPos = true;
            }

            if(isPos == true && (isExist(tempFood) == false))                    //If it is NOT the same AND another food object does not have the same coordinates
            {
                add(tempFood);                                                   //If no other food objects in the bucket have the same coordinates, add it to the bucket
                foodCount++;
            }
        }
    }

}

objPosArrayList* Food::getFoodPos()                                              //returns the food position of the food object
{
    return foodBucket;
}

//Adds food object to the bucket
void Food::add(objPos thisObj)
{
    foodBucket->insertTail(thisObj);
}

//Check if a food object is already inside the bucket
bool Food::isExist(objPos thisObj)
{
    objPos foodElement;
    for(int i = 0; i < getSize(); i++)                    //Iterating through each food object that is already in the bucket 
    {
        foodBucket->getElement(foodElement, i);        
        if(thisObj.isPosEqual(&foodElement))              //Comparing each food object with the newly created food object to see if they have the same coordinates
        {
            return true;
        }
    }
    return false;
}

//Getting size of the bucket
int Food::getSize()
{
    return foodBucket->getSize();
}