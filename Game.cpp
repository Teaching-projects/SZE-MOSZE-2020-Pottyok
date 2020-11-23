#include <string>
#include <iostream>
#include <regex>

#include "Game.h"
#include "Map.h"

Game::Game() {

}

Game::Game(std::string mapfilename) {
    Map map(mapfilename);
    setMap(map);
}

void Game::setMap(Map &map) {
    this->map = map;
}

void Game::putHero(Hero &hero, int x, int y) {
    if (map.get(x, y) == Map::Wall) throw OccupiedException("Can't place entity on wall.");
    if (!isMapSet()) throw WrongIndexException("Map is not set.");
    if (isHeroSet()) throw AlreadyHasUnitsException("The hero is already set.");

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
        printMap();
        do{
            std::cerr << "Where to go? (north, south, west, east): ";
            std::cin >> input;
        }
        while(!this->checkUserInput(input));
        this->move(input);
        this->fight();
    }

    if (areHeroesAlive()) {
        printMap();
        std::cerr << std::get<Hero>(this->heroes[0].getEntity()).getName() + " cleared the map.";
    }
    else {
        printMap();
        std::cerr << "The hero died.";
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
        std::cerr << "The given command was not found!" << std::endl;    
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
        std::cerr << "The given coordinate is a wall!" << std::endl;
        return false; 
    }

    if(futureY < 0 || futureX < 0 || futureY >= this->map.getColumnCount() || futureX >= this->map.getRow(futureY).size()){ 
        std::cerr << "The given coordinate is not existing!";
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
    MapEntity hero =  this->heroes[0];
    unsigned int currentX = hero.getX();
    unsigned int currentY = hero.getY();
    std::vector<int> toDelete;
    for (unsigned int i = 0; i < this->monsters.size() && std::get<Hero>(hero.getEntity()).isAlive(); i++)
    {
        MapEntity monster = this->monsters[i];
        if(currentX == monster.getX() && currentY == monster.getY()){
            Monster m = std::get<Monster>(monster.getEntity());
            std::get<Hero>(hero.getEntity()).fightTilDeath(m);
            
            if (std::get<Hero>(hero.getEntity()).isAlive()) {
                toDelete.push_back(i);
            }
        }
    }

    for (unsigned int i = 0; i < toDelete.size(); i++) {
        this->monsters.erase(this->monsters.begin()+(toDelete[i]-i));
    }
}

bool Game::heroIsHere(unsigned int x,unsigned int y){
    MapEntity hero =  this->heroes[0];
    unsigned int currentX = hero.getX();
    unsigned int currentY = hero.getY();
    return currentX == x && currentY == y;
}
int Game::countMonstersHere(unsigned int x,unsigned int y){
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

void Game::printMap() {
    std::cerr << "╔";
    for (unsigned int i = 0; i < map.getLongestRowCount()*2; i++) { std::cerr << "═"; }
    std::cerr << "╗" << std::endl;

    for (unsigned int i = 0; i < map.getColumnCount(); i++) {
        std::cerr << "║";
        std::string row = this->map.getRow(i);
        for (unsigned int j = 0; j < row.size(); j++)
        {
            if (this->heroIsHere(j,i)){
                std::cerr << "┣┫";
            }
            else if(this->countMonstersHere(j,i) > 0){
                std::cerr << (this->countMonstersHere(j,i) > 1 ? "MM" : "M░");
            }
            else{
                std::cerr << (this->map.get(j,i) == Map::Free ? "░░" : "██");
            }
            
        }
        
        for (unsigned int j = 0; j < map.getLongestRowCount() - map.getRow(i).length(); j++) {
            std::cerr << "██";
        }
        std::cerr << "║" << std::endl;
    }

    std::cerr << "╚";
    for (unsigned int i = 0; i < map.getLongestRowCount()*2; i++) { std::cerr << "═"; }
    std::cerr << "╝" << std::endl;
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