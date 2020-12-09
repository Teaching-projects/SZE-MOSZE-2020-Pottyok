#include "HeroTextRenderer.h"
#include "ObserverTextRenderer.h"
#include "Game.h"

#include <gtest/gtest.h>

TEST(RendererTests, TextRendererTest)
{
    Game g("map_test.txt");
    std::stringstream output;
    std::stringstream expected("\n╔════════════════════════════╗\n║████████████████████████████║\n║██░░░░░░██░░░░████████░░░░██║\n║██░░████████░░░░████░░░░████║\n║██░░░░░░██░░░░████░░░░██████║\n║██████░░██░░████░░░░████████║\n║██░░░░░░░░░░░░░░░░░░████████║\n║████████████████████████████║\n╚════════════════════════════╝\n");
    g.registerRenderer(new ObserverTextRenderer(output));
    g.render();
    ASSERT_EQ(output, expected);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}