#include "MarkedMap.h"
#include <gtest/gtest.h>

TEST(Maptest, FileReadTest)
{
    std::string fileName = "none.txt";
    ASSERT_THROW(MarkedMap map(fileName), std::runtime_error);
    fileName = "markedmap_test.txt";
    ASSERT_NO_THROW(MarkedMap map(fileName));
}

TEST(Maptest, GetHeroPosition)
{
    std::string fileName = "markedmap_test.txt";
    MarkedMap map(fileName);
    Position heroPosition =  map.getHeroPosition();
    ASSERT_EQ(heroPosition.x, 1);
    ASSERT_EQ(heroPosition.y, 3);
}

TEST(Maptest, GetMonstersPosition)
{
    std::string fileName = "markedmap_test.txt";
    MarkedMap map(fileName);
    std::list<Position> monsterPositions =  map.getMonsterPositions('1');
    ASSERT_EQ(monsterPositions.front().x, 2);
    ASSERT_EQ(monsterPositions.front().y, 3);
}

TEST(Maptest, GetMaxMonsterNumber)
{
    std::string fileName = "markedmap_test.txt";
    MarkedMap map(fileName);
    ASSERT_EQ( map.getMaxMonsterNumber(), 1);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}