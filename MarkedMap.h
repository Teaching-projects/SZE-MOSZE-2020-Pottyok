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
    Position(int _x, int _y){
        this->x = _x;
        this->y = _y;
    };
};


class MarkedMap : public Map {

    private:
        Position heroPosition;
        std::map<char, std::list<Position>> monsterPositions;

    public:
        explicit MarkedMap(std::string &fileName);
        Position getHeroPosition() const;
        std::list<Position> getMonsterPositions(char c);
        int getMaxMonsterNumber();
};

#endif