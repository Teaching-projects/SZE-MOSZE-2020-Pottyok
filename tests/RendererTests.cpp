#include "HeroTextRenderer.h"
#include "ObserverTextRenderer.h"

#include <gtest/gtest.h>

TEST(RendererTests, ObserverTest)
{
    Game g("map_test.txt");
    Hero hero = Hero::parse("../units/TestHero.json");
    g.putHero(hero,1,1);
    std::stringstream output;
    std::string expected("\n╔════════════════════════════╗\n║┣┫██████████████████████████║\n║██░░░░░░██░░░░████████░░░░██║\n║██░░████████░░░░████░░░░████║\n║██░░░░░░██░░░░████░░░░██████║\n║██████░░██░░████░░░░████████║\n║██░░░░░░░░░░░░░░░░░░████████║\n║████████████████████████████║\n╚════════════════════════════╝\n");
    g.registerRenderer(new ObserverTextRenderer(output));
    g.render();
    ASSERT_EQ(output.str(), expected);
}

TEST(RendererTests, HeroRenderTest)
{
    Game g("map_test.txt");
    Hero hero = Hero::parse("../units/TestHero.json");
    g.putHero(hero,1,1);
    std::stringstream output;
    std::string expected("\n╔══════════╗\n║┣┫████████║\n║██░░░░░░██║\n║██░░██████║\n║██░░░░░░██║\n╚══════════╝\n");
    g.registerRenderer(new HeroTextRenderer(output));
    g.render();
    ASSERT_EQ(output.str(), expected);
}

TEST(RendererTests, ObserverTestPreparedGame)
{
    PreparedGame g("preparedgame_test");
    std::stringstream output;
    std::string expected("\n╔════════════════════════════╗\n║████████████████████████████║\n║██░░░░░░██░░░░████████░░░░██║\n║██░░████████░░░░████░░░░████║\n║██┣┫M░░░██░░░░████░░░░██████║\n║██████░░██░░████░░░░████████║\n║██░░░░░░░░░░░░░░░░░░████████║\n║████████████████████████████║\n╚════════════════════════════╝\n");
    g.registerRenderer(new ObserverTextRenderer(output));
    g.render();
    ASSERT_EQ(output.str(), expected);
}


TEST(RendererTests, HeroRenderTestPreparedGame)
{
    PreparedGame g("preparedgame_test");
    std::stringstream output;
    std::string expected("\n╔════════╗\n║██░░░░░░║\n║██░░████║\n║██┣┫M░░░║\n║██████░░║\n║██░░░░░░║\n╚════════╝\n");
    g.registerRenderer(new HeroTextRenderer(output));
    g.render();
    ASSERT_EQ(output.str(), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}