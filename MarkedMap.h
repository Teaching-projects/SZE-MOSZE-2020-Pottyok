/**
 * \class MarkedMap
 * 
 * \brief MarkedMap class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/11/25 14:30
*/
#ifndef MARKED_MAP_H
#define MARKED_MAP_H

#include "Map.h"
#include <string>
#include <list>
#include <map>

struct Position
{
    int x = 0;
    int y = 0;
    Position(){};
    Position(int _x, int _y)
    {
        this->x = _x;
        this->y = _y;
    };
};

class MarkedMap : public Map
{

private:
    Position heroPosition; ///< A Hero pozíciója
    std::map<char, std::list<Position>> monsterPositions; ///< Egy std::map a monsterek pozíciójiról

public:
    explicit MarkedMap(std::string &fileName /** [in] A MarkedMap adatait tartalmazó fájl elérési útvonala */); ///< Explicit konstruktor
    Position getHeroPosition() const; ///< Visszaadja a Hero jelenlegi pozícióját
    std::list<Position> getMonsterPositions(char c /** [in] Azonosító */); ///< Visszadja az adott azonosítójú Monster-ek listáját
    int getMaxMonsterNumber(); ///< Visszadja a Monster-ek számát
};

#endif