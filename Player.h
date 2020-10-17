#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <string>
#include "Entity.h"

class Player : public Entity{
    protected:
        float ExperienceCurrent;

        void addExperience(float);

    public:
        Player(const int health, const int attackDamage, const std::string& name, const float attackSpeed) : Entity(health, attackDamage, name, attackSpeed), ExperienceCurrent(0) {};
        Player& operator=(const Entity&);
        int getLevel() const;
        void attack(Entity&);

};

#endif // PLAYER_HEADER
