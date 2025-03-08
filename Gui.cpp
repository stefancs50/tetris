#include <vector>
#include "Gui.h"
#include "raylib.h"
#include "constants.h"


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

void Gui::draw(bool game_over){

    if(game_over){
        DrawText("Game Over", 45, 80, 30, WHITE);
        DrawText("Press any key to restart", 50, 150, 10, WHITE);
    }

    DrawRectangle(0, 0 , PIXEL_SIZE, SCREEN_HEIGHT, DARKGRAY);
    DrawRectangle(11 * PIXEL_SIZE , 0, PIXEL_SIZE , SCREEN_HEIGHT, DARKGRAY);

    int center = SCREEN_WIDTH / 4 + SCREEN_WIDTH / 2;

    DrawTextCentered("Next", center, 10, 20, WHITE);
    DrawTextCentered("Brick count", center, 150, 20, WHITE);
    DrawTextCentered("Lines:", center, 200, 20, WHITE);
    DrawTextCentered("Score:", center, 250, 20, WHITE);
    DrawTextCentered(TextFormat("%d", brick_count), center, 170, 20, WHITE);
    DrawTextCentered(TextFormat("%d", lines), center, 220, 20, WHITE);
    DrawTextCentered(TextFormat("%d", score), center, 270, 20, WHITE);
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

void Gui::reset()
{
    lines = 0;
    score = 0;
    brick_count = 0;    
}

void Gui::DrawTextCentered(const char *text, int posX, int posY, int fontSize, Color color)
{
    int width = MeasureText(text, fontSize);
    int centered = posX - width / 2;
    DrawText(text, centered, posY, fontSize, color);
}
