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

class PreparedGame : private Game
{
public:
    explicit PreparedGame(std::string mapjson /** [in] A használni kívánt beállítások json fájlja */); ///< PreparedMap explicit konstruktora
    void run(); ///< PreparedMap játék loop indítása 
    void registerRenderer(Renderer *); ///< Renderer regisztrálása a kirajzolók közé
};

#endif // PREPAREDGAME_HEADER