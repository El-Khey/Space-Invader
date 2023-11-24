#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#include "../../../utils/dimension/dimension.h"
#include "../../../utils/position/position.h"
#include "../../../utils/image/image.h"

typedef struct
{
    Dimension dimension;
    Position position;

    Image background;
    Image next_background;
} Window;

Window construct_window(int width, int height);

void update_background_position(Window *window);

#endif