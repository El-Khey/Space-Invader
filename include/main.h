#ifndef MAIN_H
#define MAIN_H

#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <MLV/MLV_all.h>

#define WINDOW_WIDTH 1400
#define WINDOW_HEIGHT 800

#define MAX_PLAYER_LIFE 7
#define MAX_PLAYERS 2

#define PRIMARY_GRAY_COLOR MLV_rgba(75, 75, 75, 255)
#define PRIMARY_RED_COLOR MLV_rgba(255, 41, 41, 255)
#define PRIMARY_BLUE_COLOR MLV_rgba(50, 89, 255, 255)

#endif