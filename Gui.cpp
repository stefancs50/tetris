#include "Gui.h"
#include "raylib.h"


Gui::Gui(){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Stefans Tetris");    
    font = LoadFont("resources/fonts/alpha_beta.png");

}

