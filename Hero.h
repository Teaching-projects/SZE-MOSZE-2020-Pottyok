/**
 * \class Hero
 * 
 * \brief Hero class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/10/30 12:25
*/
#ifndef HERO_HEADER
#define HERO_HEADER

#include <string>
#include "Monster.h"

class Hero : public Monster{
    protected:
        float ExperienceCurrent; ///< Hero jelenlegi tapasztalatpontja
        float ExperiencePerLevel; ///< Hero egy szinthez szukseges tapasztalati pontjai
        float HealthPointBonusPerLevel; ///< Hero szintlepesenkent kapott eletero bonusza
        float MagicDamageBonusPerLevel; 
        float PhysicalDamageBonusPerLevel; 
        float DefenseBonusPerLevel; ///< Hero szintlepesenkent kapott vedekezesi ero bonusza
        float CooldownMultiplierPerLevel; ///< Hero szintlepesenkent kapott cooldown bonusza
        int LightRadius;
        int LightRadiusBonusPerLevel;

        void addExperience(float /** [in] A kapott tapasztalati pontok */); ///< Hero tapasztalati pontjainak novelese, elvegzi a szintlepest is

    public:
        Hero(const float health /** [in] A Hero kezdo eletereje */,
            const float attackPhysicalDamage,
            const float attackMagicDamage,
            const float defense /** [in] A Hero kezdo tamadasi ereje */,
            const std::string& name /** [in] A Hero neve */,
            const float attackSpeed /** [in] A Hero kezdo tamadasi sebessege */,
            float ExperiencePerLevel /** [in] A Hero szintlepesehez szukseges tapasztalati pontjainak mennyisege */,
            float HealthPointBonusPerLevel /** [in] A Hero szintlepesenkent kapott eletero bonusza */,
            float PhysicalDamageBonusPerLevel,
            float MagicDamageBonusPerLevel,
            float DefenseBonusPerLevel /** [in] A Hero szintlepesenkent kapott vedekezesi ero bonusza */,
            float CooldownMultiplierPerLevel /** [in] A Hero szintlepesenkent kapott cooldown bonusza */,
            int LightRadius,
            int LightRadiusBonusPerLevel,
            const std::string texture) 
                : Monster(health, attackPhysicalDamage, attackMagicDamage, defense, name, attackSpeed, texture),
                ExperienceCurrent(0),
                ExperiencePerLevel(ExperiencePerLevel),
                HealthPointBonusPerLevel(HealthPointBonusPerLevel),
                MagicDamageBonusPerLevel(MagicDamageBonusPerLevel),
                PhysicalDamageBonusPerLevel(PhysicalDamageBonusPerLevel),
                DefenseBonusPerLevel(DefenseBonusPerLevel),
                CooldownMultiplierPerLevel(CooldownMultiplierPerLevel),
                LightRadius(LightRadius),
                LightRadiusBonusPerLevel(LightRadiusBonusPerLevel)
                {}; ///< Hero osztaly konstruktora

        explicit Hero(Monster monster /** [in] A Monster, ami alapjan letre akarjuk hozni a Hero-t */)
            : Monster(monster), 
            ExperienceCurrent(0),
            ExperiencePerLevel(0),
            HealthPointBonusPerLevel(0),
            MagicDamageBonusPerLevel(0),
            PhysicalDamageBonusPerLevel(0),
            DefenseBonusPerLevel(0),
            CooldownMultiplierPerLevel(0),
            LightRadius(0),
            LightRadiusBonusPerLevel(0)
            {}; ///< Hero osztaly konstruktora Monster objektumbol

        Hero& operator=(const Monster& /** [in] A Monster, amivel egyenlove akarjuk tenni a Hero objektumot */); ///< Hero objektum egyenlove tetele egy Monster objektummal
        int getLevel() const; ///< A Hero szintjet adja vissza
        int getLightRadius() const;
        void attack(Monster& /** [in] A Monster, amit megtamad a Hero objektum*/) override; ///< Hero tamadasa, ami soran egy Monstert tamad meg
        static Hero parse(const std::string& /** [in] std::string, ami megadja a fajl eleresi utvonalat*/); ///< Hero letrehozasa egy JSON fajl alapjan
};

#endif // HERO_HEADER
