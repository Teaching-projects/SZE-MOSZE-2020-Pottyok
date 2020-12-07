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
#include <list>
#include <map>

#include "Map.h"
#include "Hero.h"
#include "Renderer.h"

class MapEntity {
    private:
        unsigned int x;
        unsigned int y;
        std::variant<Monster, Hero> entity;
    public:
        MapEntity(unsigned int _x, unsigned int _y, std::variant<Monster, Hero> _entity) : x(_x), y(_y), entity(_entity) {};

        unsigned int getX() { return x; }
        unsigned int getY() { return y; }
        std::variant<Monster, Hero>& getEntity() { return this->entity; }

        void setX(unsigned int _x) { x = _x; }
        void setY(unsigned int _y) { y = _y; }
        void setEntity(std::variant<Monster, Hero> _entity) { entity = _entity; }
};

class Game {
    private:
        Map map;
        std::vector<MapEntity> monsters;
        std::vector<MapEntity> heroes;
        std::map<std::string, std::map<char,int>> movements = {
            { "north", {{'x', 0},{'y', -1}} },
            { "east",  {{'x', 1},{'y', 0}} },
            { "west",  {{'x', -1},{'y', 0}} },
            { "south",  {{'x', 0},{'y', 1}} }
        };
        unsigned int loop_cycle = 0;

    protected:
        std::string wallTexture;
        std::string freeTexture;
        std::list<Renderer*> renderers;

    public:
        Game();
        explicit Game(std::string mapfilename);
        ~Game(){
            for (auto &&renderer : this->renderers)
            {
                delete renderer;
            }
        }

        void setMap(Map &map);
        void putHero(Hero &hero, int x, int y);
        void putMonster(Monster &monster, int x, int y);
        void run();

        virtual void render();
        void registerRenderer(Renderer*);
        std::string getMapRow(unsigned int rowId);  
        bool isHeroSet();
        bool isMapSet();
        bool areMonstersAlive();
        bool areHeroesAlive();
        bool checkUserInput(std::string &input);
        bool isMovePossible(std::string &input);
        void move(std::string &input);
        void fight();
        bool heroIsHere(unsigned int x,unsigned int y) const;
        int countMonstersHere(unsigned int x,unsigned int y) const;
        

        
        std::string getWallTexture() const;
        std::string getFreeTexture() const;
        std::vector<MapEntity> getHeroes() const;
        std::vector<MapEntity> getMonsters() const;
        Map getMap() const;
        Monster getMonsterHere(unsigned int, unsigned int) const;
        


    class WrongIndexException : virtual public std::runtime_error {
        public:
            explicit WrongIndexException(const std::string &description) : std::runtime_error("Index out of range: " + description) {}
    };
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
    class NotInitializedException : virtual public std::runtime_error {
        public:
            explicit NotInitializedException(const std::string &description) : std::runtime_error("Requirement for run() is missing: " + description) {}
    };
    class GameAlreadyStartedException : virtual public std::runtime_error {
        public:
            explicit GameAlreadyStartedException(const std::string &description) : std::runtime_error("The game has already started: " + description) {}
    };
};

#endif // GAME_HEADER