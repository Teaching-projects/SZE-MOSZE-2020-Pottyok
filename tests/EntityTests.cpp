#include "Monster.h"
#include "Hero.h"

#include <gtest/gtest.h>

TEST(EntityTests, ParseMonster)
{
    Monster monster = Monster::parse("../units/TestMonster.json");

    ASSERT_EQ(monster.getHealthPoints(), 450.0);
    ASSERT_EQ(monster.getDamage(), 600.0);
    ASSERT_EQ(monster.getName(), "Test Monster");
    ASSERT_EQ(monster.getAttackCoolDown(), 10.5);
}

TEST(EntityTests, ParseHero)
{
    Hero hero = Hero::parse("../units/TestHero.json");

    ASSERT_EQ(hero.getHealthPoints(), 30);
    ASSERT_EQ(hero.getDamage(), 6);
    ASSERT_EQ(hero.getName(), "Test Hero");
    ASSERT_EQ(hero.getAttackCoolDown(), 1.1f);
}

TEST(EntityTests, Attack)
{
    Monster monster = Monster::parse("../units/TestMonster.json");

    monster.attack(monster);
    ASSERT_EQ(monster.getHealthPoints(), 0);
}

TEST(EntityTests, FightVictory)
{
    Hero hero(30.0, 3.0, 0.0, 0.0, "Prince Aidan of Khanduras", 1.1, 20.0, 5.0, 1.0, 0.0, 0.0, 0.9, 2, 2, "hero.svg");
    Monster monster(10.0, 1.0, 0.0, 0.0, "Zombie", 2.8f, "monster.svg");

    hero.fightTilDeath(monster);

    ASSERT_NEAR(hero.getHealthPoints(), 28.0, 0.005);
}

TEST(EntityTests, FightLose)
{
    Hero hero(30.0, 3.0, 0.0, 0.0, "Prince Aidan of Khanduras", 1.1, 20.0, 5.0, 1.0, 0.0, 0.0, 0.9, 2, 2, "hero.svg");
    Monster monster(113.0, 8.0, 0.0, 0.0, "Blood Raven", 1.2, "monster.svg");

    hero.fightTilDeath(monster);

    ASSERT_EQ(hero.getHealthPoints(), 0);
}

TEST(EntityTests, MaxHealthLevelUp)
{
    Hero hero(30.0, 3.0, 0.0, 0.0, "Prince Aidan of Khanduras", 1.1, 3.0, 5.0, 1.0, 0.0, 0.0, 0.9, 2, 2, "hero.svg");
    Monster monster(113.0, 8.0, 0.0, 0.0, "Blood Raven", 1.2, "monster.svg");
    hero.attack(monster);

    ASSERT_EQ(hero.getLevel(), 1);
    ASSERT_EQ(hero.getMaxHealthPoints(), 35);
    ASSERT_EQ(hero.getDamage(), 4);
    ASSERT_EQ(hero.getHealthPoints(), 35);
    ASSERT_EQ(hero.getAttackCoolDown(), 1.1f * 0.9f);
}

TEST(EntityTests, MaxHealthNoLevelUp)
{
    Hero hero(30.0, 3.0, 0.0, 0.0, "Prince Aidan of Khanduras", 1.1, 20.0, 5.0, 1.0, 0.0, 0.0, 0.9, 2, 2, "hero.svg");
    Monster monster(113.0, 8.0, 0.0, 0.0, "Blood Raven", 1.2, "monster.svg");
    hero.attack(monster);

    ASSERT_EQ(hero.getLevel(), 0);
    ASSERT_EQ(hero.getMaxHealthPoints(), 30);
    ASSERT_EQ(hero.getDamage(), 3);
    ASSERT_EQ(hero.getHealthPoints(), 30);
    ASSERT_EQ(hero.getAttackCoolDown(), 1.1f);
}

TEST(EntityTests, NoMaxHealthLevelUp)
{
    Hero hero(30.0, 3.0, 0.0, 0.0, "Prince Aidan of Khanduras", 1.1, 3.0, 5.0, 1.0, 0.0, 0.0, 0.9, 2, 2, "hero.svg");
    Monster monster(113.0, 8.0, 0.0, 0.0, "Blood Raven", 1.2, "monster.svg");
    monster.attack(hero);
    hero.attack(monster);

    ASSERT_EQ(hero.getLevel(), 1);
    ASSERT_EQ(hero.getMaxHealthPoints(), 35);
    ASSERT_EQ(hero.getDamage(), 4);
    ASSERT_EQ(hero.getHealthPoints(), 35);
    ASSERT_EQ(hero.getAttackCoolDown(), 1.1f * 0.9f);
}

TEST(EntityTests, NoMaxHealthNoLevelUp)
{
    Hero hero(30.0, 3.0, 0.0, 0.0, "Prince Aidan of Khanduras", 1.1, 20.0, 5.0, 1.0, 0.0, 0.0, 0.9, 2, 2, "hero.svg");
    Monster monster(113.0, 8.0, 0.0, 0.0, "Blood Raven", 1.2, "monster.svg");
    monster.attack(hero);
    hero.attack(monster);

    ASSERT_EQ(hero.getLevel(), 0);
    ASSERT_EQ(hero.getMaxHealthPoints(), 30);
    ASSERT_EQ(hero.getDamage(), 3);
    ASSERT_EQ(hero.getHealthPoints(), 22);
    ASSERT_EQ(hero.getAttackCoolDown(), 1.1f);
}

TEST(EntityTests, IncreaseLightRadius)
{
    Hero hero(30.0, 3.0, 0.0, 0.0, "Prince Aidan of Khanduras", 1.1, 3.0, 5.0, 1.0, 0.0, 0.0, 0.9, 2, 2, "hero.svg");
    Monster monster(113.0, 8.0, 0.0, 0.0, "Blood Raven", 1.2, "monster.svg");
    hero.attack(monster);

    ASSERT_EQ(hero.getLightRadius(), 4);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}