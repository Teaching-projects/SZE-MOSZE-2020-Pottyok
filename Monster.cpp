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

int Monster::getHealthPoints() const{
    return this->Health;
}

int Monster::getMaxHealthPoints() const{
    return this->MaxHealth;
}

int Monster::getDamage() const{
    return this->AttackDamage;
}


float Monster::getAttackCoolDown() const {
    return this->AttackSpeed;
}


void Monster::damage(const int dmg){
    this->Health -= dmg;
    if(this->Health <= 0){
        this->Health = 0;
    }
}

void Monster::attack(Monster& enemy){
    enemy.damage(this->getDamage());
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
            attackerTimer = this->getAttackCoolDown();
            this->attack(enemy);
        }
        else if (enemyTimer < attackerTimer) {
            attackerTimer -= enemyTimer;
            enemyTimer = enemy.getAttackCoolDown();
            enemy.attack(*this);
        }
        else {
            enemyTimer = 0;
            attackerTimer = this->getAttackCoolDown();
            this->attack(enemy);
        }

    } while (!this->getIsDead() && !enemy.getIsDead());

}


Monster Monster::parse(const std::string& fileName){
    JSON json = JSON::parseFromFile(fileName);
    
    return Monster(
        json.get<int>("health_points"),
        json.get<int>("damage"),
        json.get<std::string>("name"),
        json.get<float>("attack_cooldown")
    );
}