#pragma once

#include "Pixel.h"
#include "raylib.h"
#include "Brick.h"

class Core{

public:
    Core();
    void runFrame();
    void init();
    void draw();
    void detect_keys();
    int grid[10][20];
    Color Colors[18]{ BLACK, BLUE, GREEN, YELLOW, BROWN, RED, WHITE, ORANGE, PINK, PURPLE, GOLD,
        Color { 255, 0, 255, 255 },// Magenta
        Color { 128, 128, 128, 255 }, // Grau
        Color { 64, 64, 64, 255 },     // Dunkelgrau
        Color { 192, 192, 192, 255 },   // Hellgrau
        Color { 192, 192, 192, 255 }, // Silber
        Color { 0, 255, 255, 255 },// Cyan
        Color { 192, 192, 192, 255 }  // hellgrau
        };
private:
    double deltatime;
    Brick current_brick;
    Brick next_brick;
    int height = 20;
    int width = 10;
    int pixel_size = 20;
    bool isAllowedToMove(int key);
    void lockBrick();
    Brick getNewBrick();
};
