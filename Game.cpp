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

    const unsigned int size_y = map.getColumnCount();
    const unsigned int size_x = map.getLongestRowCount();
    std::vector<std::variant<Monster, Hero>> tiles[size_y][size_x];
}

void Game::setMap(Map map) {
    this->map = map;
}

void Game::putHero(Hero hero, int x, int y) {

}

void Game::putMonster(Monster monster, int x, int y) {

}

void Game::run() {

}

void Game::printMap() {
    std::regex replaceWall("#");
    std::regex replaceFree("\\s");

    std::cout << "╔";
    for (int i = 0; i < map.getLongestRowCount(); i++) { std::cout << "═"; }
    std::cout << "╗" << std::endl;

    for (int i = 0; i < map.getColumnCount(); i++) {
        std::cout << "║";
        std::cout << std::regex_replace(std::regex_replace(map.getRow(i), replaceFree, "░"), replaceWall, "█");
        for (int j = 0; j < map.getLongestRowCount() - map.getRow(i).length(); j++) {
            std::cout << "█";
        }
        std::cout << "║" << std::endl;
    }

    std::cout << "╚";
    for (int i = 0; i < map.getLongestRowCount(); i++) { std::cout << "═"; }
    std::cout << "╝" << std::endl;
}