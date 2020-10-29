/**
 * \class Monster
 * 
 * \brief Monster class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/10/10 12:25
*/

#ifndef MONSTER_HEADER
#define MONSTER_HEADER

#include <string>

class Monster{
    protected:
        std::string Name;       ///< Monster neve
        float Health;             ///< Monster jelenlegi eletereje
        float MaxHealth;          ///< Monster maximum eletereje
        float AttackDamage;       ///< Monster sebzese
        float AttackSpeed;      ///< Monster ket tamadasa kozotti ido
        void damage(const float); ///< Monster jelenlegi eleterejenek csokkentese

    public:
        Monster(const float health,const float attackDamage,const std::string& name, const float attackSpeed) : Name(name), Health(health), MaxHealth(health), AttackDamage(attackDamage), AttackSpeed(attackSpeed) {};   ///< Az Monster class konstruktora
		Monster(const Monster& monster) : Name(monster.Name), Health(monster.Health), MaxHealth(monster.MaxHealth), AttackDamage(monster.AttackDamage), AttackSpeed(monster.AttackSpeed) {};	///< Az Monster class copy konstruktora
        Monster& operator=(const Monster&);   ///< Az Monster class egyenloseg operatora
        float getAttackDamage() const;    ///< Monster sebzeset visszaado getter
        float getAttackSpeed() const;   ///< Monster ket tamadas kozotti idot visszaado getter
        std::string getName() const;    ///< Monster nevet visszaado getter
        virtual void attack(Monster& /** [in] A megtamadni kivant Monster */);   ///< Masik Monster sebzese a damage() meghivasaval
        float getHealth() const;  ///< Monster jelenlegi eleterejet visszaado getter
		float getMaxHealth() const;	///< Monster maximum eleterejet visszaado getter
        
        /**
         * \brief Visszaadja, hogy az Monster halott-e
         * \return True, ha az Monster jelenlegi eletereje 0, mas esetben False
        */
        bool getIsDead() const;

        void fightLoop(Monster& /** [in] Az Monster akivel a harcot kezdemenyezzuk */);    ///< Harc kezdemenyezese egy masik Monster-vel

        /**
         * \brief Monster adatainak feltoltese JSON fajl hasznalataval
         * \return Monster a JSON fajlban megadott ertekekkel
        */
        static Monster parseUnit(const std::string&);


};

#endif // MONSTER_HEADER
