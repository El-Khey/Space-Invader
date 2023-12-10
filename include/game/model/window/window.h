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

    int elapsed_time;

    int start_pause_time;
    int end_pause_time;
    int total_pause_time;
} Window;

Window construct_window();

void update_background_position(Window *window);

/**
 * @brief Load the window backup
 * This function is used to load the window animation when the game is started from a backup.
 *
 * @param window The window
 */
void load_window_backup(Window *window);

#endif