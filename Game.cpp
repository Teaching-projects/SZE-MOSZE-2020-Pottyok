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
    this->echoAttackInfo();
    std::cout << (this->ent2.getIsDead() ? this->ent2.getName() : this->ent1.getName()) << " died. " << this->getWinner().getName() << " wins.";
}

bool Game::isAnyoneDead(){
    return (this->ent1.getIsDead() || this->ent2.getIsDead());
}

void Game::attackPhase(){
    this->echoAttackInfo();
    this->turn % 2 == 0 ? this->ent1.attack(this->ent2) : this->ent2.attack(this->ent1);
}

Entity Game::getWinner(){
    return this->ent1.getIsDead() ? this->ent2 : this->ent1;
}

void Game::echoAttackInfo() {
    std::cout << this->ent1.getName() << ": HP: " << this->ent1.getHealth() << ", DMG:" << this->ent1.getAttackDamage() << std::endl;
    std::cout << this->ent2.getName() << ": HP: " << this->ent2.getHealth() << ", DMG:" << this->ent2.getAttackDamage() << std::endl;
}
