#include <stdio.h>
#include <iostream>
#include "Game.h"
#include "Entity.h"

using namespace std;

int main (int argc, char *argv[]) {

    Entity* ent1 = new Entity(150,10,"Maple");
    Entity* ent2 = new Entity(45,30,"Sally");

    Game* game = new Game(*ent1,*ent2);
    game->Start();

    delete ent1;
    delete ent2;
    delete game;

    return 0;
}
