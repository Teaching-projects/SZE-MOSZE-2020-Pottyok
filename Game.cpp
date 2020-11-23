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

}

void Game::printMap() {
    std::regex replaceWall("#");
    std::regex replaceFree("\\s");

    std::cout << "╔";
    for (unsigned int i = 0; i < map.getLongestRowCount(); i++) { std::cout << "═"; }
    std::cout << "╗" << std::endl;

    for (unsigned int i = 0; i < map.getColumnCount(); i++) {
        std::cout << "║";
        std::cout << std::regex_replace(std::regex_replace(map.getRow(i), replaceFree, "░"), replaceWall, "█");
        for (unsigned int j = 0; j < map.getLongestRowCount() - map.getRow(i).length(); j++) {
            std::cout << "█";
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