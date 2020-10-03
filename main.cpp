#include <stdio.h>
#include <iostream>
#include "Game.h"
#include "Entity.h"
#include <fstream>

using namespace std;

int isNumeric(const string & chars) {
    for (char c : chars){
        if (!isdigit(c)) return false;
    }
    
    return true;
}

int main (int argc, char *argv[]) {
    
    Entity ent1(150, 10, "Maple");
    Entity ent2(45, 30, "Sally");
    if(argc != 3){
        std::cout << "Wrong initial data given, using default values." << std::endl;
    }else{
        try{
            ent1 = Entity::parseUnit(argv[1]);
            ent2 = Entity::parseUnit(argv[2]);
        }catch(std::exception& e){
            std::cout << "An error occured while the program was running: " << e.what() << std::endl;
            return 1;
        }
    }

    Game game(ent1,ent2);
    game.Start();
    return 0;
}
