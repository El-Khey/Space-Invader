#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#include "../utils/dimension/dimension.h"
#include "../utils/position/position.h"

typedef struct
{
    Dimension dimension;
    Position position;
    MLV_Image *background;
    MLV_Image *next_background;
} Window;

Window construct_window(int width, int height);
void draw_window_background(Window window);

#endif