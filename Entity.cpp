#include "Entity.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex> 
#include "JSON.h"

Entity& Entity::operator=(const Entity &entity) {
    this->MaxHealth      =   entity.MaxHealth;
    this->Health         =   entity.Health;
    this->AttackDamage   =   entity.AttackDamage;
    this->AttackSpeed    =   entity.AttackSpeed;
    this->Name           =   entity.Name;
    return *this;
}

float Entity::getHealth() const{
    return this->Health;
}

float Entity::getMaxHealth() const{
    return this->MaxHealth;
}

float Entity::getAttackDamage() const{
    return this->AttackDamage;
}


float Entity::getAttackSpeed() const {
    return this->AttackSpeed;
}


void Entity::damage(const float dmg){
    this->Health -= dmg;
    if(this->Health <= 0){
        this->Health = 0;
    }
}

void Entity::attack(Entity& enemy){
    enemy.damage(this->getAttackDamage());
}

bool Entity::getIsDead() const{
    return (this->Health <= 0);
}

std::string Entity::getName() const{
    return this->Name;
}



void Entity::fightLoop(Entity& enemy) {
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


Entity Entity::parseUnit(const std::string& fileName){
    std::map<std::string, std::any> data = JSON::ParseFile(fileName);

    JSON::CheckValues<float>(data, "hp");
    JSON::CheckValues<float>(data, "dmg");
    JSON::CheckValues<std::string>(data, "name");
    JSON::CheckValues<float>(data, "spd");

    return Entity(
        std::any_cast<float>(data["hp"]),
        std::any_cast<float>(data["dmg"]),
        std::any_cast<std::string>(data["name"]),
        std::any_cast<float>(data["spd"])
    );
}