
#include <iostream>
#include <fstream>
#include "CharacterSVGRenderer.h"

void CharacterSVGRenderer::render(const Game &game) const
{
    std::ofstream svgFile;
    svgFile.open(this->filename);
    svgFile << "<svg xmlns=\"http://www.w3.org/2000/svg\" >";

    int playerLightRadius = std::get<Hero>(game.getHeroes()[0].getEntity()).getLightRadius();
    int playerX = game.getHeroes()[0].getX();
    int playerY = game.getHeroes()[0].getY();

    for (unsigned int i = (unsigned int)std::max<int>(playerY - playerLightRadius, 0); i < (unsigned int)std::min<int>(game.getMap().getColumnCount(), playerY + 1 + playerLightRadius); i++)
    {
        std::string row = game.getMap().getRow(i);
        for (unsigned int j = (unsigned int)std::max<int>(playerX - playerLightRadius, 0); j < (unsigned int)std::min<int>(row.size(), playerX + 1 + playerLightRadius); j++)
        {
            if (game.heroIsHere(j, i))
            {
                std::string monsterTextureFileName = std::get<Hero>(game.getHeroes()[0].getEntity()).getTexture();
                std::string svgContent = this->getSVGContent(monsterTextureFileName);
                svgFile << this->replaceSVGCoordinates(svgContent, (j - (unsigned int)std::max<int>(playerX - playerLightRadius, 0)) * 10, (i - (unsigned int)std::max<int>(playerY - playerLightRadius, 0)) * 10);
            }
            else if (game.countMonstersHere(j, i) > 0)
            {
                std::string monsterTextureFileName = game.getMonstersHere(j,i).getTexture();
                
                std::string svgContent = this->getSVGContent(monsterTextureFileName);
                svgFile << this->replaceSVGCoordinates(svgContent, (j - (unsigned int)std::max<int>(playerX - playerLightRadius, 0)) * 10, (i - (unsigned int)std::max<int>(playerY - playerLightRadius, 0)) * 10);
            }
            else
            {
                std::string textureFile = (game.getMap().get(j, i) == Map::Free ? game.getFreeTexture() : game.getWallTexture());

                std::string svgContent = this->getSVGContent(textureFile);
                svgFile << this->replaceSVGCoordinates(svgContent, (j - (unsigned int)std::max<int>(playerX - playerLightRadius, 0)) * 10, (i - (unsigned int)std::max<int>(playerY - playerLightRadius, 0)) * 10);
            }
        }

        for (unsigned int j = (unsigned int)std::min<int>(row.size(), playerX + 1 + playerLightRadius); j < (unsigned int)std::min<int>((playerX + 1 + playerLightRadius), game.getMap().getLongestRowCount()); j++)
        {
            std::string wallTextureFileName = game.getWallTexture();
            std::string svgContent = this->getSVGContent(wallTextureFileName);
            svgFile << this->replaceSVGCoordinates(svgContent, (j - (unsigned int)std::max<int>(playerX - playerLightRadius, 0)) * 10, (i - (unsigned int)std::max<int>(playerY - playerLightRadius, 0)) * 10);
        }
    }

    svgFile << "</svg>";

    svgFile.close();
}