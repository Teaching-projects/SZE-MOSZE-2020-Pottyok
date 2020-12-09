#include "Map.h"
#include <gtest/gtest.h>

TEST(Maptest, FileReadTest)
{
    ASSERT_THROW(Map map("./none.txt"), std::runtime_error);
    ASSERT_NO_THROW(Map map("map_test.txt"));
}

TEST(Maptest, MapHeight)
{
    Map map("map_test.txt");
    ASSERT_EQ(map.getColumnCount(), 7);
}

TEST(Maptest, MapWidth)
{
    Map map("map_test.txt");
    ASSERT_EQ(map.getLongestRowCount(), 14);
}

TEST(Maptest, GetCoordinate)
{
    Map map("map_test.txt");
    ASSERT_EQ(map.get(0,0), Map::Wall);
    ASSERT_EQ(map.get(1,1), Map::Free);
}

TEST(Maptest, GetAndSetRow)
{
    Map map("map_test.txt");
    std::string newRow = "####";
    map.setRow(0, newRow);
    ASSERT_EQ(map.getRow(0), newRow);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}