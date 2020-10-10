#include "Player.h"
#include "Entity.h"
#include <string>
#include <iostream>
#include <cmath>

Player::Player(const int health,const int attackDamage,const std::string name) : Entity(health, attackDamage, name) {
    this->ExperienceAtLastRound         = 0;
    this->ExperienceCurrent             = 0;
    this->ExperienceStartOfFight        = 0;
}

Player& Player::operator=(const Player &player){
    this->MaxHealth                     =   player.MaxHealth;
    this->Health                        =   player.Health;
    this->AttackDamage                  =   player.AttackDamage;
    this->Name                          =   player.Name;
    this->ExperienceAtLastRound         =   player.ExperienceAtLastRound;
    this->ExperienceCurrent             =   player.ExperienceCurrent;
    this->ExperienceStartOfFight        =   player.ExperienceStartOfFight;
    
    return *this;
}

Player& Player::operator=(const Entity &entity){
    this->MaxHealth                     =   entity.getMaxHealth();
    this->Health                        =   entity.getHealth();
    this->AttackDamage                  =   entity.getAttackDamage();
    this->Name                          =   entity.getName();
    this->ExperienceAtLastRound         =   0;
    this->ExperienceCurrent             =   0;
    this->ExperienceStartOfFight        =   0;
    
    return *this;
}

void Player::addExperience(float experience){
    this->ExperienceCurrent += experience;
    int levelsToAdd = (this->ExperienceCurrent - this->ExperienceAtLastRound) / 100;
    this->MaxHealth *= powf(1.1f,levelsToAdd);
    this->AttackDamage *= powf(1.1f,levelsToAdd);
    this->Health = levelsToAdd > 0 ? this->MaxHealth : this->Health;
    this->ExperienceAtLastRound = this->ExperienceCurrent;
}

void Player::looseGainedLevels(){
    int levelsToLoose = (this->ExperienceCurrent - this->ExperienceStartOfFight) / 100;
    this->MaxHealth /= powf(1.1f,levelsToLoose);
    this->AttackDamage /= powf(1.1f,levelsToLoose);
    this->ExperienceAtLastRound = this->ExperienceStartOfFight;
    this->ExperienceCurrent = this->ExperienceStartOfFight;
}

int Player::getLevel() const{
    return this->ExperienceCurrent / 100;
}

void Player::attack(Entity& entity){
    this->addExperience(std::min(this->getAttackDamage(),entity.getHealth()));
    Entity::attack(entity);
    if(entity.getIsDead()) {
        this->ExperienceStartOfFight = this->ExperienceCurrent; 
    }
    if(this->getIsDead()){
        this->looseGainedLevels();
    }
}