#include <stdio.h>
#include <iostream>
#include "Game.h"
#include "Entity.h"

using namespace std;

int isdigits(const string & s) {
    for (char c : s) if (!isdigit(c)) return (0);
    return (1);
}

int main (int argc, char *argv[]) {

    Entity* ent1;
    Entity* ent2;

    if(argc != 7 || !(isdigits(argv[2]) && isdigits(argv[3]) && isdigits(argv[5]) && isdigits(argv[6])) ){
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
