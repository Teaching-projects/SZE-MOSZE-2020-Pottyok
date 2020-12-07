#include "Monster.h"
#include <string>
#include <regex>
#include "JSON.h"
#include "Damage.h"

Monster &Monster::operator=(const Monster &monster)
{
    this->MaxHealth = monster.MaxHealth;
    this->Health = monster.Health;
    this->Defense = monster.Defense;
    this->AttackDamage = monster.AttackDamage;
    this->AttackSpeed = monster.AttackSpeed;
    this->Name = monster.Name;
    this->Texture = monster.Texture;
    return *this;
}

float Monster::getHealthPoints() const
{
    return this->Health;
}

float Monster::getMaxHealthPoints() const
{
    return this->MaxHealth;
}

float Monster::getDamage(float defense) const
{
    return std::max<float>(this->AttackDamage.physical - defense, 0) + this->AttackDamage.magical;
}

float Monster::getDefense() const
{
    return this->Defense;
}

float Monster::getAttackCoolDown() const
{
    return this->AttackSpeed;
}

void Monster::damage(const float dmg)
{
    this->Health -= dmg;
    if (this->Health <= 0)
    {
        this->Health = 0;
    }
}

void Monster::attack(Monster &enemy)
{
    enemy.damage(this->getDamage());
}

bool Monster::getIsDead() const
{
    return (this->Health <= 0);
}

bool Monster::isAlive() const
{
    return (this->Health > 0);
}

std::string Monster::getName() const
{
    return this->Name;
}

Damage Monster::getDamageStruct() const
{
    return this->AttackDamage;
}

void Monster::fightTilDeath(Monster &enemy)
{
    float attackerTimer = 0, enemyTimer = 0;

    do
    {
        if (attackerTimer < enemyTimer)
        {
            enemyTimer -= attackerTimer;
            attackerTimer = this->getAttackCoolDown();
            this->attack(enemy);
        }
        else if (enemyTimer < attackerTimer)
        {
            attackerTimer -= enemyTimer;
            enemyTimer = enemy.getAttackCoolDown();
            enemy.attack(*this);
        }
        else
        {
            enemyTimer = 0;
            attackerTimer = this->getAttackCoolDown();
            this->attack(enemy);
        }

    } while (!this->getIsDead() && !enemy.getIsDead());
}

Monster Monster::parse(const std::string &fileName)
{
    JSON json = JSON::parseFromFile(fileName);

    int physicalDamage = json.count("damage") == 0 ? 0 : json.get<int>("damage");
    int magicalDamage = json.count("magical-damage") == 0 ? 0 : json.get<int>("magical-damage");

    return Monster(
        (float)json.get<int>("health_points"),
        (float)physicalDamage,
        (float)magicalDamage,
        (float)json.get<int>("defense"),
        json.get<std::string>("name"),
        (float)json.get<float>("attack_cooldown"),
        json.get<std::string>("texture"));
}

std::string Monster::getTexture() const
{
    return this->Texture;
}