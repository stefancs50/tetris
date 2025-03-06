#include <vector>
#include "Gui.h"
#include "raylib.h"


Gui::Gui(){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Stefans Tetris");    
    font = LoadFont("resources/fonts/alpha_beta.png");
    lines = 0;
    score = 0;
    brick_count = 0;
}

Gui::~Gui(){
    UnloadFont(font);
    CloseWindow();
}

void Gui::draw(){
    int x = 300;
    DrawText("Next brick:", x, 10, 20, WHITE);
    DrawText("Brick count:", x, 150, 20, WHITE);
    DrawText("Lines:", x, 200, 20, WHITE);
    DrawText("Score:", x, 250, 20, WHITE);
    DrawText(TextFormat("%d", brick_count), x, 170, 20, WHITE);
    DrawText(TextFormat("%d", lines), x, 220, 20, WHITE);
    DrawText(TextFormat("%d", score), x, 270, 20, WHITE);
}

void Gui::increment_brick_count(){
    brick_count += 1;
}

void Gui::increment_lines_by(int l){
    lines += l;
}

void Gui::increment_score_by(int s){
    score += s;
}

