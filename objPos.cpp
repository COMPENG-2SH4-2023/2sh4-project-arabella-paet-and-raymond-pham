#include "objPos.h"

objPos::objPos()
{
    x = 0;
    y = 0;
    symbol = 0; //NULL
}

//Copy Constructor, copies an object to another object 
objPos::objPos(objPos &o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}


objPos::objPos(int xPos, int yPos, char sym)
{
    x = xPos;
    y = yPos;
    symbol = sym;
}

//Set the data members of the object we are in, with the data members of the default object??
void objPos::setObjPos(objPos o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}

//Sets the data members of the object we are currently in with the specified parameters
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    x = xPos;
    y = yPos;
    symbol = sym;
}

//Gets the data memebers of the object we are currently in
void objPos::getObjPos(objPos &returnPos)
{
    returnPos.setObjPos(x, y, symbol);
}

//Gets the symbol of the object we are currently in
char objPos::getSymbol()
{
    return symbol;
}

//Check if the object we are currently in, has the same position of the reference object
bool objPos::isPosEqual(const objPos* refPos)
{
    return (refPos->x == x && refPos->y == y);
}

//Gets the symbol of the object we are currently in, if is in the same position of the reference object 
char objPos::getSymbolIfPosEqual(const objPos* refPos)
{
    if(isPosEqual(refPos))
        return getSymbol();
    else
        return 0;
}
