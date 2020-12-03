#include <string>

#include "PreparedGame.h"
#include "MarkedMap.h"
#include "JSON.h"
#include "Renderer.h"

PreparedGame::PreparedGame(std::string mapjson) {
    JSON json = JSON::parseFromFile(mapjson);

    std::string mapfilename = json.get<std::string>("map");
    MarkedMap map(mapfilename);
    this->setMap(map);

    std::string herofile = json.get<std::string>("hero");
    Hero hero = Hero::parse(herofile);
    Position heroPosition = map.getHeroPosition();
    this->putHero(hero, heroPosition.x, heroPosition.y);

    int maxMonsterNumber = map.getMaxMonsterNumber();
    std::string actualMosnterFile;

    for (int i = 1; i <= maxMonsterNumber; i++) {
        actualMosnterFile = json.get<std::string>("monster-" + std::to_string(i));
        Monster monster = Monster::parse(actualMosnterFile);
        std::list<Position> monsterPositions = map.getMonsterPositions((char)(i + '0'));

        for (auto& pos : monsterPositions) {
            this->putMonster(monster, pos.x, pos.y);
        }
    }

    std::string wall_texture = json.get<std::string>("wall_texture");
    this->wallTexture = wall_texture;

    std::string free_texture = json.get<std::string>("free_texture");
    this->freeTexture = free_texture;
}

void PreparedGame::run(){
    Game::run();
}

void PreparedGame::registerRenderer(Renderer* renderer){
    this->renderers.push_back(renderer);
}

void PreparedGame::render(){
    Game *game = this;

    for (unsigned int i = 0; i < this->renderers.size(); i++) {
        this->renderers[i]->render((Game)(*game));
    }
}
