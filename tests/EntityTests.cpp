#include "Monster.h"
#include "Hero.h"

#include <gtest/gtest.h>


TEST(EntityTests, ParseUnit) {
    Monster entity = Monster::parse("../units/TestUnit.json");

    ASSERT_EQ(entity.getHealthPoints(), 450.0);
    ASSERT_EQ(entity.getDamage(), 300.0);
    ASSERT_EQ(entity.getName(), "TestUnit");
    ASSERT_EQ(entity.getAttackCoolDown(), 10.5);
}

TEST(EntityTests, Attack) {
    Monster entity = Monster::parse("../units/TestUnit.json");

    entity.attack(entity);
    ASSERT_EQ(entity.getHealthPoints(), 150.0);
}

TEST(EntityTests, fightVictory) {
    Hero ent1(30.0, 3.0, "Prince Aidan of Khanduras", 1.1, 20.0, 5.0, 1.0, 0.9);
    Monster ent2(10.0, 1.0, "Zombie", 2.8f);
    
    ent1.fightTilDeath(ent2);

    ASSERT_NEAR(ent1.getHealthPoints(), 28.0, 0.005);
}

TEST(EntityTests, fightLose) {
    Hero ent1(30.0, 3.0, "Prince Aidan of Khanduras", 1.1, 20.0, 5.0, 1.0, 0.9);
    Monster ent2(113.0, 8.0, "Blood Draven", 1.2);
    
    ent1.fightTilDeath(ent2);

    ASSERT_EQ(ent1.getHealthPoints(), 0);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}