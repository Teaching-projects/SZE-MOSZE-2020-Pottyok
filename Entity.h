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
        std::string getName();
        float getHealth();
        float getAttackDamage();
        void damage(const float);
        void attack(Entity&);
        void die();
        bool getIsDead();

};

#endif // ENTITY_HEADER
