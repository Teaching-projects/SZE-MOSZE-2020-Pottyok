#include "Entity.h"
#include "Player.h"

#include <gtest/gtest.h>


TEST(EntityTests, ParseUnit) {
    Entity entity = Entity::parseUnit("../units/TestUnit.json");

    ASSERT_EQ(entity.getHealth(), 450.0);
    ASSERT_EQ(entity.getAttackDamage(), 300.0);
    ASSERT_EQ(entity.getName(), "TestUnit");
    ASSERT_EQ(entity.getAttackSpeed(), 10.5);
}

TEST(EntityTests, Attack) {
    Entity entity = Entity::parseUnit("../units/TestUnit.json");

    entity.attack(entity);
    ASSERT_EQ(entity.getHealth(), 150.0);
}

TEST(EntityTests, fightVictory) {
    Player ent1(450.0, 300.0, "Sally", 10.5f);
    Player ent2(1500.0, 100.0, "Maple", 15.2f);
    
    ent1.fightLoop(ent2);

    ASSERT_NEAR(ent1.getHealth(), 4029.44, 0.005);
}

TEST(EntityTests, fightLose) {
    Player ent1(1500.0, 100.0, "Maple", 15.2f);
    Player ent2(450.0, 300.0, "Sally", 10.5f);
    
    ent1.fightLoop(ent2);

    ASSERT_EQ(ent1.getHealth(), 0);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}