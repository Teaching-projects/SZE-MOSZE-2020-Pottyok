#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <string>
#include "Entity.h"

class Player : public Entity{
    protected:
        float ExperienceCurrent;
        float ExperienceAtLastRound;
        float ExperienceAtFightStart;

        void addExperience(float);

    public:
        Player(const int,const int,const std::string);
        Player& operator=(const Player&);
        int getLevel() const;

};

#endif // PLAYER_HEADER
