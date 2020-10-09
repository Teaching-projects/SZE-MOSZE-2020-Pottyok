#include "Player.h"
#include "Entity.h"
#include <string>
#include <iostream>

Player::Player(const int health,const int attackDamage,const std::string name) : Entity(health, attackDamage, name) {
    this->Experience    = 0;
    this->Level         = 1;
}

Player& Player::operator=(const Player &player){
    this->MaxHealth      =   player.MaxHealth;
    this->Health         =   player.Health;
    this->AttackDamage   =   player.AttackDamage;
    this->Name           =   player.Name;
    this->Experience     =   player.Experience;
    this->Level          =   player.Level;
    
    return *this;
}
