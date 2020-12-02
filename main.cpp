#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

#include "PreparedGame.h"
#include "JSON.h"
#include "ObserverTextRenderer.h"
#include "HeroTextRenderer.h"

const std::map<int,std::string> error_messages = {
    { 1 , "Bad number of arguments. Only a single map file should be provided." },
    { 2 , "The provided map file is not accessible." },
    { 3 , "JSON parsing error." }
};

void bad_exit(int exitcode){
    std::cerr 
        << (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
        << std::endl;
    exit(exitcode);
}

int main(int argc, char** argv){
    if (argc != 2) bad_exit(1);
    
    if (!std::filesystem::exists(argv[1])) bad_exit(2);

    try { 
        PreparedGame game(argv[1]);
        std::ofstream stream = std::ofstream("log.txt");
        game.registerRenderer(new HeroTextRenderer());
        game.registerRenderer(new ObserverTextRenderer(stream));
        game.run();
    } catch (const JSON::ParseException& e) {bad_exit(3);}

    return 0;
}