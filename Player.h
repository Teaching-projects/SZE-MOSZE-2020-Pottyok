#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <string>
#include "Entity.h"

class Player : public Entity{
    protected:
        float ExperienceCurrent;

        void addExperience(float);

    public:
        Player(const int health,const int attackDamage,const std::string& name) : Entity(health, attackDamage, name), ExperienceCurrent(0) {};
        Player(const Player& other) : Entity(other.Health, other.AttackDamage, other.Name), ExperienceCurrent(other.ExperienceCurrent){};
        Player& operator=(const Entity&);
        int getLevel() const;
        void attack(Entity&);

};

#endif // PLAYER_HEADER
