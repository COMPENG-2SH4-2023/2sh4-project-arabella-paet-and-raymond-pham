#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"

Food::Food()
{
    foodPos.setObjPos(0, 0, 'O');
}

void Food::generateFood(objPos blockOff, GameMechs* board)
{
    int xCandidate = 0;
    int yCandidate = 0;

    xCandidate = rand() % (board->getBoardSizeX() - 2) + 1; 
    yCandidate = rand() % (board->getBoardSizeY() - 2) + 1;
    foodPos.setObjPos(xCandidate, yCandidate, 'O');

}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos);
}