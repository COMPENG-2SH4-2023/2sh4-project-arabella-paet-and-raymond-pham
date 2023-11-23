#include "objPosArrayList.h"

#include <iostream>
using namespace std;

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;
    aList = new objPos[ARRAY_MAX_CAP];

    cout << "Default Constructor called." << endl;

}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
    cout << "Destructor Called" << endl;

}

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // Error check
    if (listSize == arrayCapacity)
    {
        cout << "Array List is full." << endl;
    }

    // Move over elements +1 pos towards tail
    for (int i=listSize; i>0; i--)
    {
        aList[i].setObjPos(aList[i-1]); //shuffle all elements towards tail
    }
    aList[0].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == arrayCapacity)
    {
        cout << "Array List is full." << endl;
    }
    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    // Shift towards head
    for (int i=1; i<listSize; i++)
    {
        aList[i-1] = aList[i];
    }
    listSize--;    
}

void objPosArrayList::removeTail()
{
    listSize--;  
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}