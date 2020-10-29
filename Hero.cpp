#include "Hero.h"
#include "Monster.h"
#include <string>
#include <iostream>
#include <cmath>

Hero& Hero::operator=(const Monster &monster){
    this->MaxHealth                     =   monster.getMaxHealth();
    this->Health                        =   monster.getHealth();
    this->AttackDamage                  =   monster.getAttackDamage();
    this->Name                          =   monster.getName();
	this->AttackSpeed					=	monster.getAttackSpeed();
    this->ExperienceCurrent             =   0;
    
    return *this;
}

void Hero::addExperience(float experience){
    float experienceAfterRound = this->ExperienceCurrent + experience;
    int levelsToAdd = (experienceAfterRound - this->ExperienceCurrent) / 100;
    this->MaxHealth *= powf(1.1f,levelsToAdd);
    this->AttackDamage *= powf(1.1f,levelsToAdd);
    this->Health = levelsToAdd > 0 ? this->MaxHealth : this->Health;
	this->AttackSpeed *= powf(0.9f,levelsToAdd);
    this->ExperienceCurrent = experienceAfterRound;
}

int Hero::getLevel() const{
    return this->ExperienceCurrent / 100;
}

void Hero::attack(Monster& monster){
	float enemyHealthBeforeAttack = monster.getHealth();
	
	Monster::attack(monster);
    this->addExperience(std::min(this->getAttackDamage(), enemyHealthBeforeAttack));

}