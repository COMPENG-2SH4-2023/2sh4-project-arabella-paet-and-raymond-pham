#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

class Food
{
    private:
        objPos foodPos;
        GameMechs* mainGameMechsRef;

    public:
        //Constructor
        Food(GameMechs* thisGMRef);

        //Deconstructor
        ~Food();

        void generateFood(objPosArrayList* blockOff);
        void getFoodPos(objPos &returnPos);
};

#endif
