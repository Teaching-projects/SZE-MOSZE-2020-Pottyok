#include "MarkedMap.h"
#include <string>
#include <iostream>

MarkedMap::MarkedMap(std::string &fileName) : Map(fileName){
    for (int i = 0; i < (int)this->getColumnCount(); i++)
    {
        std::string currentRow = this->getRow(i);
        for (int j = 0; j < (int)currentRow.length(); j++)
        {
            if(currentRow[j] == 'H'){
                currentRow[j] = ' ';

                this->setRow(i,currentRow);
                Position tempHeroPosition = Position(j,i);
                this->heroPosition = tempHeroPosition;
            }
            else if(isdigit(currentRow[j])){
                Position tempMonsterPosition = Position(j,i);
                if ( this->monsterPositions.find(currentRow[j]) == this->monsterPositions.end() ) {
                    this->monsterPositions.insert(std::pair<char,std::list<Position>>(currentRow[j],NULL));
                }
                this->monsterPositions[currentRow[j]].push_back(tempMonsterPosition);
                currentRow[j] = ' ';
                this->setRow(i,currentRow);
            }
        }
        
    }
}

Position MarkedMap::getHeroPosition() const {
    return this->heroPosition;
}

std::list<Position> MarkedMap::getMonsterPositions(char c) {
    std::list<Position> positions = this->monsterPositions[c];

    return positions;
}

int MarkedMap::getMaxMonsterNumber() {
    int monsterNumber = 1;
    for( auto& [key, val] : this->monsterPositions ) {
        if((int)(key - '0') > monsterNumber)
            monsterNumber = (int)(key - '0');
    }
    return monsterNumber;
}