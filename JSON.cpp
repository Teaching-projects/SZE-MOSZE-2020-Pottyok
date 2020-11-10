#include "JSON.h"
#include <iostream>

#include <fstream>
#include <regex>
#include <algorithm>

JSON JSON::parseFromString(const std::string &input){
    std::map<std::string, std::any> data;
    std::smatch searchMatches;
    
    const std::regex searchRegex("\"([^\"]+)\"\\s*:\\s*(\"[^\"]+\")?([0-9]*[.]?[0-9]+)?(true|false)?(\\[[^\\]]+\\])?[,\r\n}]{1}");
    const std::regex syntaxRegex("\\w*[{]{1}[^}]+}{1}\\w*");

    std::string worker(input), key, value;
    
    if(!std::regex_match(input, syntaxRegex)){
        throw JSON::ParseException("Given file has bad syntax");
    }

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
        else if(searchMatches[5].str() != ""){
            value = searchMatches[5].str();
            value.erase(std::remove(value.begin(), value.end(), '['), value.end());
            value.erase(std::remove(value.begin(), value.end(), ']'), value.end());
            data[key] = value;
        }

        worker = searchMatches.suffix();
    }

    return *(new JSON(data));
}

JSON JSON::parseFromFile(const std::string &fileName){
    std::ifstream stream(fileName);
    if(!stream.good()) throw JSON::ParseException("The given file was not found: " + fileName);

    JSON json = parseFromStream(stream);
    
    stream.close();

    return json;
}

JSON JSON::parseFromStream(std::istream &stream){
  std::string fileContent, currentLine;
  while(std::getline(stream, currentLine)){
    fileContent += currentLine;
  }

  return parseFromString(fileContent);
}