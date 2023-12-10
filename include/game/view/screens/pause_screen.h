#ifndef PAUSE_SCREEN_H
#define PAUSE_SCREEN_H

#include "../../../gui/shape/shape.h"
#include "../../../gui/button/button.h"
#include "../../../utils/text/text.h"

typedef struct
{
    Shape background_filter;

    Button resume_button;
    Button quit_button;
    Button save_and_quit_button;

    Text title;
} PauseScreen;

/**
 * @brief Initialize the pause screen
 *
 * @param pause_screen The pause screen
 */
PauseScreen construct_pause_screen();

/**
 * @brief Draw the pause screen
 *
 * @param pause_screen The pause screen
 * @param mouse_position The mouse position
 */
void draw_pause_screen(PauseScreen pause_screen, Position mouse_position);

/**
 * @brief Free the pause screen
 *
 * @param pause_screen The pause screen
 */
void free_pause_screen(PauseScreen *pause_screen);

#endif