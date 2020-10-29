#include "Hero.h"
#include "JSON.h"
#include "Monster.h"
#include <string>
#include <iostream>
#include <cmath>

Hero& Hero::operator=(const Monster &monster){
    this->MaxHealth                     =   monster.getMaxHealthPoints();
    this->Health                        =   monster.getHealthPoints();
    this->AttackDamage                  =   monster.getDamage();
    this->Name                          =   monster.getName();
	this->AttackSpeed					=	monster.getAttackCoolDown();
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
	float enemyHealthBeforeAttack = monster.getHealthPoints();
	
	Monster::attack(monster);
    this->addExperience(std::min(this->getDamage(), enemyHealthBeforeAttack));

}

Hero Hero::parse(const std::string& fileName){
    JSON json = JSON::parseFromFile(fileName);
    
    return Hero(
        json.get<float>("base_health_points"),
        json.get<float>("base_damage"),
        json.get<std::string>("name"),
        json.get<float>("base_attack_cooldown")
    );
}