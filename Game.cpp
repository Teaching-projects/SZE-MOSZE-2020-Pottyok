#include "Game.h"
#include "Entity.h"
#include <iostream>

Game::Game(const Entity& ent1, const Entity& ent2) :ent1(ent1), ent2(ent2) {}

void Game::Start(){

    ent1.fightLoop(ent2);
    this->End();
}

void Game::End(){
    std::cout << this->getWinner().getName() << " wins. Remaining HP: " << this->getWinner().getHealth() << std::endl;
}

bool Game::isAnyoneDead() const {
    return (this->ent1.getIsDead() || this->ent2.getIsDead());
}

Entity Game::getWinner() const  {
    return this->ent1.getIsDead() ? this->ent2 : this->ent1;
}