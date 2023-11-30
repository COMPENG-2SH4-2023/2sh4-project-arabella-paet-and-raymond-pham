#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    protected:
        objPos* aList;
        int listSize; 
        int arrayCapacity; 

    public:
        //Default Constructor
        objPosArrayList();

        //Destructor
        ~objPosArrayList();

        //Getters
        int getSize();
        void getHeadElement(objPos &returnPos);
        void getTailElement(objPos &returnPos);
        void getElement(objPos &returnPos, int index);

        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        void emptyList();
        
};

#endif