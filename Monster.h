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
#include "Damage.h"

class Monster{
    protected:
        std::string Name;       ///< Monster neve
        float Health;             ///< Monster jelenlegi eletereje
        float MaxHealth;          ///< Monster maximum eletereje
        Damage AttackDamage;       ///< Monster sebzese
        float Defense;            ///< Monster vedekezesi ereje
        float AttackSpeed;      ///< Monster ket tamadasa kozotti ido
        void damage(const float); ///< Monster jelenlegi eleterejenek csokkentese
        std::string Texture;        ///< Monster svg textúrája

    public:
        Monster(const float health /** [in] A Monster eletereje */,
                const float attackPhysicalDamage,
                const float attackMagicDamage,
                const float defense /** [in] A Monster vedekezesi ereje */,
                const std::string& name /** [in] A Monster neve */,
                const float attackSpeed /** [in] A Monster tamadasi sebessege */,
                const std::string& texture /** [in] A Monster svg textúrája */) : 
                    Name(name),
                    Health(health),
                    MaxHealth(health),
                    Defense(defense),
                    AttackSpeed(attackSpeed),
                    Texture(texture) 
                    {
                        Damage dmg = Damage();
                        dmg.magical = attackMagicDamage;
                        dmg.physical = attackPhysicalDamage;

                        this->AttackDamage = dmg;

                    };   ///< Az Monster class konstruktora
		Monster(const Monster& monster /** [in] Másolni kívánt Monster */) : Name(monster.Name), Health(monster.Health), MaxHealth(monster.MaxHealth), AttackDamage(monster.AttackDamage), Defense(monster.Defense), AttackSpeed(monster.AttackSpeed), Texture(monster.Texture) {};	///< Az Monster class copy konstruktora
        Monster& operator=(const Monster& /** [in] A Monster amivel egyenlove akarjuk tenni az objektumot */);   ///< Az Monster class egyenloseg operatora
        float getDamage(float defense = 0) const;    ///< Monster sebzeset visszaado getter
        float getDefense() const;    ///< Monster vedekezesi erejet visszaado getter
        Damage getDamageStruct() const;
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

        std::string getTexture() const;


};

#endif // MONSTER_HEADER
