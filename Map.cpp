#include "Map.h"
#include <string>
#include <fstream>
#include <regex>

Map::Map() { }

Map::Map(std::string filename) {
    std::ifstream stream(filename);
    if(!stream.good()) throw std::runtime_error("The given file was not found: " + filename);

    std::regex replaceNewLine("[\r\n]+$");
    this->longestRowCount = 0;
    
    std::string currentLine;
    while(std::getline(stream, currentLine)){
        currentLine = std::regex_replace(currentLine, replaceNewLine, "");
        if (currentLine.length() > this->longestRowCount) this->longestRowCount = currentLine.length();
        map.push_back(currentLine);
    }
    
    stream.close();
}

Map::type Map::get(unsigned int x, unsigned int y) const {
    if(y >= map.size() || y < 0)
        throw Map::WrongIndexException("y is out of range");

    if(x >= map[y].length() || x < 0)
        throw Map::WrongIndexException("x is out of range");
    
    if(map[y][x] == '#')
        return Map::type::Wall;
    else
        return Map::type::Free;
}