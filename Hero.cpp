#include "Hero.h"
#include "JSON.h"
#include "Monster.h"
#include <string>
#include <iostream>
#include <cmath>

Hero& Hero::operator=(const Monster &monster){
    this->MaxHealth                     =   monster.getMaxHealthPoints();
    this->Health                        =   monster.getHealthPoints();
    this->Defense                       =   monster.getDefense();
    this->AttackDamage                  =   monster.getDamageStruct();
    this->Name                          =   monster.getName();
	this->AttackSpeed					=	monster.getAttackCoolDown();
    this->ExperienceCurrent             =   0;
    
    return *this;
}

void Hero::addExperience(float experience){
    int levelsToAdd =  ((this->ExperienceCurrent + experience) - this->getLevel() * this->ExperiencePerLevel) / this->ExperiencePerLevel;
    this->ExperienceCurrent = this->ExperienceCurrent + experience;

    this->MaxHealth += levelsToAdd * this->HealthPointBonusPerLevel;
    this->AttackDamage.progress(levelsToAdd * this->PhysicalDamageBonusPerLevel,levelsToAdd * this->MagicDamageBonusPerLevel);
    this->Defense += levelsToAdd * this->DefenseBonusPerLevel;
    this->Health = levelsToAdd > 0 ? this->MaxHealth : this->Health;
	this->AttackSpeed *= powf(this->ColdownMultiplierPerLevel ,levelsToAdd);
}

int Hero::getLevel() const{
    return this->ExperienceCurrent / this->ExperiencePerLevel;
}

void Hero::attack(Monster& monster){
	float enemyHealthBeforeAttack = monster.getHealthPoints();

	Monster::attack(monster);
    this->addExperience(std::min(std::max(this->getDamage() - monster.getDefense(), (float)0), enemyHealthBeforeAttack));

}

Hero Hero::parse(const std::string& fileName){
    JSON json = JSON::parseFromFile(fileName);
    
    return Hero(
        json.get<int>("base_health_points"),
        json.get<int>("daamge"),
        json.get<int>("magical-damage"),
        json.get<int>("base_defense"),
        json.get<std::string>("name"),
        json.get<float>("base_attack_cooldown"),
        json.get<int>("experience_per_level"),
        json.get<int>("health_point_bonus_per_level"),
        json.get<int>("physical_damage_bonus_per_level"),
        json.get<int>("magic_damage_bonus_per_level"),
        json.get<int>("defense_bonus_per_level"),
        json.get<float>("cooldown_multiplier_per_level")
    );
}