#include "Player.h"

//for debugging messages
#include <iostream>
using namespace std;

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos((mainGameMechsRef->getBoardSizeX())/2, (mainGameMechsRef->getBoardSizeY())/2, '*');

}


Player::~Player()
{
    // delete any heap members here
    // nothing to delete yet
    //will be implemented in iteration 3
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    // FSM
    
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
    // cout << "Input: " << mainGameMechsRef->getInput() << endl;
    // cout << "Dir: " << myDir << endl;

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    // THis^ is the comment under this method but Isn't FSM supposed to be in updatePlayerDir


    switch(myDir)
    {
        case UP:
            playerPos.y -= 1;
            break;
        case DOWN:
            playerPos.y += 1;
            break;
        case LEFT:
            playerPos.x -= 1;
            break;
        case RIGHT:
            playerPos.x += 1;
            break;
        default:
            break;
    }

    // Border Wraparound
    if (playerPos.y <= 0)
    {
        playerPos.y = (mainGameMechsRef->getBoardSizeY())-2;
    }
    else if (playerPos.y >= (mainGameMechsRef->getBoardSizeY())-1)
    {
        playerPos.y = 1;
    }
    
    if (playerPos.x >= (mainGameMechsRef->getBoardSizeX())-1)
    {
        playerPos.x = 1;
    }
    else if (playerPos.x <= 0)
    {
        playerPos.x = (mainGameMechsRef->getBoardSizeX())-2;
    }

    playerPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
}

