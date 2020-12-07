#include "Game.h"

#include <gtest/gtest.h>


TEST(GameTests, SetMap) {
    Game game("map_test.txt");
    ASSERT_TRUE(game.isMapSet());
}

TEST(GameTests, IsHeroSetTrue) {
    Game game("map_test.txt");
    Hero hero = Hero::parse("../units/TestHero.json");
    game.putHero(hero, 1, 1);
    ASSERT_TRUE(game.isHeroSet());
}

TEST(GameTests, IsHeroSetFalse) {
    Game game("map_test.txt");
    ASSERT_FALSE(game.isHeroSet());
}

TEST(GameTests, PutHeroOnFree) {
    Game game("map_test.txt");
    Hero hero = Hero::parse("../units/TestHero.json");
    ASSERT_NO_THROW(game.putHero(hero, 1, 1));
}

TEST(GameTests, PutHeroOnWall) {
    Game game("map_test.txt");
    Hero hero = Hero::parse("../units/TestHero.json");
    ASSERT_THROW(game.putHero(hero, 0, 0), std::runtime_error);
}

TEST(GameTests, PutMonsterOnFree) {
    Game game("map_test.txt");
    Monster monster = Monster::parse("../units/TestMonster.json");
    ASSERT_THROW(game.putMonster(monster, 0, 0), std::runtime_error);
}

TEST(GameTests, PutMonsterOnWall) {
    Game game("map_test.txt");
    Monster monster = Monster::parse("../units/TestMonster.json");
    ASSERT_THROW(game.putMonster(monster, 0, 0), std::runtime_error);
}

TEST(GameTests, HeroIsHereTrue) {
    Game game("map_test.txt");
    Hero hero = Hero::parse("../units/TestHero.json");
    game.putHero(hero, 1, 1);
    ASSERT_TRUE(game.heroIsHere(1, 1));
}

TEST(GameTests, HeroIsHereFalse) {
    Game game("map_test.txt");
    Hero hero = Hero::parse("../units/TestHero.json");
    game.putHero(hero, 1, 1);
    ASSERT_FALSE(game.heroIsHere(1, 2));
}

TEST(GameTests, CountMonsterHereNone) {
    Game game("map_test.txt");
    ASSERT_EQ(game.countMonstersHere(1, 1), 0);
}

TEST(GameTests, CountMonsterHereSingle) {
    Game game("map_test.txt");
    Monster monster = Monster::parse("../units/TestMonster.json");
    game.putMonster(monster, 1, 1);
    ASSERT_EQ(game.countMonstersHere(1, 1), 1);
}

TEST(GameTests, CountMonsterHereMultiple) {
    Game game("map_test.txt");
    Monster monster = Monster::parse("../units/TestMonster.json");
    game.putMonster(monster, 1, 1);
    game.putMonster(monster, 1, 1);
    ASSERT_EQ(game.countMonstersHere(1, 1), 2);
}

TEST(GameTests, AreMonstersAliveTrue) {
    Game game("map_test.txt");
    Monster monster = Monster::parse("../units/TestMonster.json");
    game.putMonster(monster, 1, 1);
    ASSERT_TRUE(game.areMonstersAlive());
}

TEST(GameTests, AreMonstersAliveFalse) {
    Game game("map_test.txt");
    ASSERT_FALSE(game.areMonstersAlive());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}