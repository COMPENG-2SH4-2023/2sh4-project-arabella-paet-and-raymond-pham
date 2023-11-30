#include "GameMechs.h"
#include "MacUILib.h"

//Constructors
GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    superFoodFlag = false;


}

//Parameterized Constructor
GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    superFoodFlag = false;
}

//Getters
bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

bool GameMechs::getSuperFoodStatus()
{
    return superFoodFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
        if (input == 27)
        {
            setExitTrue();
        }
    }
    return input;
}   

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

int GameMechs::getScore()
{
    return score;
}

//Setters
void GameMechs::setExitFalse()
{
    exitFlag = false;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFalse()
{
    loseFlag = false;
}

void GameMechs::setLoseTrue()
{
    loseFlag = true;
}

void GameMechs::setSuperFoodTrue()
{
    superFoodFlag = true;
}

void GameMechs::setSuperFoodFalse()
{
    superFoodFlag = false;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

//clears the input stream
void GameMechs::clearInput()
{
    input = 0;
}

//increment score of the game
void GameMechs::incrementScore()
{
    score++;
}

//increment score of the game when super food is eaten
void GameMechs::incrementSuperScore()
{
    score+=10;
}


