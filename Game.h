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
#include "Player.h"

class Game{
    protected:
        Player ent1;    ///< A jatekban resztvevo elso Player
        Player ent2;    ///< A jatekban resztvevo masodik Player
    public:
        /**
         * \brief A Game class konstruktora
         * \param Player A jatekban resztvevo Player (mint tamado)
         * \param Player A jakekban resztvevo Player (mint ellenfel)
        */
        Game(const Player&,const Player&);
        bool isAnyoneDead() const;  ///< Lekeri, hogy a ket Player kozul halott-e valamelyik
        Entity getWinner() const;   ///< Lekeri, hogy melyik Entity nyerte a harcot
        void Start();   ///< Elinditja a harcot a ket Player kozott, aminek a vegen az End() kerul meghivasra
        void End(); ///< Ket Player kozotti harc vegen kiirja annak vegeredmenyet

};

#endif // GAME_HEADER
