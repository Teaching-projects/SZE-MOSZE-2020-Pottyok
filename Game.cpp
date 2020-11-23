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

    isHeroSet();
}

void Game::setMap(Map map) {
    this->map = map;
}

void Game::putHero(Hero hero, int x, int y) {
    if (map.get(x, y) == Map::Wall) throw OccupiedException("Can't place entity on wall.");
    if (isMapSet()) throw WrongIndexException("Map is not set.");
    if (isHeroSet()) throw AlreadyHasUnitsException("The hero is already set.");

    MapEntity _hero(x, y, hero);
    this->heroes.push_back(_hero);
}

void Game::putMonster(Monster monster, int x, int y) {
    if (map.get(x, y) == Map::Wall) throw OccupiedException("Can't place entity on wall.");
    if (isMapSet()) throw WrongIndexException("Map is not set.");
    
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
            std::cout << "Where to go? (north, south, west, east): ";
            std::cin >> input;
        }
        while(!this->checkUserInput(input));

    }

    if (areHeroesAlive()) {
        std::cout << std::get<Hero>(this->heroes[0].getEntity()).getName() + " cleared the map.";
    }
    else {
        std::cout << "The hero died.";
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
        std::cout << "The given coordinate is a wall!";
        return false; 
    }

    if(futureY < 0 || futureX < 0 || futureY >= this->map.getColumnCount() || futureX >= this->map.getRow(futureY).size()){ 
        std::cout << "The given coordinate is not existing!";
        return false;
    }

    return true;

}

void Game::printMap() {
    std::regex replaceWall("#");
    std::regex replaceFree("\\s");

    std::cout << "╔";
    for (unsigned int i = 0; i < map.getLongestRowCount(); i++) { std::cout << "═"; }
    std::cout << "╗" << std::endl;

    for (unsigned int i = 0; i < map.getColumnCount(); i++) {
        std::cout << "║";
        std::cout << std::regex_replace(std::regex_replace(map.getRow(i), replaceFree, "░░"), replaceWall, "██");
        for (unsigned int j = 0; j < map.getLongestRowCount() - map.getRow(i).length(); j++) {
            std::cout << "██";
        }
        std::cout << "║" << std::endl;
    }

    std::cout << "╚";
    for (unsigned int i = 0; i < map.getLongestRowCount(); i++) { std::cout << "═"; }
    std::cout << "╝" << std::endl;
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