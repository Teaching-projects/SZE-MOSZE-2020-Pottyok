#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <string>

class Entity{
    protected:
        const std::string Name;
        int Health;
        int MaxHealth;
        int AttackDamage;
        bool isDead;

    public:
        Entity(const int,const int,const std::string);
        void damage(const int);
        int getAttackDamage();
        std::string getName();
        void attack(Entity&);
        int getHealth();
        bool getIsDead();
        void die();

};

#endif // ENTITY_HEADER
