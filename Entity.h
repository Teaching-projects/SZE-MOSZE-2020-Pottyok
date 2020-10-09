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
        Entity(const int,const int,const std::string);
        Entity& operator=(const Entity&);
        void damage(const int);
        int getAttackDamage() const;
        std::string getName() const;
        void attack(Entity&);
        int getHealth() const;
        bool getIsDead() const;
        void die();

        static Entity parseUnit(const std::string&);


};

#endif // ENTITY_HEADER
