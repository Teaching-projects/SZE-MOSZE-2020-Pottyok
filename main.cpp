#include <stdio.h>
#include <iostream>
#include "Game.h"
#include "Entity.h"

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
    if(argc != 7 || !(isNumeric(argv[2]) && isNumeric(argv[3]) && isNumeric(argv[5]) && isNumeric(argv[6])) ){
        std::cout << "Wrong initial data given, using default values." << std::endl;
    }else{
        Entity ent1FromArgs(stof(argv[2]), stof(argv[3]), argv[1]);
        Entity ent2FromArgs(stof(argv[5]), stof(argv[6]), argv[4]);
        ent1 = ent1FromArgs;
        ent2 = ent2FromArgs;
    }

    Game game(ent1,ent2);
    game.Start();
    return 0;
}
