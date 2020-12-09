#include "Game.h"
#include <gtest/gtest.h>

TEST(Maptest, CreateMapEntity)
{
    Monster monster = Monster::parse("../units/TestMonster.json");
    ASSERT_NO_THROW(MapEntity entity(1,1,monster));
}

TEST(Maptest, SetAndGetEntity)
{
    Monster monster1 = Monster::parse("../units/TestMonster.json");
    Monster monster2 = Monster::parse("../units/Zombie.json");
    MapEntity entity(1,1,monster1);

    entity.setEntity(monster2);

    Monster retunrMonster = std::get<Monster>(entity.getEntity());

    ASSERT_EQ(retunrMonster.getAttackCoolDown(), monster2.getAttackCoolDown());
    ASSERT_EQ(retunrMonster.getDamage(), monster2.getDamage());
    ASSERT_EQ(retunrMonster.getDefense(), monster2.getDefense());
    ASSERT_EQ(retunrMonster.getHealthPoints(), monster2.getHealthPoints());
    ASSERT_EQ(retunrMonster.getIsDead(), monster2.getIsDead());
    ASSERT_EQ(retunrMonster.getMaxHealthPoints(), monster2.getMaxHealthPoints());
    ASSERT_EQ(retunrMonster.getName(), monster2.getName());
    ASSERT_EQ(retunrMonster.getTexture(), monster2.getTexture());
    ASSERT_EQ(retunrMonster.isAlive(), monster2.isAlive());
}

TEST(Maptest, SetAndGetPosition)
{
    Monster monster = Monster::parse("../units/TestMonster.json");
    MapEntity entity(1,1,monster);

    int newX = 2, newY = 2;

    entity.setX(newX);
    entity.setY(newY);

    ASSERT_EQ(entity.getX(), newX);
    ASSERT_EQ(entity.getY(), newY);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}