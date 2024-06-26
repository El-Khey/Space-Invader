#include "../../../../include/game/model/window/window.h"

static AnimatedBackground construct_animated_background();

Window construct_window()
{
    Window window;

    window.elapsed_time = 0;

    window.start_pause_time = 0;
    window.end_pause_time = 0;
    window.total_pause_time = 0;

    window.start_game_over_time = 0;
    window.end_game_over_time = 0;
    window.total_game_over_time = 0;

    window.dimension.height = WINDOW_HEIGHT;
    window.dimension.width = WINDOW_WIDTH;

    window.position.x = 0;
    window.position.y = 0;

    window.animated_backgrounds[0] = construct_animated_background();
    window.animated_backgrounds[0].layers_position = construct_position(0, 0);

    window.animated_backgrounds[1] = construct_animated_background();
    window.animated_backgrounds[1].layers_position = construct_position(0, -WINDOW_HEIGHT);

    return window;
}

void load_window_backup(Window *window)
{
    window->animated_backgrounds[0] = construct_animated_background();
    window->animated_backgrounds[0].layers_position = construct_position(0, 0);

    window->animated_backgrounds[1] = construct_animated_background();
    window->animated_backgrounds[1].layers_position = construct_position(0, -WINDOW_HEIGHT);
}

static AnimatedBackground construct_animated_background()
{
    AnimatedBackground animated_background;

    animated_background.layer_01_void = construct_animation("assets/sprites/Environment/Backgrounds/Condensed/Starry background  - Layer 01 - Void.png", 9, construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT), FORWARD);
    animated_background.layer_02_stars = construct_animation("assets/sprites/Environment/Backgrounds/Condensed/Starry background  - Layer 02 - Stars.png", 9, construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT), FORWARD);
    animated_background.layer_03_stars = construct_animation("assets/sprites/Environment/Backgrounds/Condensed/Starry background  - Layer 03 - Stars.png", 9, construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT), FORWARD);

    animated_background.layers_position = construct_position(0, 0);

    play_animation(&animated_background.layer_01_void);
    play_animation(&animated_background.layer_02_stars);
    play_animation(&animated_background.layer_03_stars);

    return animated_background;
}

void update_background_position(Window *window)
{
    static int background_iteration = 0;

    move_position(&window->animated_backgrounds[0].layers_position, 0, 1);
    move_position(&window->animated_backgrounds[1].layers_position, 0, 1);

    if (get_y(window->animated_backgrounds[0].layers_position) >= WINDOW_HEIGHT)
    {
        window->animated_backgrounds[0].layers_position = construct_position(0, -WINDOW_HEIGHT);
        background_iteration++;
    }
    else if (get_y(window->animated_backgrounds[1].layers_position) >= WINDOW_HEIGHT)
    {
        window->animated_backgrounds[1].layers_position = construct_position(0, get_y(window->animated_backgrounds[0].layers_position) - WINDOW_HEIGHT);
    }

    draw_animation(window->animated_backgrounds[0].layer_01_void, window->animated_backgrounds[0].layers_position);
    draw_animation(window->animated_backgrounds[1].layer_01_void, window->animated_backgrounds[1].layers_position);

    draw_animation(window->animated_backgrounds[1].layer_02_stars, window->animated_backgrounds[1].layers_position);
    draw_animation(window->animated_backgrounds[0].layer_02_stars, window->animated_backgrounds[0].layers_position);

    if (background_iteration % 2)
    {
        draw_animation(window->animated_backgrounds[0].layer_03_stars, window->animated_backgrounds[0].layers_position);
    }
}

void free_window(Window *window)
{
    int i;
    for (i = 0; i < NUMBER_OF_BACKGROUNDS; i++)
    {
        free_animation(&window->animated_backgrounds[i].layer_01_void);
        free_animation(&window->animated_backgrounds[i].layer_02_stars);
        free_animation(&window->animated_backgrounds[i].layer_03_stars);
    }
}