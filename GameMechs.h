#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        bool superFoodFlag;
        int score;       
        
        int boardSizeX;
        int boardSizeY;

    public:
        //Default Constructor
        GameMechs();

        //Parameterized Constructor
        GameMechs(int boardX, int boardY);
        
        //Getters
        bool getExitFlagStatus();
        bool getLoseFlagStatus();
        bool getSuperFoodStatus();
        char getInput();
        int getBoardSizeX();
        int getBoardSizeY();
        int getScore();

        //Setters
        void setExitFalse();
        void setExitTrue();
        void setLoseFalse();
        void setLoseTrue();
        void setSuperFoodTrue();
        void setSuperFoodFalse();
        void setInput(char this_input);

        void clearInput();
        void incrementScore();
        void incrementSuperScore();
};

#endif