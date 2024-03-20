#include "../../../include/utils/frame_rate/frame_rate.h"

FrameRate construct_frame_rate(int fps)
{
    FrameRate frame_rate;

    frame_rate.fps = fps;
    frame_rate.delay = 1000 / fps;

    return frame_rate;
}

void set_frame_rate(FrameRate *frame_rate, int fps)
{
    frame_rate->fps = fps;
    frame_rate->delay = 1000 / fps;
}

void set_frame_rate_start_time(FrameRate *frame_rate)
{
    clock_gettime(CLOCK_REALTIME, &frame_rate->start_time);
}

static void set_frame_rate_end_time(FrameRate *frame_rate)
{
    clock_gettime(CLOCK_REALTIME, &frame_rate->end_time);
}

void delay_according_to_frame_rate(FrameRate *frame_rate)
{
    struct timespec time_elapsed;
    int time_elapsed_ms;

    set_frame_rate_end_time(frame_rate);

    time_elapsed.tv_sec = frame_rate->end_time.tv_sec - frame_rate->start_time.tv_sec;
    time_elapsed.tv_nsec = frame_rate->end_time.tv_nsec - frame_rate->start_time.tv_nsec;

    time_elapsed_ms = time_elapsed.tv_sec * 1000 + time_elapsed.tv_nsec / 1000000;

    if (time_elapsed_ms < frame_rate->delay)
    {
        struct timespec time_to_sleep;
        time_to_sleep.tv_sec = 0;
        time_to_sleep.tv_nsec = (frame_rate->delay - time_elapsed_ms) * 1000000;

        nanosleep(&time_to_sleep, NULL);
    }

    set_frame_rate_start_time(frame_rate);
}