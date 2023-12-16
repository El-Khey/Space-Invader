#ifndef FRAME_RATE_H
#define FRAME_RATE_H

#include "../../main.h"

typedef struct
{
    int fps;
    int delay;

    struct timespec start_time;
    struct timespec end_time;
} FrameRate;

FrameRate construct_frame_rate(int fps);

void set_frame_rate(FrameRate *frame_rate, int fps);

void set_frame_rate_start_time(FrameRate *frame_rate);

void delay_according_to_frame_rate(FrameRate *frame_rate);

#endif