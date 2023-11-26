#include "Player.h"

//for debugging messages
#include <iostream>
using namespace std;

Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    foodRef = thisFoodRef;
    myDir = STOP;

    objPos startPos;
    startPos.setObjPos((mainGameMechsRef->getBoardSizeX())/2, (mainGameMechsRef->getBoardSizeY())/2, '*');

    playerPosList = new objPosArrayList();

    playerPosList->insertHead(startPos);
    foodRef->generateFood(playerPosList);
}


Player::~Player()
{
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
}

bool Player::checkFoodConsumption(objPos newHead)
{
    objPos foodPos;
    foodRef->getFoodPos(foodPos);

    return newHead.isPosEqual(&foodPos);            //return true if the new head position collides with a food item

}

void Player::increasePlayerLength(objPos newHead)
{
    playerPosList->insertHead(newHead);            //inserts the new head position
    if(checkFoodConsumption(newHead) == true)  //checking if the new head position hit food
    {
        foodRef->generateFood(playerPosList);      //generates new food location after collision
        mainGameMechsRef->incrementScore();        //increment game score
    }
    else
    {   
        playerPosList->removeTail();               //if no collison occure, remove the tail of the snake(which is the old tail position)
    }
}



void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    // FSM
    
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
    // cout << "Input: " << mainGameMechsRef->getInput() << endl;
    // cout << "Dir: " << myDir << endl;

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    // THis^ is the comment under this method but Isn't FSM supposed to be in updatePlayerDir

    objPos currentHead;
    playerPosList->getHeadElement(currentHead);

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

    increasePlayerLength(currentHead);             //after moving the current head based on the user input, insert the current head object as the NEW head of the snake
}

