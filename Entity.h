#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <string>

class Entity{
    protected:
        std::string Name;
        int Health;
        int MaxHealth;
        int AttackDamage;
        float AttackSpeed;
        void damage(const int);

    public:
        Entity(const int, const int, const std::string, const float);
        Entity& operator=(const Entity&);
        int getAttackDamage() const;
        float getAttackSpeed() const;
        std::string getName() const;
        void attack(Entity&);
        int getHealth() const;
        bool getIsDead() const;

        void fightLoop(Entity&);

        static Entity parseUnit(const std::string&);


};

#endif // ENTITY_HEADER
