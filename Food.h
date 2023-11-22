#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

using namespace std;

class Food
{
    private:
        objPos foodPos;

    public:
        //Constructor
        Food();

        //Deconstructor
        ~Food();

        void generateFood(objPos blockOff, GameMechs* board);
        void getFoodPos(objPos &returnPos);
};

#endif
