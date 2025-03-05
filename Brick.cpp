#include "Brick.h"
#include "Pixel.h"
#include "raylib.h"

Brick::Brick(){
    offset_x = 0;
    offset_y = 0;
}

void Brick::setposition(int x, int y){
    offset_x = x;
    offset_y = y;
}

void Brick::draw(){
    for(Pixel p : getPixels()){
        DrawRectangle((offset_x + p.x) * pixel_size + 1, (offset_y + p.y) * pixel_size + 1, pixel_size - 1, pixel_size - 1, Colors[p.color]);
    }
}

void Brick::undraw(){
    for(Pixel p : getPixels()){
        DrawRectangle((offset_x + p.x) * pixel_size + 1, (offset_y + p.y) * pixel_size + 1, pixel_size - 1, pixel_size - 1, Colors[(sizeof(Colors)/sizeof(Colors[0]) ) - 1]);
    }
}

void Brick::draw_next_brick(bool undraw)
{
    int giu_x = 12;
    int gui_y = 1;

    if(undraw){
        for(Pixel p : getPixels()){
            DrawRectangle((giu_x + offset_x + p.x) * pixel_size + 1, (gui_y + offset_y + p.y) * pixel_size + 1, pixel_size - 1, pixel_size - 1, Colors[0]);
        }
    }else{
        for(Pixel p : getPixels()){
            DrawRectangle((giu_x + offset_x + p.x) * pixel_size + 1, (gui_y + offset_y + p.y) * pixel_size + 1, pixel_size - 1, pixel_size - 1, Colors[p.color]);
        }
    }
}

vector<Pixel> Brick::getPixels(bool incrementstate){
    if(incrementstate)
    {
        if(rotatonstate == 3){
            return pixels[0];
        }else{
            return pixels[rotatonstate + 1];
        }
    }
    return pixels[rotatonstate];
}


void Brick::move_down(){
    undraw();
    offset_y +=1;
    draw();
}

void Brick::move_left(){
    undraw();
    offset_x -=1;
    draw();
}

void Brick::move_right(){
    undraw();
    offset_x +=1;
    draw();
}

void Brick::rotate(){
    undraw();
    if(rotatonstate == 3){
        rotatonstate = 0;
    }else{
        rotatonstate++;
    }
    draw();
}