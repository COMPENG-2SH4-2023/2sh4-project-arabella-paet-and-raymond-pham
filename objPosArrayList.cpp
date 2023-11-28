#include "objPosArrayList.h"

#include <iostream>
using namespace std;

//Default Constructor
objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;
    aList = new objPos[ARRAY_MAX_CAP];

    cout << "Default Constructor called." << endl;

}


//Destructor
objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

//Getters
int objPosArrayList::getSize()
{
    return listSize;
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
    if(index > listSize)
    {
        cout << "Invalid Index." << endl;
        return;
    }
    returnPos.setObjPos(aList[index]);
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // Error check
    if (listSize == arrayCapacity)
    {
        cout << "Array List is full." << endl;
        return;
    }

    // Move over elements +1 pos towards tail
    for (int i=listSize; i>0; i--)
    {
        aList[i].setObjPos(aList[i-1]); //shuffle all elements towards tail
    }
    aList[0].setObjPos(thisPos);        //insert head based on the input
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    //Error Check
    if (listSize == arrayCapacity)
    {
        cout << "Array List is full." << endl;
        return;      
    }
    aList[listSize] = thisPos;          //insert element at the end of the list
    listSize++;
}

void objPosArrayList::removeHead()
{
    //Error Check
    if(listSize <= 0)
    {
        cout << "List is Empty, No Removal Allowed" << endl;
        return;
    }
    // Shift towards head
    for (int i=1; i<listSize; i++)
    {
        aList[i-1] = aList[i];
    }
    listSize--;    
}

void objPosArrayList::removeTail()
{
    //Error Check
    if(listSize == 0)
    {
        cout << "List is Empty, No Removal Allowed" << endl;
        return;
    }
    listSize--;  
}

//Empty the list
void objPosArrayList::emptyList()
{
    listSize = 0;                   //By setting the listSize as 0, elements within the list can get overwritten by new objects that will inserted
}
