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