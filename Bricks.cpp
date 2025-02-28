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

ZBrick::ZBrick(){
    offset_x = 4;
    pixels.push_back(Pixel{ 0, 0, 3 });
    pixels.push_back(Pixel{ 0, 1, 3 });
    pixels.push_back(Pixel{ 1, 1, 3 });
    pixels.push_back(Pixel{ 1, 2, 3 });
}

LineBrick::LineBrick(){
    offset_x = 3;
    pixels.push_back(Pixel{ 0, 0, 4 });
    pixels.push_back(Pixel{ 1, 0, 4 });
    pixels.push_back(Pixel{ 2, 0, 4 });
    pixels.push_back(Pixel{ 3, 0, 4 });
}

TriBrick::TriBrick(){
    offset_x = 4;
    pixels.push_back(Pixel{ 0, 0, 5 });
    pixels.push_back(Pixel{ 1, 0, 5 });
    pixels.push_back(Pixel{ 2, 0, 5 });
    pixels.push_back(Pixel{ 1, 1, 5 });
}