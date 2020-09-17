#include "Entity.h"
#include <string>
#include <iostream>

Entity::Entity(const int health,const int attackDamage,const std::string name){
    this->MaxHealth      =   health;
    this->Health         =   this->MaxHealth;
    this->AttackDamage   =   attackDamage;
    this->isDead         =   false;
    this->Name           =   name;
}


Entity& Entity::operator=(const Entity &entity){
    this->MaxHealth      =   entity.MaxHealth;
    this->Health         =   entity.Health;
    this->AttackDamage   =   entity.AttackDamage;
    this->Name         =   entity.Name;
    this->isDead         =   entity.isDead; 
}

int Entity::getHealth(){
    return this->Health;
}


int Entity::getAttackDamage(){
    return this->AttackDamage;
}

void Entity::die(){
    this->isDead = true;
}

void Entity::damage(const int dmg){
    this->Health -= dmg;
    if(this->Health <= 0){
        this->Health = 0;
        this->die();
    }
}

void Entity::attack(Entity& enemy){
    std::cout << this->getName() << " -> " << enemy.getName() << std::endl;
    enemy.damage(this->getAttackDamage());
}

bool Entity::getIsDead(){
    return this->isDead;
}

std::string Entity::getName(){
    return this->Name;
}
