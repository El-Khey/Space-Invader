#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#include "../../../utils/dimension/dimension.h"
#include "../../../utils/position/position.h"
#include "../../../utils/image/image.h"
#include "../../../utils/animation/animation.h"

#define NUMBER_OF_BACKGROUNDS 2

typedef struct
{
    Position layers_position;

    Animation layer_01_void;
    Animation layer_02_stars;
    Animation layer_03_stars;

} AnimatedBackground;

typedef struct
{
    Dimension dimension;
    Position position;

    AnimatedBackground animated_backgrounds[NUMBER_OF_BACKGROUNDS];
} Window;

Window construct_window(int width, int height);

void update_background_position(Window *window);

#endif