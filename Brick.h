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
        
    int offset_x, offset_y;
    void undraw();
    void draw_next_brick(bool undraw = false);
    int rotatonstate = 0;
};
