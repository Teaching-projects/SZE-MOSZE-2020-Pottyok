#include "Entity.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex> 

Entity::Entity(const int health,const int attackDamage,const std::string name){
    this->MaxHealth      =   health;
    this->Health         =   this->MaxHealth;
    this->AttackDamage   =   attackDamage;
    this->Name           =   name;
}


Entity& Entity::operator=(const Entity &entity){
    this->MaxHealth      =   entity.MaxHealth;
    this->Health         =   entity.Health;
    this->AttackDamage   =   entity.AttackDamage;
    this->Name           =   entity.Name;
    return *this;
}

int Entity::getHealth(){
    return this->Health;
}


int Entity::getAttackDamage(){
    return this->AttackDamage;
}


void Entity::damage(const int dmg){
    this->Health -= dmg;
    if(this->Health <= 0){
        this->Health = 0;
    }
}

void Entity::attack(Entity& enemy){
    enemy.damage(this->getAttackDamage());
}

bool Entity::getIsDead(){
    return (this->Health <= 0);
}

Entity Entity::parseUnit(const std::string fileName){
    std::ifstream f(fileName);
    if(!f.good()) throw std::runtime_error("The given file was not found: " + fileName);
    std::string fileInOneLine, line;
    while (std::getline(f, line)){ fileInOneLine += line; }
    f.close();

    const std::regex searchRegex("\"([a-zA-Z0-9]+)\"\\s:\\s(\"[a-zA-Z0-9]+\"|[a-zA-Z0-9]+)[,\n}]{1}");
    const std::regex replaceRegex("\"");
    std::smatch searchMatches;
    std::string name;
    std::string matchValue;
    int health, attackDamage;
    std::regex_match(fileInOneLine, searchMatches, searchRegex);
    while (std::regex_search(fileInOneLine, searchMatches, searchRegex))
    {
        matchValue = searchMatches[2].str();
        std::replace(matchValue.begin(), matchValue.end(), '\"', '\0');
        if(searchMatches[1] == "name")
            name = matchValue;
        else if(searchMatches[1] == "hp")
            health = stoi(matchValue);
        else if(searchMatches[1] == "dmg")
            attackDamage = stoi(matchValue);

        fileInOneLine = searchMatches.suffix();
    }
    
    return Entity(health, attackDamage, name);
}

const std::string Entity::getName(){
    return this->Name;
}
