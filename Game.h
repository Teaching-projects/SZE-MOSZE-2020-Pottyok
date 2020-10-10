/**
 * \class Game
 * 
 * \brief Game class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/10/10 12:25
*/

#ifndef GAME_HEADER
#define GAME_HEADER
#include <vector>
#include "Entity.h"

class Game{
    protected:
        Entity ent1;    ///< A jatekban resztvevo elso Entity
        Entity ent2;    ///< A jatekban resztvevo masodik Entity
    public:
        /**
         * \brief A Game class konstruktora
         * \param Entity A jatekban resztvevo Entity (mint tamado)
         * \param Entity A jakekban resztvevo Entity (mint ellenfel)
        */
        Game(const Entity&,const Entity&);
        bool isAnyoneDead() const;  ///< Lekeri, hogy a ket Entity kozul halott-e valamelyik
        Entity getWinner() const;   ///< Lekeri, hogy melyik Entity nyerte a harcot
        void Start();   ///< Elinditja a harcot a ket Entity kozott, aminek a vegen az End() kerul meghivasra
        void End(); ///< Ket Entity kozotti harc vegen kiirja annak vegeredmenyet

};

#endif // GAME_HEADER
