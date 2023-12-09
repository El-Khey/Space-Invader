#ifndef SETTINGS_BAR_VIEW_H_
#define SETTINGS_BAR_VIEW_H_

#include "../../gui/button/button.h"
#include "../../gui/shape/shape.h"
#include "../../utils/text/text.h"

typedef struct
{
    Position position;
    Dimension dimension;

    Text time_text;
} ClockContainer;

typedef struct
{
    Dimension dimension;
    Position position;

    Button music_button;
    Button mute_button;

    Button pause_button;
    Button resume_button;
} settings_bar_content;

typedef struct
{
    ClockContainer clock_container;
    settings_bar_content content;

    int is_music_on;
    int is_paused;
} settings_bar_view;

/**
 * @brief Construct the settings bar view
 *
 * @param settings_bar_view The settings bar view
 */
settings_bar_view construct_settings_bar_view();

/**
 * @brief Set the music button state
 *
 * @param settings_bar_view The settings bar view
 */
void set_music_button_state(settings_bar_view *settings_bar_view);

/**
 * @brief Draw the settings bar view
 *
 * @param settings_bar_view The settings bar view
 */
void draw_settings_bar_view(settings_bar_view *settings_bar_view, int elapsed_time);

#endif