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
    std::cout << this->getName() << " -> " << enemy.getName() << std::endl;
    enemy.damage(this->getAttackDamage());
}

bool Entity::getIsDead(){
    return (this->Health <= 0);
}

Entity Entity::parseUnit(const std::string fileName){
    std::ifstream f("units/"+fileName);
    if(!f.good()) throw std::runtime_error("The given file was not found: " + fileName);
    std::string fileInOneLine, line;
    while (std::getline(f, line)){ fileInOneLine += line; }
    f.close();
    const std::regex searchRegex("\"([a-zA-Z0-9]*)\"[\\s:]*\"?([a-zA-Z0-9]*)\"?,?");
    std::smatch searchMatches;
    std::string name;
    int health, attackDamage;
    while (std::regex_search(fileInOneLine, searchMatches, searchRegex))
    {
        if(searchMatches[1] == "name")
            name = searchMatches[2];
        else if(searchMatches[1] == "hp")
            health = stoi(searchMatches[2]);
        else
            attackDamage = stoi(searchMatches[2]);

        fileInOneLine = searchMatches.suffix();
    }
    Entity toCreate(health, attackDamage, name);
    return toCreate;
}

std::string Entity::getName(){
    return this->Name;
}
