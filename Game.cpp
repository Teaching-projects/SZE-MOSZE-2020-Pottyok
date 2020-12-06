#include <string>
#include <iostream>
#include <regex>

#include "Game.h"
#include "Map.h"
#include "Renderer.h"

Game::Game() {

}

Game::Game(std::string mapfilename) {
    Map map(mapfilename);
    setMap(map);
}

void Game::setMap(Map &map) {
    if (this->loop_cycle > 0) throw GameAlreadyStartedException("Can't set map after the game has started.");
    this->map = map;
}

void Game::putHero(Hero &hero, int x, int y) {
    if (map.get(x, y) == Map::Wall) throw OccupiedException("Can't place entity on wall.");
    if (!isMapSet()) throw WrongIndexException("Map is not set.");
    if (isHeroSet()) throw AlreadyHasUnitsException("The hero is already set.");
    if (this->loop_cycle > 0) throw GameAlreadyStartedException("Can't set hero after the game has started.");

    MapEntity _hero(x, y, hero);
    this->heroes.push_back(_hero);
}

void Game::putMonster(Monster &monster, int x, int y) {
    if (map.get(x, y) == Map::Wall) throw OccupiedException("Can't place entity on wall.");
    if (!isMapSet()) throw WrongIndexException("Map is not set.");
    
    MapEntity _monster(x, y, monster);
    this->monsters.push_back(_monster);
}



void Game::run() {
    if (!isMapSet()) throw NotInitializedException("Map is not set.");
    if (!isHeroSet()) throw NotInitializedException("Hero is not set.");

    std::string input;

    while (areMonstersAlive() && areHeroesAlive()) {
        this->loop_cycle++;
        render();
        do{
            std::cout << "Where to go? (north, south, west, east): ";
            std::cin >> input;
        }
        while(!this->checkUserInput(input));
        this->move(input);
        this->fight();
    }

    this->loop_cycle = 0;

    if (areHeroesAlive()) {
        render();
        std::cout << std::get<Hero>(this->heroes[0].getEntity()).getName() + " cleared the map." << std::endl;
    }
    else {
        render();
        std::cout << "The hero died." << std::endl;
    }
}



bool Game::checkUserInput(std::string &input){
    std::vector<std::string> goodInputs {
        "north",
        "south",
        "east",
        "west"
    };

    if(std::find(goodInputs.begin(), goodInputs.end(),input) == goodInputs.end()){ 
        std::cout << "The given command was not found!" << std::endl;    
        return false; 
    }

    return this->isMovePossible(input);
}

bool Game::isMovePossible(std::string &input){
    MapEntity hero =  this->heroes[0];
    unsigned int currentX = hero.getX();
    unsigned int currentY = hero.getY();

    unsigned int futureX = currentX + this->movements[input]['x'];
    unsigned int futureY = currentY + this->movements[input]['y'];

    Map::type maptype = this->map.get(futureX, futureY);
    if(maptype == Map::Wall){ 
        std::cout << "The given coordinate is a wall!" << std::endl;
        return false; 
    }

    if(futureY < 0 || futureX < 0 || futureY >= this->map.getColumnCount() || futureX >= this->map.getRow(futureY).size()){ 
        std::cout << "The given coordinate is not existing!";
        return false;
    }

    return true;
}

void Game::move(std::string &input){
    MapEntity hero =  this->heroes[0];
    unsigned int currentX = hero.getX();
    unsigned int currentY = hero.getY();
    unsigned int futureX = currentX + this->movements[input]['x'];
    unsigned int futureY = currentY + this->movements[input]['y'];
    this->heroes[0].setX(futureX);
    this->heroes[0].setY(futureY);
}
void Game::fight(){
    unsigned int currentX = this->heroes[0].getX();
    unsigned int currentY = this->heroes[0].getY();
    std::vector<int> toDelete;
    for (unsigned int i = 0; i < this->monsters.size() && std::get<Hero>(this->heroes[0].getEntity()).isAlive(); i++)
    {
        MapEntity monster = this->monsters[i];
        if(currentX == monster.getX() && currentY == monster.getY()){
            Monster m = std::get<Monster>(monster.getEntity());
            std::get<Hero>(this->heroes[0].getEntity()).fightTilDeath(m);
            
            if (std::get<Hero>(this->heroes[0].getEntity()).isAlive()) {
                toDelete.push_back(i);
            }
        }
    }

    for (unsigned int i = 0; i < toDelete.size(); i++) {
        this->monsters.erase(this->monsters.begin()+(toDelete[i]-i));
    }
}


void Game::deleteAllRenderersSafely(){
    for (unsigned int i = this->renderers.size() - 1; i >= 0; i--) {
        delete this->renderers[i];
    }
}

bool Game::heroIsHere(unsigned int x,unsigned int y) const {
    MapEntity hero =  this->heroes[0];
    unsigned int currentX = hero.getX();
    unsigned int currentY = hero.getY();
    return currentX == x && currentY == y;
}
int Game::countMonstersHere(unsigned int x,unsigned int y) const {
    int monsterCount = 0;
    for (unsigned int i = 0; i < this->monsters.size(); i++)
    {
        MapEntity monster = this->monsters[i];
        if(x == monster.getX() && y == monster.getY()){
            monsterCount++;
        }
    }
    return monsterCount;
}

Monster Game::getMonsterHere(unsigned int x,unsigned int y) const {
    for (unsigned int i = 0; i < this->monsters.size(); i++)
    {
        MapEntity monster = this->monsters[i];
        if(x == monster.getX() && y == monster.getY()){
            return std::get<Monster>(monster.getEntity());
        }
    }
    throw std::runtime_error("No monster here");
}

void Game::registerRenderer(Renderer* renderer) {
    this->renderers.push_back(renderer);
}

void Game::render() {
    Game *game = this;

    for (unsigned int i = 0; i < this->renderers.size(); i++) {
        this->renderers[i]->render((Game)(*game));
    }
}



bool Game::isHeroSet() {
    return this->heroes.size() > 0;
}

bool Game::isMapSet() {
    return this->map.getColumnCount() > 0;
}

bool Game::areMonstersAlive() {
    return this->monsters.size() > 0;
}

bool Game::areHeroesAlive() {
    for (auto& a : this->heroes) {
        if (std::get<Hero>(a.getEntity()).isAlive()) return true;
    }
    return false;
}

std::vector<MapEntity> Game::getHeroes() const {
    return this->heroes;
}

std::vector<MapEntity> Game::getMonsters() const {
    return this->monsters;
}

Map Game::getMap() const {
    return this->map;
}


std::string Game::getWallTexture() const {
    return this->wallTexture;
};

std::string Game::getFreeTexture() const {
    return this->freeTexture;
};