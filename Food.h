#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

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

        void generateFood(objPosArrayList* blockOff);
};

#endif
