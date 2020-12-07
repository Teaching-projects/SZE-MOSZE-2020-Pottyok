#include "HeroTextRenderer.h"

void HeroTextRenderer::render(const Game &game) const
{
    int playerLightRadius = std::get<Hero>(game.getHeroes()[0].getEntity()).getLightRadius();
    int playerX = game.getHeroes()[0].getX();
    int playerY = game.getHeroes()[0].getY();
    unsigned int border_width = (std::min<int>(playerLightRadius, playerX) + 1 + std::min<int>(playerLightRadius, game.getMap().getLongestRowCount() - 1 - playerX)) * 2;

    this->stream << "\n╔";
    for (unsigned int i = 0; i < border_width; i++)
    {
        this->stream << "═";
    }
    this->stream << "╗" << std::endl;

    for (unsigned int i = (unsigned int)std::max<int>(playerY - playerLightRadius, 0); i < (unsigned int)std::min<int>(game.getMap().getColumnCount(), playerY + 1 + playerLightRadius); i++)
    {
        this->stream << "║";
        std::string row = game.getMap().getRow(i);
        for (unsigned int j = (unsigned int)std::max<int>(playerX - playerLightRadius, 0); j < (unsigned int)std::min<int>(row.size(), playerX + 1 + playerLightRadius); j++)
        {
            if (game.heroIsHere(j, i))
            {
                this->stream << "┣┫";
            }
            else if (game.countMonstersHere(j, i) > 0)
            {
                this->stream << (game.countMonstersHere(j, i) > 1 ? "MM" : "M░");
            }
            else
            {
                this->stream << (game.getMap().get(j, i) == Map::Free ? "░░" : "██");
            }
        }

        for (unsigned int j = (unsigned int)std::min<int>(row.size(), playerX + 1 + playerLightRadius); j < (unsigned int)std::min<int>((playerX + 1 + playerLightRadius), game.getMap().getLongestRowCount()); j++)
        {
            this->stream << "██";
        }
        this->stream << "║" << std::endl;
    }

    this->stream << "╚";
    for (unsigned int i = 0; i < border_width; i++)
    {
        this->stream << "═";
    }
    this->stream << "╝" << std::endl;
}