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
#include "Renderer.h"


class PreparedGame : Game {
    private:
        std::vector<Renderer*> renderers;
        std::string wallTexture;
        std::string freeTexture;

    public:
        PreparedGame(std::string mapjson);
        void run();
        void registerRenderer(Renderer*);
        void render();
        std::string getWallTexture();
        std::string getFreeTexture();

};

#endif // PREPAREDGAME_HEADER