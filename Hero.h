#ifndef HERO_HEADER
#define HERO_HEADER

#include <string>
#include "Monster.h"

class Hero : public Monster{
    protected:
        float ExperienceCurrent;

        void addExperience(float);

    public:
        Hero(const int health, const int attackDamage, const std::string& name, const float attackSpeed) : Monster(health, attackDamage, name, attackSpeed), ExperienceCurrent(0) {};
        Hero(Monster monster) : Monster(monster), ExperienceCurrent(0) {};
        Hero& operator=(const Monster&);
        int getLevel() const;
        void attack(Monster&);

};

#endif // HERO_HEADER
