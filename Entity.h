#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <string>

class Entity{
    protected:
        std::string Name;
        int Health;
        int MaxHealth;
        int AttackDamage;
        int AttackSpeed;

    public:
        Entity(const int, const int, const std::string, const int);
        Entity& operator=(const Entity&);
        void damage(const int);
        int getAttackDamage() const;
        int getAttackSpeed() const;
        std::string getName() const;
        void attack(Entity&);
        int getHealth() const;
        bool getIsDead() const;

        static Entity parseUnit(const std::string&);


};

#endif // ENTITY_HEADER
