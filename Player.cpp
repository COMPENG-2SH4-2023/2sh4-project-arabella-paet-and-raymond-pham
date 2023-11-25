#include "Player.h"

//for debugging messages
#include <iostream>
using namespace std;

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    //playerPos.setObjPos((mainGameMechsRef->getBoardSizeX())/2, (mainGameMechsRef->getBoardSizeY())/2, '*');

    objPos tempPos;
    tempPos.setObjPos((mainGameMechsRef->getBoardSizeX())/2, (mainGameMechsRef->getBoardSizeY())/2, '*');

    playerPosList = new objPosArrayList();

    //Snake with 1 Element
    //playerPosList->insertHead(tempPos);

    //Snake with 3 Elements
    // playerPosList->insertHead(tempPos);
    // playerPosList->insertHead(tempPos);

    //Snake with 5 Elements
    // playerPosList->insertHead(tempPos);
    // playerPosList->insertHead(tempPos);
    // playerPosList->insertHead(tempPos);
    // playerPosList->insertHead(tempPos);
    // playerPosList->insertHead(tempPos);

}


Player::~Player()
{
    // delete any heap members here
    // nothing to delete yet
    //will be implemented in iteration 3
    delete playerPosList;
}

// void Player::getPlayerPos(objPos &returnPos)
// {
//     // return the reference to the playerPos arrray list
//     returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
// }

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
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

    playerPosList->insertHead(currentHead);    //after moving the current head based on the user input, insert the current head object as the NEW head of the snake
    playerPosList->removeTail();               //then the tail of the snake since it has been moved 
}

