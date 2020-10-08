#include "Entity.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex> 

#include "JsonParser.h"

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

int Entity::getHealth() const{
    return this->Health;
}


int Entity::getAttackDamage() const{
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

bool Entity::getIsDead() const{
    return (this->Health <= 0);
}

std::string Entity::getName() const{
    return this->Name;
}


Entity Entity::parseUnit(const std::string& fileName){
    std::map<std::string, std::any> data = JsonParser::ParseFile(fileName);

    return Entity(std::any_cast<int>(data["hp"]), std::any_cast<int>(data["dmg"]), std::any_cast<std::string>(data["name"]));
}