#pragma once
#include <vector>
#include "raylib.h"


class Gui{

public:
    Gui();
    ~Gui();
    void draw();
    void increment_brick_count();
    void increment_lines_by(int lines);
    void increment_score_by(int score);

    
protected: 
    Font font;
    const int SCREEN_WIDTH = 471;
    const int SCREEN_HEIGHT = 401;

    int brick_count = 0;
    int lines = 0;
    int score = 0;
};
