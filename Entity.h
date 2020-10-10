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
        Entity(const float health,const float attackDamage,const std::string& name) : Name(name), Health(health), MaxHealth(health), AttackDamage(attackDamage){};
        Entity(const Entity& entity) : Name(entity.Name), Health(entity.Health), MaxHealth(entity.MaxHealth),AttackDamage(entity.AttackDamage) {};
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
