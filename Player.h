#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <string>
#include "Monster.h"

class Player : public Monster{
    protected:
        float ExperienceCurrent;

        void addExperience(float);

    public:
        Player(const int health, const int attackDamage, const std::string& name, const float attackSpeed) : Monster(health, attackDamage, name, attackSpeed), ExperienceCurrent(0) {};
        Player& operator=(const Monster&);
        int getLevel() const;
        void attack(Monster&);

};

#endif // PLAYER_HEADER
