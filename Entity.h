/**
 * \class Entity
 * 
 * \brief Entity class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/10/10 12:25
*/

#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <string>

class Entity{
    protected:
        std::string Name;       ///< Entity neve
        int Health;             ///< Entity jelenlegi eletereje
        int MaxHealth;          ///< Entity maximum eletereje
        int AttackDamage;       ///< Entity sebzese
        float AttackSpeed;      ///< Entity ket tamadasa kozotti ido
        void damage(const int); ///< Entity jelenlegi eleterejenek csokkentese

    public:
        Entity(const int, const int, const std::string, const float);   ///< Az Entity class konstruktora
        Entity& operator=(const Entity&);   ///< Az Entity class konstruktora
        int getAttackDamage() const;    ///< Entity sebzeset visszaado getter
        float getAttackSpeed() const;   ///< Entity ket tamadas kozotti idot visszaado getter
        std::string getName() const;    ///< Entity nevet visszaado getter
        void attack(Entity& /** [in] A megtamadni kivant Entity */);   ///< Masik Entity sebzese a damage() meghivasaval
        int getHealth() const;  ///< Entity jelenlegi eleterejet visszaado getter
        
        /**
         * \brief Visszaadja, hogy az Entity halott-e
         * \return True, ha az Entity jelenlegi eletereje 0, mas esetben False
        */
        bool getIsDead() const;

        void fightLoop(Entity& /** [in] Az Entity akivel a harcot kezdemenyezzuk */);    ///< Harc kezdemenyezese egy masik Entity-vel

        /**
         * \brief Entity adatainak feltoltese JSON fajl hasznalataval
         * \return Entity a JSON fajlban megadott ertekekkel
        */
        static Entity parseUnit(const std::string&);


};

#endif // ENTITY_HEADER
