#pragma once

#include "Pixel.h"
#include "raylib.h"
#include "Brick.h"
#include "Gui.h"

class Core{

public:
    Core();
    void runFrame();
    void init();
    void draw();
    void detect_keys();
    int grid[10][20];
    Color Colors[9]{ BLACK,
        Color{ 0, 255, 255, 255 }, // Cyan (I-Block)
        Color{ 0, 0, 255, 255 }, // Blau (J-Block)
        Color{ 255, 165, 0, 255 }, // Orange (L-Block)
        Color{ 255, 255, 0, 255 }, // Gelb (O-Block)
        Color{ 0, 255, 0, 255 }, // Grün (S-Block)
        Color{ 128, 0, 128, 255 }, // Lila (T-Block)
        Color{ 255, 0, 0, 255 }, // Rot (Z-Block)
        Color { 192, 192, 192, 255 }  // hellgrau
        };
private:
    Gui gui;
    float brickspeed;
    
    float time;
    bool game_over;
    double deltatime;
    Brick current_brick;
    Brick next_brick;
    int height = 20;
    int width = 10;
    int PIXEL_SIZE = 20;
    bool isAllowedToMove(int key);
    void lockBrick();
    int last_Brick_index;
    Brick getNewBrick();
    void check_line_full();
    void remove_line(int y_index);
};
