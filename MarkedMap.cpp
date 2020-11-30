#include "MarkedMap.h"
#include <string>

MarkedMap::MarkedMap(std::string &fileName) : Map(fileName){
    for (int i = 0; i < (int)this->getColumnCount(); i++)
    {
        std::string currentRow = this->getRow(i);
        for (int j = 0; j < (int)currentRow.length(); i++)
        {
            if(currentRow[j] == 'H'){
                currentRow[j] = ' ';
                this->setRow(i,currentRow);
                Position tempHeroPosition = Position(i,j);
                this->heroPosition = tempHeroPosition;
            }
            else if(isdigit(currentRow[j])){
                currentRow[j] = ' ';
                this->setRow(i,currentRow);
                Position tempMonsterPosition = Position(i,j);
                if ( this->monsterPositions.find(currentRow[j]) == this->monsterPositions.end() ) {
                    this->monsterPositions.insert(std::pair<char,std::list<Position>>(currentRow[j],NULL));
                }
                this->monsterPositions[currentRow[j]].push_back(tempMonsterPosition);
            }
        }
        
    }
}

Position MarkedMap::getHeroPosition() const {
    return this->heroPosition;
}

std::list<Position> MarkedMap::getMonsterPositions(char c) const {
    std::list<Position> monsterPositionsList;
    for( auto const& [key, val] : this->monsterPositions ) {
        if(key == c){
            for (auto const& i : val) {
                monsterPositionsList.push_back(i);
            }
        }
    }
    return monsterPositionsList;
}

int MarkedMap::getMaxMonsterNumber() {
    int monsterNumber = 1;
    for( auto const& [key, val] : this->monsterPositions ) {
        if((int)key > monsterNumber)
            monsterNumber = (int)key;
    }
    return monsterNumber;
}