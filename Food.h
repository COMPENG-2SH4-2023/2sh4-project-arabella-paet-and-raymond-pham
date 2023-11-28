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

        //Getter
        void getFoodPos(objPos &returnPos);

        void generateFood(objPosArrayList* blockOff);
};

#endif
