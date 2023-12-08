#include "../../../include/game/view/settings_bar_view.h"

#define SETTINGS_BAR_VIEW_WIDTH 300
#define SETTINGS_BAR_VIEW_HEIGHT 45

#define CLOCK_CONTAINER_WIDTH 220
#define CLOCK_CONTAINER_HEIGHT 75

#define BUTTON_WIDTH 20
#define BUTTON_HEIGHT 20

#define BUTTON_PADDING 22
#define NB_BUTTONS 3

settings_bar_view construct_settings_bar_view()
{
    settings_bar_view settings_bar_view;
    Dimension button_dimension;

    int center_x, center_y;
    char time_string[10];

    settings_bar_view.content.dimension = construct_dimension(SETTINGS_BAR_VIEW_WIDTH, SETTINGS_BAR_VIEW_HEIGHT);
    settings_bar_view.clock_container.dimension = construct_dimension(CLOCK_CONTAINER_WIDTH, CLOCK_CONTAINER_HEIGHT);

    /** Calculate the center positions */
    center_x = (get_width(settings_bar_view.content.dimension) - (NB_BUTTONS * (BUTTON_WIDTH + BUTTON_PADDING) - BUTTON_PADDING)) / 2;
    center_y = (get_height(settings_bar_view.content.dimension) - BUTTON_HEIGHT) / 2;

    settings_bar_view.content.position = construct_position(WINDOW_WIDTH / 2 - SETTINGS_BAR_VIEW_WIDTH / 2, get_height(settings_bar_view.clock_container.dimension) + 7 + 25);
    settings_bar_view.clock_container.position = construct_position(WINDOW_WIDTH / 2 - CLOCK_CONTAINER_WIDTH / 2, 25);
    button_dimension = construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT);

    settings_bar_view.content.resume_button = construct_button_with_image(
        load_image("assets/images/icons/play.png", button_dimension),
        construct_position(get_x(settings_bar_view.content.position) + center_x, get_y(settings_bar_view.content.position) + center_y),
        button_dimension);

    center_x += BUTTON_WIDTH + BUTTON_PADDING;
    settings_bar_view.content.pause_button = construct_button_with_image(
        load_image("assets/images/icons/pause.png", button_dimension),
        construct_position(get_x(settings_bar_view.content.position) + center_x, get_y(settings_bar_view.content.position) + center_y),
        button_dimension);

    center_x += BUTTON_WIDTH + BUTTON_PADDING;
    settings_bar_view.content.music_button = construct_button_with_image(
        load_image("assets/images/icons/sound-on.png", button_dimension),
        construct_position(get_x(settings_bar_view.content.position) + center_x, get_y(settings_bar_view.content.position) + center_y),
        button_dimension);

    settings_bar_view.content.mute_button = construct_button_with_image(
        load_image("assets/images/icons/sound-off.png", button_dimension),
        construct_position(get_x(settings_bar_view.content.position) + center_x, get_y(settings_bar_view.content.position) + center_y),
        button_dimension);

    settings_bar_view.is_music_on = 1;
    settings_bar_view.is_paused = 0;

    format_milliseconds(time_string, MLV_get_time());
    settings_bar_view.clock_container.time_text = construct_text(time_string, construct_position(0, 0), "assets/fonts/Play-Bold.ttf", 42, MLV_COLOR_BLACK);
    set_text_position(&settings_bar_view.clock_container.time_text, construct_position(get_x(settings_bar_view.clock_container.position) + (get_width(settings_bar_view.clock_container.dimension) - get_text_width(settings_bar_view.clock_container.time_text)) / 2, get_y(settings_bar_view.clock_container.position) + (get_height(settings_bar_view.clock_container.dimension) - get_text_height(settings_bar_view.clock_container.time_text)) / 2));

    return settings_bar_view;
}

void set_music_button_state(settings_bar_view *settings_bar_view)
{
    settings_bar_view->is_music_on = !settings_bar_view->is_music_on;
}

void draw_settings_bar_view(settings_bar_view *settings_bar_view, int elapsed_time)
{
    /** Clock container background */
    draw_rounded_filled_rectangle(settings_bar_view->clock_container.position, settings_bar_view->clock_container.dimension, 5, MLV_COLOR_WHITE);

    /** Update the clock and draw it */
    format_milliseconds(settings_bar_view->clock_container.time_text.text, elapsed_time);
    draw_text(settings_bar_view->clock_container.time_text);

    /** Settings bar background */
    draw_rounded_filled_rectangle(settings_bar_view->content.position, settings_bar_view->content.dimension, 22, MLV_COLOR_WHITE);

    draw_button_image(settings_bar_view->content.pause_button);
    draw_button_image(settings_bar_view->content.resume_button);

    (settings_bar_view->is_music_on) ? draw_button_image(settings_bar_view->content.music_button) : draw_button_image(settings_bar_view->content.mute_button);
}
