#include "JsonParser.h"
#include <iostream>

#include <fstream>
#include <regex>
#include <algorithm>

std::map<std::string, std::any> JsonParser::ParseString(const std::string &input){
    std::map<std::string, std::any> data;
    std::smatch searchMatches;
    
    const std::regex searchRegex("\"([a-zA-Z0-9]+)\"\\s*:\\s*(\"[^\"]+\")?([0-9]*[.]?[0-9]+)?(true|false)?[,\n}]{1}");

    std::string worker(input), key, value;

    while (std::regex_search(worker, searchMatches, searchRegex))
    {
        key = searchMatches[1].str();
        if(searchMatches[2].str() != ""){
            value = searchMatches[2].str();
            value.erase(std::remove(value.begin(), value.end(), '\"'), value.end());
            data[key] = value;
        }
        else if(searchMatches[3].str() != ""){
            value = searchMatches[3].str();
            if(searchMatches[3].str().find('.') != std::string::npos){
                data[key] = stof(value);
            } else {
                data[key] = stoi(value);
            }
        }
        else if(searchMatches[4].str() != ""){
            value = searchMatches[4].str();
            data[key] = value == "true" ? true : false;
        }

        worker = searchMatches.suffix();
    }

    return data;
}

std::map<std::string, std::any> JsonParser::ParseFile(const std::string &fileName){
    std::ifstream stream(fileName);
    if(!stream.good()) throw std::runtime_error("The given file was not found: " + fileName);

    std::map<std::string, std::any> data = ParseStream(stream);
    
    stream.close();

    return data;
}

std::map<std::string, std::any> JsonParser::ParseStream(std::istream &stream){
  std::string fileContent, currentLine;
  while(std::getline(stream, currentLine)){
    fileContent += currentLine;
  }

  return ParseString(fileContent);
}