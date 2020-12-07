#include "ObserverSVGRenderer.h"

void ObserverSVGRenderer::render(const Game &game) const
{
    std::ofstream svgFile;
    svgFile.open(this->filename);
    svgFile << "<svg xmlns=\"http://www.w3.org/2000/svg\" >";

    for (unsigned int i = 0; i < game.getMap().getColumnCount(); i++)
    {
        std::string row = game.getMap().getRow(i);
        for (unsigned int j = 0; j < row.size(); j++)
        {
            if (game.heroIsHere(j, i))
            {
                std::string heroTextureFileName = std::get<Hero>(game.getHeroes()[0].getEntity()).getTexture();
                std::string svgContent = this->getSVGContent(heroTextureFileName);
                svgFile << this->replaceSVGCoordinates(svgContent, j * 10, i * 10);
            }
            else if (game.countMonstersHere(j, i) > 0)
            {
                std::string monsterTextureFileName = game.getMonsterHere(j, i).getTexture();

                std::string svgContent = this->getSVGContent(monsterTextureFileName);
                svgFile << this->replaceSVGCoordinates(svgContent, j * 10, i * 10);
            }
            else
            {
                std::string textureFile = (game.getMap().get(j, i) == Map::Free ? game.getFreeTexture() : game.getWallTexture());
                std::string svgContent = this->getSVGContent(textureFile);
                svgFile << this->replaceSVGCoordinates(svgContent, j * 10, i * 10);
            }
        }

        for (unsigned int j = 0; j < game.getMap().getLongestRowCount() - game.getMap().getRow(i).length(); j++)
        {
            std::string textureFile = game.getWallTexture();
            std::string svgContent = this->getSVGContent(textureFile);
            svgFile << this->replaceSVGCoordinates(svgContent, (j + game.getMap().getRow(i).length()) * 10, i * 10);
        }
    }

    svgFile << "</svg>";
    svgFile.close();
}