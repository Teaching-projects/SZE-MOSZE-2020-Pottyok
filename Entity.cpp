#include "Entity.h"
#include <string>
#include <iostream>

Entity::Entity(const float h,const float ad,const std::string n) : Name(n){
    this->MaxHealth      =   h;
    this->Health         =   this->MaxHealth;
    this->AttackDamage   =   ad;
    this->isDead         =   false;
}

float Entity::getHealth(){
    return this->Health;
}

float Entity::getAttackDamage(){
    return this->AttackDamage;
}

void Entity::die(){
    this->isDead = true;
    std::cout << "I am dead: " << this->Name << std::endl;
}

void Entity::damage(const float dmg){
    this->Health -= dmg;
    if(this->Health <= 0){
        this->Health = 0;
        this->die();
    }
}

void Entity::attack(Entity& enemy){
    enemy.damage(this->getAttackDamage());
}

bool Entity::getIsDead(){
    return this->isDead;
}

std::string Entity::getName(){
    return this->Name;
}
