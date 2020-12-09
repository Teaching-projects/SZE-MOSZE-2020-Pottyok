#include "HeroTextRenderer.cpp"
#include "ObserverTextRenderer.cpp"
#include "Game.cpp"

#include <gtest/gtest.h>

TEST(RendererTests, ObserverTest)
{
    Game g("map_test.txt");
    std::stringstream output;
    std::string expected("\n╔════════════════════════════╗\n║████████████████████████████║\n║██░░░░░░██░░░░████████░░░░██║\n║██░░████████░░░░████░░░░████║\n║██░░░░░░██░░░░████░░░░██████║\n║██████░░██░░████░░░░████████║\n║██░░░░░░░░░░░░░░░░░░████████║\n║████████████████████████████║\n╚════════════════════════════╝\n");
    g.registerRenderer(new ObserverTextRenderer(output));
    g.render();
    ASSERT_EQ(output.str(), expected);
}

TEST(RendererTests, HeroRenderTest)
{
    Game g("map_test.txt");
    std::stringstream output;
    std::string expected("\n╔══════════╗\n║██████████║\n║██░░┣┫░░██║\n║██░░██████║\n║██░░M░M░██║\n╚══════════╝\n");
    g.registerRenderer(new HeroTextRenderer(output));
    g.render();
    ASSERT_EQ(output.str(), expected);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}