#ifndef OBJPOS_H
#define OBJPOS_H

class objPos
{
    public:
        int x;
        int y;
        char symbol;

        //Default Constructor
        objPos();

        //Copy Constructor
        objPos(objPos &o); 

        //Parameterized Constructor
        objPos(int xPos, int yPos, char sym);

        //Setters
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        //Getters
        void getObjPos(objPos &returnPos);
        char getSymbol();

        bool isPosEqual(const objPos* refPos);
        char getSymbolIfPosEqual(const objPos* refPos);
};

#endif