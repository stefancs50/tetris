#include <iostream>
#include <raylib.h>
#include <vector>

using namespace std;

Color PixelColors [6] = { BLACK, BLUE, GREEN, YELLOW, BROWN, RED };

class Pixel{
    public:
        Pixel()
        {
        }

        Pixel(int color)
        {
            this->color = color;
        }

        Color getcolor(){
            return PixelColors[this->color];
        }

        unsigned int getheight(){
            return this->h;
        }

        unsigned int getwidth(){
            return this->w;
        }
        void setColor(unsigned int c){
            this->color = c;
        }
    private:
        unsigned int h = 10;
        unsigned int w = 10;
        unsigned int color = 0;
};

class Core{


    public:
        Core(){
        this->init();
    }

    void draw()
    {
        for(int x = 0; x < width; x++)
        {
            for(int y = 0; y < height; y++)
            {
                Pixel p = grid[x][y];
                DrawRectangle(x* p.getwidth(), y * p.getheight(), p.getwidth() - 1, p.getheight() - 1, p.getcolor());
            }
        }
    }

    void init()
    {
        for(int i = 0; i < width; i++)
        {
            for(int y = 0; y < height; y++)
            {
                grid[i][y] = Pixel(5);
            }
        }
    }
        
    Pixel grid[10][20];

    private:
        Color color = { 175, 175, 25, 255 };
        int height = 20;
        int width = 10;

};

int main () {

    const int SCREEN_WIDTH = 200;
    const int SCREEN_HEIGHT = 400;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Stefans Tetris");    
   
    Core grid;
    grid.grid[3][3].setColor(1);
    grid.grid[5][5].setColor(3);
    grid.grid[9][3].setColor(2);

    SetTargetFPS(60);
    
    while (WindowShouldClose() == false){
        BeginDrawing();
        grid.draw();
        EndDrawing();
    }

    CloseWindow();
}