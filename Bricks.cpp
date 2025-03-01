#include "Bricks.h"
#include "Pixel.h"

QuadBrick::QuadBrick(){
    offset_x = 4;
    pixels[0].push_back(Pixel{ 0, 0, 1 });
    pixels[0].push_back(Pixel{ 0, 1, 1 });
    pixels[0].push_back(Pixel{ 1, 0, 1 });
    pixels[0].push_back(Pixel{ 1, 1, 1 });
    pixels[1] = pixels[2] = pixels[3] = pixels[0];
}

LBrick::LBrick(){
    offset_x = 3;
    pixels[0].push_back(Pixel{ 1, 0, 2 });
    pixels[0].push_back(Pixel{ 1, 1, 2 });
    pixels[0].push_back(Pixel{ 1, 2, 2 });
    pixels[0].push_back(Pixel{ 2, 0, 2 });

    pixels[1].push_back(Pixel{ 0, 1, 2 });
    pixels[1].push_back(Pixel{ 1, 1, 2 });
    pixels[1].push_back(Pixel{ 2, 1, 2 });
    pixels[1].push_back(Pixel{ 2, 2, 2 });

    pixels[2].push_back(Pixel{ 1, 0, 2 });
    pixels[2].push_back(Pixel{ 1, 1, 2 });
    pixels[2].push_back(Pixel{ 1, 2, 2 });
    pixels[2].push_back(Pixel{ 0, 2, 2 });

    pixels[3].push_back(Pixel{ 0, 0, 2 });
    pixels[3].push_back(Pixel{ 0, 1, 2 });
    pixels[3].push_back(Pixel{ 1, 1, 2 });
    pixels[3].push_back(Pixel{ 2, 1, 2 });
}

LTwoBrick::LTwoBrick(){
    offset_x = 3;
    pixels[0].push_back(Pixel{ 1, 0, 8 });
    pixels[0].push_back(Pixel{ 1, 1, 8 });
    pixels[0].push_back(Pixel{ 1, 2, 8 });
    pixels[0].push_back(Pixel{ 0, 0, 8 });

    pixels[1].push_back(Pixel{ 0, 1, 8 });
    pixels[1].push_back(Pixel{ 1, 1, 8 });
    pixels[1].push_back(Pixel{ 2, 1, 8 });
    pixels[1].push_back(Pixel{ 2, 0, 8 });

    pixels[2].push_back(Pixel{ 1, 0, 8 });
    pixels[2].push_back(Pixel{ 1, 1, 8 });
    pixels[2].push_back(Pixel{ 1, 2, 8 });
    pixels[2].push_back(Pixel{ 2, 2, 8 });

    pixels[3].push_back(Pixel{ 0, 1, 8 });
    pixels[3].push_back(Pixel{ 1, 1, 8 });
    pixels[3].push_back(Pixel{ 2, 1, 8 });
    pixels[3].push_back(Pixel{ 0, 2, 8 });
}

ZBrick::ZBrick(){
    offset_x = 3;
    pixels[0].push_back(Pixel{ 1, 0, 3 });
    pixels[0].push_back(Pixel{ 1, 1, 3 });
    pixels[0].push_back(Pixel{ 2, 1, 3 });
    pixels[0].push_back(Pixel{ 2, 2, 3 });

    pixels[1].push_back(Pixel{ 0, 1, 3 });
    pixels[1].push_back(Pixel{ 1, 0, 3 });
    pixels[1].push_back(Pixel{ 1, 1, 3 });
    pixels[1].push_back(Pixel{ 2, 0, 3 });

    pixels[2].push_back(Pixel{ 0, 0, 3 });
    pixels[2].push_back(Pixel{ 0, 1, 3 });
    pixels[2].push_back(Pixel{ 1, 1, 3 });
    pixels[2].push_back(Pixel{ 1, 2, 3 });

    pixels[3].push_back(Pixel{ 0, 2, 3 });
    pixels[3].push_back(Pixel{ 1, 1, 3 });
    pixels[3].push_back(Pixel{ 1, 2, 3 });
    pixels[3].push_back(Pixel{ 2, 1, 3 });
}

ZTwoBrick::ZTwoBrick(){
    offset_x = 3;
    pixels[0].push_back(Pixel{ 0, 1, 7 });
    pixels[0].push_back(Pixel{ 1, 1, 7 });
    pixels[0].push_back(Pixel{ 1, 2, 7 });
    pixels[0].push_back(Pixel{ 2, 2, 7 });

    pixels[1].push_back(Pixel{ 0, 1, 7 });
    pixels[1].push_back(Pixel{ 1, 0, 7 });
    pixels[1].push_back(Pixel{ 1, 1, 7 });
    pixels[1].push_back(Pixel{ 2, 0, 7 });

    pixels[2].push_back(Pixel{ 0, 0, 7 });
    pixels[2].push_back(Pixel{ 0, 1, 7 });
    pixels[2].push_back(Pixel{ 1, 1, 7 });
    pixels[2].push_back(Pixel{ 1, 2, 7 });

    pixels[3].push_back(Pixel{ 0, 2, 3 });
    pixels[3].push_back(Pixel{ 1, 1, 3 });
    pixels[3].push_back(Pixel{ 1, 2, 3 });
    pixels[3].push_back(Pixel{ 2, 1, 3 });
}

LineBrick::LineBrick(){
    offset_x = 3;
    pixels[0].push_back(Pixel{ 1, 0, 4 });
    pixels[0].push_back(Pixel{ 1, 1, 4 });
    pixels[0].push_back(Pixel{ 1, 2, 4 });
    pixels[0].push_back(Pixel{ 1, 3, 4 });

    pixels[1].push_back(Pixel{ 0, 2, 4 });
    pixels[1].push_back(Pixel{ 1, 2, 4 });
    pixels[1].push_back(Pixel{ 2, 2, 4 });
    pixels[1].push_back(Pixel{ 3, 2, 4 });

    pixels[2].push_back(Pixel{ 2, 0, 4 });
    pixels[2].push_back(Pixel{ 2, 1, 4 });
    pixels[2].push_back(Pixel{ 2, 2, 4 });
    pixels[2].push_back(Pixel{ 2, 3, 4 });

    pixels[3].push_back(Pixel{ 0, 1, 4 });
    pixels[3].push_back(Pixel{ 1, 1, 4 });
    pixels[3].push_back(Pixel{ 2, 1, 4 });
    pixels[3].push_back(Pixel{ 3, 1, 4 });
}

TriBrick::TriBrick(){
    offset_x = 3;
    pixels[0].push_back(Pixel{ 1, 0, 5 });
    pixels[0].push_back(Pixel{ 1, 1, 5 });
    pixels[0].push_back(Pixel{ 1, 2, 5 });
    pixels[0].push_back(Pixel{ 2, 1, 5 });

    pixels[1].push_back(Pixel{ 0, 1, 5 });
    pixels[1].push_back(Pixel{ 1, 0, 5 });
    pixels[1].push_back(Pixel{ 1, 1, 5 });
    pixels[1].push_back(Pixel{ 2, 1, 5 });

    pixels[2].push_back(Pixel{ 1, 0, 5 });
    pixels[2].push_back(Pixel{ 1, 1, 5 });
    pixels[2].push_back(Pixel{ 1, 2, 5 });
    pixels[2].push_back(Pixel{ 0, 1, 5 });

    pixels[3].push_back(Pixel{ 0, 1, 5 });
    pixels[3].push_back(Pixel{ 1, 2, 5 });
    pixels[3].push_back(Pixel{ 1, 1, 5 });
    pixels[3].push_back(Pixel{ 2, 1, 5 });
}