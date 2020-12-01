#include <iostream>
#include <map>

#include "Renderer.h"

void Renderer::render(const Game& game) const {
    int playerLightRadius = std::get<Hero>(game.getHeroes()[0].getEntity()).getLightRadius();
    int playerX = game.getHeroes()[0].getX();
    int playerY = game.getHeroes()[0].getY();
    unsigned int border_width = (std::min<int>(playerLightRadius, playerX) + 1 + std::min<int>(playerLightRadius, game.getMap().getLongestRowCount() - 1 - playerX)) * 2;
    
    std::cout << "\n╔";
    for (unsigned int i = 0; i < border_width; i++) { std::cout << "═"; }
    std::cout << "╗" << std::endl;

    for (unsigned int i = (unsigned int)std::max<int>(playerY - playerLightRadius , 0); i < (unsigned int)std::min<int>(game.getMap().getColumnCount(), playerY + 1 + playerLightRadius); i++) {
        std::cout << "║";
        std::string row = game.getMap().getRow(i);
        for (unsigned int j = (unsigned int)std::max<int>(playerX - playerLightRadius , 0); j < (unsigned int)std::min<int>(row.size(), playerX + 1 + playerLightRadius); j++)
        {
            if (game.heroIsHere(j,i)){
                std::cout << "┣┫";
            }
            else if(game.countMonstersHere(j,i) > 0){
                std::cout << (game.countMonstersHere(j,i) > 1 ? "MM" : "M░");
            }
            else{
                std::cout << (game.getMap().get(j,i) == Map::Free ? "░░" : "██");
            }
            
        }
        
        for (unsigned int j = (unsigned int)std::min<int>(row.size(), playerX + 1 + playerLightRadius); j < (unsigned int)std::min<int>((playerX + 1 + playerLightRadius), game.getMap().getLongestRowCount()); j++) {
            std::cout << "██";
        }
        std::cout << "║" << std::endl;
    }

    std::cout << "╚";
    for (unsigned int i = 0; i < border_width; i++) { std::cout << "═"; }
    std::cout << "╝" << std::endl;
}