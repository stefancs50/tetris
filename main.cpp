#include <iostream>
#include <raylib.h>
#include <vector>
#include "Core.h"

using namespace std;

int main () {

    const int SCREEN_WIDTH = 201;
    const int SCREEN_HEIGHT = 401;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Stefans Tetris");    
   
    Core core;
    SetTargetFPS(20);
    core.draw();

    while (WindowShouldClose() == false){
        core.runFrame();
    }

    CloseWindow();
}