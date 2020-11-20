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
        float Defense;            ///< Monster vedekezesi ereje
        float AttackSpeed;      ///< Monster ket tamadasa kozotti ido
        void damage(const float); ///< Monster jelenlegi eleterejenek csokkentese

    public:
        Monster(const float health /** [in] A Monster eletereje */,
                const float attackDamage /** [in] A Monster tamadasi ereje */,
                const float defense /** [in] A Monster vedekezesi ereje */,
                const std::string& name /** [in] A Monster neve */,
                const float attackSpeed /** [in] A Monster tamadasi sebessege */) : 
                    Name(name),
                    Health(health),
                    MaxHealth(health),
                    AttackDamage(attackDamage),
                    Defense(defense),
                    AttackSpeed(attackSpeed) 
                    {};   ///< Az Monster class konstruktora
		Monster(const Monster& monster /** [in] Másolni kívánt Monster */) : Name(monster.Name), Health(monster.Health), MaxHealth(monster.MaxHealth), AttackDamage(monster.AttackDamage), Defense(monster.Defense), AttackSpeed(monster.AttackSpeed) {};	///< Az Monster class copy konstruktora
        Monster& operator=(const Monster& /** [in] A Monster amivel egyenlove akarjuk tenni az objektumot */);   ///< Az Monster class egyenloseg operatora
        float getDamage() const;    ///< Monster sebzeset visszaado getter
        float getDefense() const;    ///< Monster vedekezesi erejet visszaado getter
        float getAttackCoolDown() const;   ///< Monster ket tamadas kozotti idot visszaado getter
        std::string getName() const;    ///< Monster nevet visszaado getter
        virtual void attack(Monster& /** [in] A megtamadni kivant Monster */);   ///< Masik Monster sebzese a damage() meghivasaval
        float getHealthPoints() const;  ///< Monster jelenlegi eleterejet visszaado getter
		float getMaxHealthPoints() const;	///< Monster maximum eleterejet visszaado getter
        
        /**
         * \brief Visszaadja, hogy az Monster halott-e
         * \return True, ha az Monster jelenlegi eletereje 0, mas esetben False
        */
        bool getIsDead() const;
        bool isAlive() const; ///< Megadja, hogy a Monster eletben van-e

        void fightTilDeath(Monster& /** [in] Az Monster akivel a harcot kezdemenyezzuk */);    ///< Harc kezdemenyezese egy masik Monster-vel

        /**
         * \brief Monster adatainak feltoltese JSON fajl hasznalataval
         * \return Monster a JSON fajlban megadott ertekekkel
        */
        static Monster parse(const std::string&);


};

#endif // MONSTER_HEADER
