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
#include "Monster.h"
#include "Hero.h"

class Game{
    protected:
        Hero ent1;    ///< A jatekban resztvevo elso Hero
        Hero ent2;    ///< A jatekban resztvevo masodik Hero
    public:
        /**
         * \brief A Game class konstruktora
         * \param Hero A jatekban resztvevo Hero (mint tamado)
         * \param Hero A jakekban resztvevo Hero (mint ellenfel)
        */
        Game(const Hero&,const Hero&);
        bool isAnyoneDead() const;  ///< Lekeri, hogy a ket Hero kozul halott-e valamelyik
        Monster getWinner() const;   ///< Lekeri, hogy melyik Monster nyerte a harcot
        void Start();   ///< Elinditja a harcot a ket Hero kozott, aminek a vegen az End() kerul meghivasra
        void End(); ///< Ket Hero kozotti harc vegen kiirja annak vegeredmenyet

};

#endif // GAME_HEADER
