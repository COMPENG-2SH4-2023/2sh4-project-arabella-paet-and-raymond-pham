#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "MacUILib.h"

#define NUM_FOOD 3

class Food 
{
    private:
        objPosArrayList* foodBucket;
        GameMechs* mainGameMechsRef;

    public:
        //Constructor
        Food(GameMechs* thisGMRef);

        //Deconstructor
        ~Food();

        //Getter
        objPosArrayList* getFoodPos();
        int getSize();

        void generateFood(objPosArrayList* blockOff);
        void add(objPos thisObj);
        bool isExist(objPos thisObj);
};

#endif
