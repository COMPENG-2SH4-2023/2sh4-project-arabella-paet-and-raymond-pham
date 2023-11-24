#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"

Food::Food(GameMechs* thisGMRef)
{
    foodPos.setObjPos(0, 0, 'O');
    mainGameMechsRef = thisGMRef;
}

Food::~Food()
{

}

void Food::generateFood(objPos blockOff)
{
    srand(time(NULL));
    int xCandidate = 0;
    int yCandidate = 0;

    xCandidate = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1; 
    yCandidate = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
    foodPos.setObjPos(xCandidate, yCandidate, 'O');

}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos);
}