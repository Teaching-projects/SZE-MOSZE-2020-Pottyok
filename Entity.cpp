#include "Entity.h"
#include <string>
#include <iostream>

Entity::Entity(const int h,const int ad,const std::string n) : Name(n){
    this->MaxHealth      =   h;
    this->Health         =   this->MaxHealth;
    this->AttackDamage   =   ad;
    this->isDead         =   false;
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
