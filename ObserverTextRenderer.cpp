#include "ObserverTextRenderer.h"
#include "Map.h"

void ObserverTextRenderer::render(const Game& game) const {
    this->stream << "\n╔";
    for (unsigned int i = 0; i < game.getMap().getLongestRowCount()*2; i++) { this->stream << "═"; }
    this->stream << "╗" << std::endl;

    for (unsigned int i = 0; i < game.getMap().getColumnCount(); i++) {
        this->stream << "║";
        std::string row = game.getMap().getRow(i);
        for (unsigned int j = 0; j < row.size(); j++)
        {
            if (game.heroIsHere(j,i)){
                this->stream << "┣┫";
            }
            else if(game.countMonstersHere(j,i) > 0){
                this->stream << (game.countMonstersHere(j,i) > 1 ? "MM" : "M░");
            }
            else{
                this->stream << (game.getMap().get(j,i) == Map::Free ? "░░" : "██");
            }
            
        }
        
        for (unsigned int j = 0; j < game.getMap().getLongestRowCount() - game.getMap().getRow(i).length(); j++) {
            this->stream << "██";
        }
        this->stream << "║" << std::endl;
    }

    this->stream << "╚";
    for (unsigned int i = 0; i < game.getMap().getLongestRowCount()*2; i++) { this->stream << "═"; }
    this->stream << "╝" << std::endl;
}