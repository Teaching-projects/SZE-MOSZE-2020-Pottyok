#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <string>

class Entity{
    protected:
        std::string Name;
        int Health;
        int MaxHealth;
        int AttackDamage;

    public:
        Entity(const int,const int,const std::string);
        Entity& operator=(const Entity&);
        void damage(const int);
        int getAttackDamage();
        const std::string getName();
        static Entity parseUnit(const std::string&);
        void attack(Entity&);
        int getHealth();
        bool getIsDead();
        void die();


};

#endif // ENTITY_HEADER
