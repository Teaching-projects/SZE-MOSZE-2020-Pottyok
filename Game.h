#ifndef GAME_HEADER
#define GAME_HEADER
#include <vector>
#include "Entity.h"

class Game{
    protected:
        Entity ent1;
        Entity ent2;
        int turn;
    public:
        Game(const Entity&,const Entity&);
        void echoAttackInfo();
        bool isAnyoneDead();
        void attackPhase();
        Entity getWinner();
        void Start();
        void End();

};

#endif // GAME_HEADER
