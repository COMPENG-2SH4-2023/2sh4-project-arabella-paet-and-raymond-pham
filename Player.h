#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFoodRef); 
        ~Player();

        objPosArrayList* getPlayerPos(); 
        void updatePlayerDir();

        void movePlayer();

        //check if the newly positioned head overlaps with the objPos of the food
        bool checkFoodConsumption(objPos head);

        //increases the size of the list if the snake consumes a food
        void increasePlayerLength(objPos head);

        //check if head overlaps with body
        bool checkSelfCollision(objPos head);
    private:
        objPosArrayList* playerPosList;   
        GameMechs* mainGameMechsRef;
        Food* foodRef; 
             
        enum Dir myDir;
};

#endif

