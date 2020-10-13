#include "Entity.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex> 

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
    std::ifstream f(fileName);
    if(!f.good()) throw std::runtime_error("The given file was not found: " + fileName);
    std::string fileInOneLine, line;
    while (std::getline(f, line)){ fileInOneLine += line; }
    f.close();

    const std::regex searchRegex("\"([a-zA-Z0-9]+)\"\\s:\\s(\"[a-zA-Z0-9.]+\"|[a-zA-Z0-9.]+)[,\r\n}]{1}");
    std::smatch searchMatches;
    std::string name, matchValue;
    int health, attackDamage;
    float attackSpeed;
    std::regex_match(fileInOneLine, searchMatches, searchRegex);
    while (std::regex_search(fileInOneLine, searchMatches, searchRegex))
    {
        matchValue = searchMatches[2].str();
        std::replace(matchValue.begin(), matchValue.end(), '\"', '\0');
        if (searchMatches[1] == "name")
            name = matchValue;
        else if (searchMatches[1] == "hp")
            health = stoi(matchValue);
        else if (searchMatches[1] == "dmg")
            attackDamage = stoi(matchValue);
        else if (searchMatches[1] == "spd")
            attackSpeed = stof(matchValue);

        fileInOneLine = searchMatches.suffix();
    }

    return Entity(health, attackDamage, name, attackSpeed);
}