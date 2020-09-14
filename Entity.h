#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <string>

class Entity{
    protected:
        const std::string Name;
        float Health;
        float MaxHealth;
        float AttackDamage;
        bool isDead;

    public:
        Entity(const float,const float,const std::string);
        void damage(const float);
        float getAttackDamage();
        std::string getName();
        void attack(Entity&);
        float getHealth();
        bool getIsDead();
        void die();

};

#endif // ENTITY_HEADER
