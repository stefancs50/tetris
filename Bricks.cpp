#include "Bricks.h"
#include "Pixel.h"

QuadBrick::QuadBrick(){
    offset_x = 4;
    pixels.push_back(Pixel{ 0, 0, 1 });
    pixels.push_back(Pixel{ 0, 1, 1 });
    pixels.push_back(Pixel{ 1, 0, 1 });
    pixels.push_back(Pixel{ 1, 1, 1 });
}

LBrick::LBrick(){
    offset_x = 4;
    pixels.push_back(Pixel{ 0, 0, 2 });
    pixels.push_back(Pixel{ 0, 1, 2 });
    pixels.push_back(Pixel{ 0, 2, 2 });
    pixels.push_back(Pixel{ 1, 0, 2 });
}