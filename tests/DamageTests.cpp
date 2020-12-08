#include "Damage.h"

#include <gtest/gtest.h>

TEST(DamageTests, SumDamageWithoutDefense)
{
    Damage damage = Damage();
    damage->physical = 4;
    damage->magical = 4;

    ASSERT_EQ(damage->sum(), 8);
}

TEST(DamageTests, SumDamageWithDefense)
{
    Damage damage = Damage();
    damage->physical = 4;
    damage->magical = 4;

    ASSERT_EQ(damage->sum(4), 4);
}

TEST(DamageTests, SumDamageWithProgress)
{
    Damage damage = Damage();
    damage->physical = 4;
    damage->magical = 4;
    damage->progress(5,5);

    ASSERT_EQ(damage->sum(0), 18);
}

TEST(DamageTests, AddDamages)
{
    Damage damage1 = Damage();
    damage->physical = 4;
    damage->magical = 4;
    Damage damage2 = Damage();
    damage->physical = 4;
    damage->magical = 4;
    damage1 += damage2;

    ASSERT_EQ(damage->sum(0), 16);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}