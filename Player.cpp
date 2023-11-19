#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.x = 10;
    playerPos.y = 4;
    playerPos.symbol = '#';

    enum Dir move;

    // Border Wraparound
    if (player.y <= 0)
    {
        playerPos.y = (*thisGMRef.getBoardSizeY)-2;
    }
    else if (playerPos.y >= (*thisGMRef.getBoardSizeY)-1)
    {
        playerPos.y = 1;
    }
    
    if (playerPos.x >= (*thisGMRef.getBoardSizeX)-1)
    {
        playerPos.x = 1;
    }
    else if (playerPos.x <= 0)
    {
        playerPos.x = (*thisGMRef.getBoardSizeX)-2;
    }
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    // FSM
    switch(input)
    {
        case 'w':
            if (move == DOWN){
                break;
            }
            else {
                move = UP;
                break;
            }

        case 'a': 
            if (move == RIGHT){
                break;
            }
            else {
                move = LEFT;
                break;
            }              

        case 's':
            if (move == UP){
                break;
            }
            else {
                move = DOWN;
                break;
            }

        case 'd':
            if (move == LEFT){
                break;
            }
            else {
                move = RIGHT;
                break;
            }
    }
    input = 0;        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    // Isn't FSM supposed to be in updatePlayerDir
    switch(move)
    {
        case UP:
            player.y -= 1;
            break;
        case DOWN:
            player.y += 1;
            break;
        case LEFT:
            player.x -= 1;
            break;
        case RIGHT:
            player.x += 1;
            break;
        default:
            break;
    }
}

