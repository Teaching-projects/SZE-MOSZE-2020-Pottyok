#include "Game.h"
#include "Entity.h"
#include <iostream>

Game::Game (const Entity& ent1,const Entity& ent2):ent1(ent1), ent2(ent2){
    this->turn  = 0;
}

void Game::Start(){
    do {
        this->attackPhase();
        this->turn++;
    }
    while(!this->isAnyoneDead());
    this->End();
}

void Game::End(){
    std::cout << this->getWinner().getName() << " wins. Remaining HP: " << this->getWinner().getHealth() << std::endl;
}

bool Game::isAnyoneDead() const {
    return (this->ent1.getIsDead() || this->ent2.getIsDead());
}

void Game::attackPhase(){
    this->turn % 2 == 0 ? this->ent1.attack(this->ent2) : this->ent2.attack(this->ent1);
}

Entity Game::getWinner() const  {
    return this->ent1.getIsDead() ? this->ent2 : this->ent1;
}