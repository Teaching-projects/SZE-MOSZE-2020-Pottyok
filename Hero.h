#ifndef HERO_HEADER
#define HERO_HEADER

#include <string>
#include "Monster.h"

class Hero : public Monster{
    protected:
        float ExperienceCurrent;
        float ExperiencePerLevel;
        float HealthPointBonusPerLevel;
        float DamageBonusPerLevel;
        float ColdownMultiplierPerLevel;

        void addExperience(float);

    public:
        Hero(const float health,
            const float attackDamage,
            const std::string& name,
            const float attackSpeed,
            float ExperiencePerLevel,
            float HealthPointBonusPerLevel,
            float DamageBonusPerLevel,
            float ColdownMultiplierPerLevel) 
                : Monster(health, attackDamage, name, attackSpeed),
                ExperienceCurrent(0),
                ExperiencePerLevel(ExperiencePerLevel),
                HealthPointBonusPerLevel(HealthPointBonusPerLevel),
                DamageBonusPerLevel(DamageBonusPerLevel),
                ColdownMultiplierPerLevel(ColdownMultiplierPerLevel)
                {};

        Hero(Monster monster)
            : Monster(monster), 
            ExperienceCurrent(0),
            ExperiencePerLevel(0),
            HealthPointBonusPerLevel(0),
            DamageBonusPerLevel(0),
            ColdownMultiplierPerLevel(0)
            {};
            
        Hero& operator=(const Monster&);
        int getLevel() const;
        void attack(Monster&);
        static Hero parse(const std::string&);
};

#endif // HERO_HEADER
