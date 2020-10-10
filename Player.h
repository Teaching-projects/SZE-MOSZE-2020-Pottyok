#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <string>
#include "Entity.h"

class Player : public Entity{
    protected:
        float ExperienceCurrent;
        float ExperienceAtLastRound;
        float ExperienceStartOfFight;

        void addExperience(float);
        void looseGainedLevels();

    public:
        Player(const int,const int,const std::string);
        Player& operator=(const Player&);
        Player& operator=(const Entity&);
        int getLevel() const;
        void attack(Entity&);

};

#endif // PLAYER_HEADER
