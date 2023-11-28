#include "Player.h"

//for debugging messages
#include <iostream>
using namespace std;

//Constructor
Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    playerPosList = new objPosArrayList();
    mainGameMechsRef = thisGMRef;                             //reference to the main GameMechanics
    foodRef = thisFoodRef;                                    //reference to the main food obj
    myDir = STOP;

    objPos startPos;                                          //Getting the start position of the head when the game first starts
    startPos.setObjPos((mainGameMechsRef->getBoardSizeX())/2,
                       (mainGameMechsRef->getBoardSizeY())/2,
                        '*');

    playerPosList->insertHead(startPos);
}

//Destructor
Player::~Player()
{
    delete playerPosList;
}

//Getter
objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    
    if(mainGameMechsRef->getInput() != 0)  // if not null character
    {
        switch(mainGameMechsRef->getInput())
        {
            case 'w':
                if (myDir == DOWN){
                    break;
                }
                else {
                    myDir = UP;
                    break;
                }

            case 'a': 
                if (myDir == RIGHT){
                    break;
                }
                else {
                    myDir = LEFT;
                    break;
                }              

            case 's':
                if (myDir == UP){
                    break;
                }
                else {
                    myDir = DOWN;
                    break;
                }

            case 'd':
                if (myDir == LEFT){
                    break;
                }
                else {
                    myDir = RIGHT;
                    break;
                }
            default:
                myDir = STOP;
                break;
        }
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    objPos currentHead;
    playerPosList->getHeadElement(currentHead);    //Getting the position of the current snakes head

    switch(myDir)
    {
        case UP:
            currentHead.y -= 1;
            break;
        case DOWN:
            currentHead.y += 1;
            break;
        case LEFT:
            currentHead.x -= 1;
            break;
        case RIGHT:
            currentHead.x += 1;
            break;
        default:
            break;
    }

    // Border Wraparound
    if (currentHead.y <= 0)
    {
        currentHead.y = (mainGameMechsRef->getBoardSizeY())-2;
    }
    else if (currentHead.y >= (mainGameMechsRef->getBoardSizeY())-1)
    {
        currentHead.y = 1;
    }
    
    if (currentHead.x >= (mainGameMechsRef->getBoardSizeX())-1)
    {
        currentHead.x = 1;
    }
    else if (currentHead.x <= 0)
    {
        currentHead.x = (mainGameMechsRef->getBoardSizeX())-2;
    }

    if ((checkSelfCollision(currentHead) == true))   //Checking if the snake collided with its own body
    {
        mainGameMechsRef->setLoseTrue();
        mainGameMechsRef->setExitTrue();
    }
    else                                             //If no collision occured, perform the increasePlayerLength algorithm
    {
        increasePlayerLength(currentHead);           //after moving the current head based on the user input, insert the current head object as the NEW head of the snake
    }
}

//Checking if the snake ate a food obj
bool Player::checkFoodConsumption(objPos head)
{
    objPos foodPos;
    foodRef->getFoodPos(foodPos);                   //getting the food coordinates

    return head.isPosEqual(&foodPos);               //return true if the new head position collides with a food item

}

//Increasing the snakes body 
void Player::increasePlayerLength(objPos head)
{
    playerPosList->insertHead(head);               //inserts the new head position
    if(checkFoodConsumption(head) == true)         //checking if the new head position hit a food obj
    {
        foodRef->generateFood(playerPosList);      //generates new food location after collision
        mainGameMechsRef->incrementScore();        //increment game score
    }
    else
    {   
        playerPosList->removeTail();               //if no collison occurs, remove the tail of the snake(which is the old tail position)
    }
}

bool Player::checkSelfCollision(objPos head)
{
    int bodyIndex;
    objPos bodyElement;
    bool isCollision = false;
    for (bodyIndex = 1; bodyIndex < playerPosList->getSize(); bodyIndex++) // Loop through each list element for the coords of the body
    {
        playerPosList->getElement(bodyElement, bodyIndex);                 
        if (head.isPosEqual(&bodyElement))                                 // Checking if the head of the snake has collided with the current body element
        {
            isCollision = true;
        }
    }
    return isCollision;
}
