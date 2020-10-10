#ifndef GAME_HEADER
#define GAME_HEADER
#include <vector>
#include "Entity.h"
#include "Player.h"

class Game{
    protected:
        Player ent1;
        Player ent2;
        int turn;
    public:
        Game(const Player&,const Player&);
        bool isAnyoneDead() const;
        void attackPhase();
        Entity getWinner() const;
        void Start();
        void End();

};

#endif // GAME_HEADER
