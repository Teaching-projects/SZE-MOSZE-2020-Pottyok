#include "Player.h"
#include "Entity.h"
#include <string>
#include <iostream>
#include <cmath>

Player& Player::operator=(const Entity &entity){
    this->MaxHealth                     =   entity.getMaxHealth();
    this->Health                        =   entity.getHealth();
    this->AttackDamage                  =   entity.getAttackDamage();
    this->Name                          =   entity.getName();
	this->AttackSpeed					=	entity.getAttackSpeed();
    this->ExperienceCurrent             =   0;
    
    return *this;
}

void Player::addExperience(float experience){
    float experienceAfterRound = this->ExperienceCurrent + experience;
    int levelsToAdd = (experienceAfterRound - this->ExperienceCurrent) / 100;
    this->MaxHealth *= powf(1.1f,levelsToAdd);
    this->AttackDamage *= powf(1.1f,levelsToAdd);
    this->Health = levelsToAdd > 0 ? this->MaxHealth : this->Health;
	this->AttackSpeed *= powf(0.9f,levelsToAdd);
    this->ExperienceCurrent = experienceAfterRound;
}

int Player::getLevel() const{
    return this->ExperienceCurrent / 100;
}

void Player::attack(Entity& entity){
	float enemyHealthBeforeAttack = entity.getHealth();
	
	Entity::attack(entity);
    this->addExperience(std::min(this->getAttackDamage(), enemyHealthBeforeAttack));

}