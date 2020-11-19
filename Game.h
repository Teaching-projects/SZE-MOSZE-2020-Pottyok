/**
 * \class Game
 * 
 * \brief Game class
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/11/19 16:30
*/

#ifndef GAME_HEADER
#define GAME_HEADER

#include <string>
#include <vector>
#include <variant>

#include "Map.h"
#include "Hero.h"

class Game {
    private:
        Map map;
        std::vector<std::variant<Monster, Hero>> tiles;

    public:
        Game();
        Game(std::string mapfilename);

        void setMap(Map map);
        void putHero(Hero hero, int x, int y);
        void putMonster(Monster monster, int x, int y);
        void run();

        void printMap();


    class OccupiedException : virtual public std::runtime_error {
        public:
            explicit OccupiedException(const std::string &description) : std::runtime_error("Tile occupied: " + description) {}
    };
    class AlreadyHasHeroException : virtual public std::runtime_error {
        public:
            explicit AlreadyHasHeroException(const std::string &description) : std::runtime_error("Already has hero: " + description) {}
    };
    class AlreadyHasUnitsException : virtual public std::runtime_error {
        public:
            explicit AlreadyHasUnitsException(const std::string &description) : std::runtime_error("Already has units: " + description) {}
    };
};

#endif // GAME_HEADER