#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <string>
#include "Entity.h"

class Player : public Entity{
    protected:
        int Level;
        float Experience;

        void addExperience(float);

    public:
        Player(const int,const int,const std::string);
        Player& operator=(const Player&);

};

#endif // PLAYER_HEADER
