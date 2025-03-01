#include <stdlib.h>
#include "Core.h"
#include "Pixel.h"
#include "raylib.h"
#include "Bricks.h"

Core::Core(){
    height = 20;
    width = 10;
    this->init();
}

void Core::runFrame(){
    if(!game_over)
    {
        BeginDrawing(); 
        detect_keys();
        if(deltatime > 50){   //TODO better time calculation
            deltatime = 0;
            if(isAllowedToMove(KEY_DOWN)){
                current_brick.move_down();
            }
        }else if(deltatime < 25){  
            //detect_keys();
        }
        deltatime += GetFrameTime() * 100;
        draw();
        EndDrawing();
    }
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
    game_over = false;
    current_brick = getNewBrick();

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
    if(IsKeyPressed(KEY_UP)&& isAllowedToMove(KEY_UP)){
        current_brick.rotate();
    }

    if(IsKeyDown(KEY_DOWN) && isAllowedToMove(KEY_DOWN)){
        current_brick.move_down();
    }

    if(IsKeyDown(KEY_LEFT) && isAllowedToMove(KEY_LEFT)){
        current_brick.move_left();
    }

    if(IsKeyDown(KEY_RIGHT) && isAllowedToMove(KEY_RIGHT)){
        current_brick.move_right();
    }
}

bool Core::isAllowedToMove(int key){
    int offset_x = current_brick.offset_x;
    int offset_y = current_brick.offset_y;

    if(offset_y == 0){ //when it spawns
        for(Pixel p : current_brick.getPixels()){ 
            if(grid[p.x + offset_x][p.y + offset_y] != 17){ //touches locked brick
                lockBrick();
                game_over = true;
                return false;
            }
        }
    }

    if(key == KEY_DOWN){
        offset_y += 1;
        for(Pixel p : current_brick.getPixels()){ 
            if(grid[p.x + offset_x][p.y + offset_y] != 17){ //touches locked brick
                lockBrick();
                return false;
            }  
            if(p.y + offset_y > 19){ //down
                lockBrick();
                return false;
            }  
        }
    }

    if(key == KEY_LEFT){
        offset_x -= 1;
        
        for(Pixel p : current_brick.getPixels()){ 
            if(p.x + offset_x < 0){ //left
                return false;
            }

            if(grid[p.x + offset_x][p.y + offset_y] != 17){ //touches locked brick
                return false;
            }
        }
    }

    if(key == KEY_RIGHT){
        offset_x += 1;
        for(Pixel p : current_brick.getPixels()){ //right
            if(p.x + offset_x > 9){
                return false;
            }

            if(grid[p.x + offset_x][p.y + offset_y] != 17){ //touches locked brick
                return false;
            }
        }
    }

    if(key == KEY_UP){
        for(Pixel p : current_brick.getPixels(true)){ //right
            if(p.x + offset_x > 9){ //left
                return false;
            }
            if(p.x + offset_x > 9){ //right
                return false;
            }
            if(p.y + offset_y > 19){ //down
                return false;
            }  
            if(grid[p.x + offset_x][p.y + offset_y] != 17){ //touches locked brick
                return false;
            }
        }
    }
    return true;
}

void Core::lockBrick(){
    for(Pixel p : current_brick.getPixels()){ 
        grid[p.x + current_brick.offset_x][p.y + current_brick.offset_y] = p.color;
    }
    current_brick.undraw();
    current_brick = getNewBrick();

}

Brick Core::getNewBrick()
{
    Brick allbricks[7] = { QuadBrick(), LBrick(), ZBrick(), LineBrick(), TriBrick(), LTwoBrick(), ZTwoBrick() };
    int index = rand() % 7;
    return allbricks[index];
}
