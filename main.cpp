#include <iostream>
#include <raylib.h>
#include <vector>
#include "Core.h"
#include "Gui.h"

using namespace std;

int main () {
   
    Core game;
    Gui gui;
    int framerate = 18;
    SetTargetFPS(framerate);
    
    while (WindowShouldClose() == false){       
        game.runFrame();
    }
    

    CloseWindow();
    return 0;
}