/**
 * \class PreparedGame
 * 
 * \brief PreparedGame class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/11/30 13:30
*/

#ifndef PREPAREDGAME_HEADER
#define PREPAREDGAME_HEADER

#include <string>
#include <map>

#include "Game.h"
#include "MarkedMap.h"

class PreparedGame : private Game {
    public:
        PreparedGame(std::string mapjson);
        void run();
        void registerRenderer(Renderer*);
};

#endif // PREPAREDGAME_HEADER