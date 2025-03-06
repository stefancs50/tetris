#include <stdlib.h>
#include "Core.h"
#include "Pixel.h"
#include "raylib.h"
#include "Bricks.h"
#include "Constants.h"

Core::Core(){
    height = 20;
    width = 10;

    brickspeed = 0.5; 
    time = GetTime();

    init();
}


void Core::runFrame(){
    float currenttime = GetTime();

    BeginDrawing();
    ClearBackground(BLACK);

    if(!game_over)
    {
        if(currenttime - time > brickspeed){
            time = currenttime;
            if(isAllowedToMove(KEY_DOWN)){
                current_brick.move_down();
            }
        }

        detect_keys();
        check_line_full();
        draw();
    }
    else
    {
        if (GetKeyPressed()) {
            init();
        }
    }

    gui.draw(game_over);

    EndDrawing();
}

void Core::draw()
{
    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            DrawRectangle(PIXEL_SIZE + x * PIXEL_SIZE + 1, y * PIXEL_SIZE + 1, PIXEL_SIZE - 1, PIXEL_SIZE - 1, Colors[grid[x][y]]);
        }
    }
    current_brick.draw();
    next_brick.draw_next_brick();
}

void Core::init()
{
    game_over = false;
    current_brick = getNewBrick();
    next_brick = getNewBrick();
    brickspeed = 0.5;
    gui.reset();

    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            grid[x][y] = BACKGROUND_COLOR_INDEX;
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

            if(grid[p.x + offset_x][p.y + offset_y] != BACKGROUND_COLOR_INDEX){ //touches locked brick
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

            if(grid[p.x + offset_x][p.y + offset_y] != BACKGROUND_COLOR_INDEX){ //touches locked brick
                return false;
            }
        }
    }

    if(key == KEY_UP){
        for(Pixel p : current_brick.getPixels(true)){ //right
            if(p.x + offset_x < 0){ //left
                return false;
            }
            if(p.x + offset_x > 9){ //right
                return false;
            }
            if(p.y + offset_y > 19){ //down
                return false;
            }  
            if(grid[p.x + offset_x][p.y + offset_y] != BACKGROUND_COLOR_INDEX){ //touches locked brick
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
    next_brick.draw_next_brick(true);
    current_brick = next_brick;
    next_brick = getNewBrick();

    gui.increment_brick_count();;
    brickspeed -= 0.01;
}

Brick Core::getNewBrick()
{
    Brick allbricks[7] = { QuadBrick(), LBrick(), ZBrick(), LineBrick(), TriBrick(), LTwoBrick(), ZTwoBrick() };
    int index = rand() % 7;
    return allbricks[index];
}

void Core::check_line_full(){
    int removed_lines = 0;

    for(int y = 0; y < height; y++)
    {
        int full = 0;
        for(int x = 0; x < width; x++)
        {
            if(grid[x][y] != 17){
                full++;
            }
            if(full == width){
                remove_line(y);
                removed_lines++;
            }
        }
    }

    if(removed_lines > 0){
        switch(removed_lines){
            case 1:
                gui.increment_score_by(100);
                break;
            case 2:
                gui.increment_score_by(300);
                break;
            case 3:
                gui.increment_score_by(500);
                break;
            case 4:
                gui.increment_score_by(800);
                break;
        }
    }
    gui.increment_lines_by(removed_lines);
}

void Core::remove_line(int y_index){
    for(int y = y_index; y > 0; y--)
    {
        for(int x = 0; x < width; x++)
        {
            if(y == 0){
                grid[x][y] = BACKGROUND_COLOR_INDEX;
            }else{
                grid[x][y] = grid[x][y - 1];
            }
        }
    }
}
