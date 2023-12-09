#ifndef GAME_OVER_SCREEN_H
#define GAME_OVER_SCREEN_H

#include "../../../gui/shape/shape.h"
#include "../../../gui/button/button.h"
#include "../../../utils/text/text.h"

typedef struct
{
    Shape background_filter;

    Button restart_button;
    Button back_to_menu_button;

    Text title;
} GameOverScreen;

/**
 * @brief Construct a new Game Over Screen object
 *
 * @param game_over_screen The game over screen
 */
GameOverScreen construct_game_over_screen();

/**
 * @brief Draw the game over screen
 *
 * @param game_over_screen The game over screen
 * @param mouse_position The mouse position
 */
void draw_game_over_screen(GameOverScreen game_over_screen, Position mouse_position);

/**
 * @brief
 *
 * @param game_over_screen
 */
void free_game_over_screen(GameOverScreen *game_over_screen);

#endif