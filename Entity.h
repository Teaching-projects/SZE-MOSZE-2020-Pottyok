#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <string>

class Entity{
    protected:
        std::string Name;
        float Health;
        float MaxHealth;
        float AttackDamage;

    public:
        Entity(const float,const float,const std::string);
        Entity& operator=(const Entity&);
        void damage(const float);
        float getAttackDamage() const;
        std::string getName() const;
        void attack(Entity&);
        float getHealth() const;
        float getMaxHealth() const;
        bool getIsDead() const;
        void die();

        static Entity parseUnit(const std::string&);


};

#endif // ENTITY_HEADER
