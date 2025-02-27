#include "Core.h"
#include "Pixel.h"
#include "raylib.h"
#include "Bricks.h"

Core::Core(){
    height = 20;
    width = 10;
    this->init();
}

void Core::draw()
{
    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            DrawRectangle(x * pixel_size + 1, y * pixel_size + 1, pixel_size - 1, pixel_size - 1, Colors[grid[x][y]]);
        }
    }

    current_brick.draw();
}

void Core::init()
{
    current_brick = LBrick();

    for(int i = 0; i < width; i++)
    {
        for(int y = 0; y < height; y++)
        {
            grid[i][y] = (sizeof(Colors)/sizeof(Colors[0]) ) - 1;
        }
    }
}

void Core::detect_keys()
{
    int key = GetKeyPressed();
    switch(key){
        case KEY_DOWN:
            current_brick.move_down();
            break;
        case KEY_UP:
            current_brick.rotate();
            break;
        case KEY_LEFT:
            current_brick.move_left();
            break;
        case KEY_RIGHT:
            current_brick.move_right();
            break;
        default:
            break;
    }
}
