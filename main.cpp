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

    Entity* ent1;
    Entity* ent2;

    if(argc != 7 || !(isNumeric(argv[2]) && isNumeric(argv[3]) && isNumeric(argv[5]) && isNumeric(argv[6])) ){
        std::cout << "Wrong initial data given, using default values." << std::endl;
        ent1 = new Entity(150, 10, "Maple");
        ent2 = new Entity(45, 30, "Sally");
    }else{
        ent1 = new Entity(stof(argv[2]), stof(argv[3]), argv[1]);
        ent2 = new Entity(stof(argv[5]), stof(argv[6]), argv[4]);
    }

    Game* game = new Game(*ent1,*ent2);
    game->Start();

    delete ent1;
    delete ent2;
    delete game;

    return 0;
}
