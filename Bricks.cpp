#include "Bricks.h"
#include "Pixel.h"

QuadBrick::QuadBrick(){
    offset_x = 4;
    int color = 4;
    pixels[0].push_back(Pixel{ 0, 0, color });
    pixels[0].push_back(Pixel{ 0, 1, color });
    pixels[0].push_back(Pixel{ 1, 0, color });
    pixels[0].push_back(Pixel{ 1, 1, color });
    pixels[1] = pixels[2] = pixels[3] = pixels[0];
}

LBrick::LBrick(){
    offset_x = 3;
    int color = 2;
    pixels[0].push_back(Pixel{ 1, 0, color });
    pixels[0].push_back(Pixel{ 1, 1, color });
    pixels[0].push_back(Pixel{ 1, 2, color });
    pixels[0].push_back(Pixel{ 2, 0, color });

    pixels[1].push_back(Pixel{ 0, 1, color });
    pixels[1].push_back(Pixel{ 1, 1, color });
    pixels[1].push_back(Pixel{ 2, 1, color });
    pixels[1].push_back(Pixel{ 2, 2, color });

    pixels[2].push_back(Pixel{ 1, 0, color });
    pixels[2].push_back(Pixel{ 1, 1, color });
    pixels[2].push_back(Pixel{ 1, 2, color });
    pixels[2].push_back(Pixel{ 0, 2, color });

    pixels[3].push_back(Pixel{ 0, 0, color });
    pixels[3].push_back(Pixel{ 0, 1, color });
    pixels[3].push_back(Pixel{ 1, 1, color });
    pixels[3].push_back(Pixel{ 2, 1, color });
}

LTwoBrick::LTwoBrick(){
    offset_x = 4;
    int color = 3;
    pixels[0].push_back(Pixel{ 1, 0, color });
    pixels[0].push_back(Pixel{ 1, 1, color });
    pixels[0].push_back(Pixel{ 1, 2, color });
    pixels[0].push_back(Pixel{ 0, 0, color });

    pixels[1].push_back(Pixel{ 0, 1, color });
    pixels[1].push_back(Pixel{ 1, 1, color });
    pixels[1].push_back(Pixel{ 2, 1, color });
    pixels[1].push_back(Pixel{ 2, 0, color });

    pixels[2].push_back(Pixel{ 1, 0, color });
    pixels[2].push_back(Pixel{ 1, 1, color });
    pixels[2].push_back(Pixel{ 1, 2, color });
    pixels[2].push_back(Pixel{ 2, 2, color });

    pixels[3].push_back(Pixel{ 0, 1, color });
    pixels[3].push_back(Pixel{ 1, 1, color });
    pixels[3].push_back(Pixel{ 2, 1, color });
    pixels[3].push_back(Pixel{ 0, 2, color });
}

ZBrick::ZBrick(){
    offset_x = 3;
    int color = 5;
    pixels[0].push_back(Pixel{ 1, 0, color });
    pixels[0].push_back(Pixel{ 1, 1, color });
    pixels[0].push_back(Pixel{ 2, 1, color });
    pixels[0].push_back(Pixel{ 2, 2, color });

    pixels[1].push_back(Pixel{ 1, 1, color });
    pixels[1].push_back(Pixel{ 1, 2, color });
    pixels[1].push_back(Pixel{ 0, 2, color });
    pixels[1].push_back(Pixel{ 2, 1, color });

    pixels[2] = pixels[0];
    pixels[3] = pixels[1];
}

ZTwoBrick::ZTwoBrick(){
    offset_x = 4;
    int color = 7;
    pixels[0].push_back(Pixel{ 1, 0, color });
    pixels[0].push_back(Pixel{ 0, 1, color });
    pixels[0].push_back(Pixel{ 1, 1, color });
    pixels[0].push_back(Pixel{ 0, 2, color });

    pixels[1].push_back(Pixel{ 0, 1, color });
    pixels[1].push_back(Pixel{ 1, 1, color });
    pixels[1].push_back(Pixel{ 1, 2, color });
    pixels[1].push_back(Pixel{ 2, 2, color });

    pixels[2] = pixels[0];
    pixels[3] = pixels[1];
}

LineBrick::LineBrick(){
    offset_x = 3;
    offset_y = -2;
    int color = 1;
    pixels[0].push_back(Pixel{ 0, 2, color });
    pixels[0].push_back(Pixel{ 1, 2, color });
    pixels[0].push_back(Pixel{ 2, 2, color });
    pixels[0].push_back(Pixel{ 3, 2, color });

    pixels[1].push_back(Pixel{ 1, 0, color });
    pixels[1].push_back(Pixel{ 1, 1, color });
    pixels[1].push_back(Pixel{ 1, 2, color });
    pixels[1].push_back(Pixel{ 1, 3, color });

    pixels[2] = pixels[0];
    pixels[3] = pixels[1];
}

TriBrick::TriBrick(){
    offset_x = 3;
    int color = 6;
    pixels[0].push_back(Pixel{ 1, 0, color });
    pixels[0].push_back(Pixel{ 1, 1, color });
    pixels[0].push_back(Pixel{ 1, 2, color });
    pixels[0].push_back(Pixel{ 2, 1, color });

    pixels[1].push_back(Pixel{ 0, 1, color });
    pixels[1].push_back(Pixel{ 1, 2, color });
    pixels[1].push_back(Pixel{ 1, 1, color });
    pixels[1].push_back(Pixel{ 2, 1, color });

    pixels[2].push_back(Pixel{ 1, 0, color });
    pixels[2].push_back(Pixel{ 1, 1, color });
    pixels[2].push_back(Pixel{ 1, 2, color });
    pixels[2].push_back(Pixel{ 0, 1, color });

    pixels[3].push_back(Pixel{ 0, 1, color });
    pixels[3].push_back(Pixel{ 1, 0, color });
    pixels[3].push_back(Pixel{ 1, 1, color });
    pixels[3].push_back(Pixel{ 2, 1, color });
}