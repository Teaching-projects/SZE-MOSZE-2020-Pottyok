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
        float DamageBonusPerLevel; ///< Hero szintlepesenkent kapott tamadasi ero bonusza
        float DefenseBonusPerLevel; ///< Hero szintlepesenkent kapott vedekezesi ero bonusza
        float ColdownMultiplierPerLevel; ///< Hero szintlepesenkent kapott cooldown bonusza

        void addExperience(float /** [in] A kapott tapasztalati pontok */); ///< Hero tapasztalati pontjainak novelese, elvegzi a szintlepest is

    public:
        Hero(const float health /** [in] A Hero kezdo eletereje */,
            const float attackDamage /** [in] A Hero kezdo tamadasi ereje */,
            const float defense /** [in] A Hero kezdo tamadasi ereje */,
            const std::string& name /** [in] A Hero neve */,
            const float attackSpeed /** [in] A Hero kezdo tamadasi sebessege */,
            float ExperiencePerLevel /** [in] A Hero szintlepesehez szukseges tapasztalati pontjainak mennyisege */,
            float HealthPointBonusPerLevel /** [in] A Hero szintlepesenkent kapott eletero bonusza */,
            float DamageBonusPerLevel /** [in] A Hero szintlepesenkent kapott tamadasi ero bonusza */,
            float DefenseBonusPerLevel /** [in] A Hero szintlepesenkent kapott vedekezesi ero bonusza */,
            float ColdownMultiplierPerLevel /** [in] A Hero szintlepesenkent kapott cooldown bonusza */) 
                : Monster(health, attackDamage, defense, name, attackSpeed),
                ExperienceCurrent(0),
                ExperiencePerLevel(ExperiencePerLevel),
                HealthPointBonusPerLevel(HealthPointBonusPerLevel),
                DamageBonusPerLevel(DamageBonusPerLevel),
                DefenseBonusPerLevel(DefenseBonusPerLevel),
                ColdownMultiplierPerLevel(ColdownMultiplierPerLevel)
                {}; ///< Hero osztaly konstruktora

        Hero(Monster monster /** [in] A Monster, ami alapjan letre akarjuk hozni a Hero-t */)
            : Monster(monster), 
            ExperienceCurrent(0),
            ExperiencePerLevel(0),
            HealthPointBonusPerLevel(0),
            DamageBonusPerLevel(0),
            DefenseBonusPerLevel(0),
            ColdownMultiplierPerLevel(0)
            {}; ///< Hero osztaly konstruktora Monster objektumbol

        Hero& operator=(const Monster& /** [in] A Monster, amivel egyenlove akarjuk tenni a Hero objektumot */); ///< Hero objektum egyenlove tetele egy Monster objektummal
        int getLevel() const; ///< A Hero szintjet adja vissza
        void attack(Monster& /** [in] A Monster, amit megtamad a Hero objektum*/); ///< Hero tamadasa, ami soran egy Monstert tamad meg
        static Hero parse(const std::string& /** [in] std::string, ami megadja a fajl eleresi utvonalat*/); ///< Hero letrehozasa egy JSON fajl alapjan
};

#endif // HERO_HEADER
