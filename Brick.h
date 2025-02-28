#pragma once
#include "Pixel.h"
#include "raylib.h"
#include <vector>

using namespace std;

class Brick{

public:
    Brick();
    void setposition(int x, int y);
    void move_left();
    void move_down();
    void move_right();
    void rotate();
    void draw();
    vector<Pixel> getPixels(bool incrementstate = false);
    vector<Pixel> pixels[4];
    
    Color Colors[18]{ BLACK, BLUE, GREEN, YELLOW, BROWN, RED, WHITE, ORANGE, PINK, PURPLE, GOLD,
        Color { 255, 0, 255, 255 },// Magenta
        Color { 128, 128, 128, 255 }, // Grau
        Color { 64, 64, 64, 255 },     // Dunkelgrau
        Color { 192, 192, 192, 255 },   // Hellgrau
        Color { 192, 192, 192, 255 }, // Silber
        Color { 0, 255, 255, 255 },// Cyan
        Color { 192, 192, 192, 255 }  // hellgrau
    };
    int offset_x, offset_y;
    void undraw();
    int rotatonstate = 0;

protected: 
    int pixel_size = 20;
};
