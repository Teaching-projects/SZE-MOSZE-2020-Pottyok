#include "Monster.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex> 
#include "JSON.h"

Monster& Monster::operator=(const Monster &monster) {
    this->MaxHealth      =   monster.MaxHealth;
    this->Health         =   monster.Health;
    this->AttackDamage   =   monster.AttackDamage;
    this->AttackSpeed    =   monster.AttackSpeed;
    this->Name           =   monster.Name;
    return *this;
}

float Monster::getHealthPoints() const{
    return this->Health;
}

float Monster::getMaxHealth() const{
    return this->MaxHealth;
}

float Monster::getAttackDamage() const{
    return this->AttackDamage;
}


float Monster::getAttackSpeed() const {
    return this->AttackSpeed;
}


void Monster::damage(const float dmg){
    this->Health -= dmg;
    if(this->Health <= 0){
        this->Health = 0;
    }
}

void Monster::attack(Monster& enemy){
    enemy.damage(this->getAttackDamage());
}

bool Monster::getIsDead() const{
    return (this->Health <= 0);
}

bool Monster::isAlive() const{
    return (this->Health > 0);
}

std::string Monster::getName() const{
    return this->Name;
}



void Monster::fightTilDeath(Monster& enemy) {
    float attackerTimer = 0, enemyTimer = 0;

    do
    {
        if (attackerTimer < enemyTimer) {
            enemyTimer -= attackerTimer;
            attackerTimer = this->getAttackSpeed();
            this->attack(enemy);
        }
        else if (enemyTimer < attackerTimer) {
            attackerTimer -= enemyTimer;
            enemyTimer = enemy.getAttackSpeed();
            enemy.attack(*this);
        }
        else {
            enemyTimer = 0;
            attackerTimer = this->getAttackSpeed();
            this->attack(enemy);
        }

    } while (!this->getIsDead() && !enemy.getIsDead());

}


Monster Monster::parse(const std::string& fileName){
    std::map<std::string, std::any> data = JSON::parseFromFile(fileName);

    JSON::CheckValues<float>(data, "hp");
    JSON::CheckValues<float>(data, "dmg");
    JSON::CheckValues<std::string>(data, "name");
    JSON::CheckValues<float>(data, "spd");

    return Monster(
        std::any_cast<float>(data["hp"]),
        std::any_cast<float>(data["dmg"]),
        std::any_cast<std::string>(data["name"]),
        std::any_cast<float>(data["spd"])
    );
}