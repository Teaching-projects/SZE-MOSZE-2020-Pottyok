#include "Game.h"
#include "Entity.h"
#include <iostream>

Game::Game (const Entity& ent1,const Entity& ent2):ent1(ent1), ent2(ent2){
    this->turn  = 0;
}

void Game::Start(){
    this->Loop();
}

void Game::Loop(){
    do {
        this->attackPhase();
        this->turn++;
    }
    while(!this->isAnyoneDead());
    this->End();
}

void Game::End(){
    std::cout << "The game has ended! The winner is: " << this->getWinner().getName() << " after " << this->turn << " turn(s)!" << std::endl;
}

bool Game::isAnyoneDead(){
    return (this->ent1.getIsDead() || this->ent2.getIsDead());
}

void Game::attackPhase(){
    this->turn % 2 == 0 ? this->ent1.attack(this->ent2) : this->ent2.attack(this->ent1);
    std::cout << this->ent1.getName() << " HP: " << this->ent1.getHealth() << " | " << this->ent2.getName() <<" HP: " << this->ent2.getHealth() << std::endl;
}

Entity Game::getWinner(){
    return this->ent1.getIsDead() ? this->ent2 : this->ent1;
}
