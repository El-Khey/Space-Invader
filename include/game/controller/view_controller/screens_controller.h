#ifndef SCREENS_CONTROLLER_H_
#define SCREENS_CONTROLLER_H_

#include "../../manager/game_manager/game_manager.h"
#include "../../manager/event_manager/event_manager.h"

/**
 * @brief Handle the events of the pause screen
 *
 * @param game_manager The game manager
 * @param pause_screen The pause screen
 * @param mouse_manager The mouse manager
 */
void handle_pause_screen_events(GameManager *game_manager, PauseScreen pause_screen, MouseManager mouse_manager);

/**
 * @brief Handle the events of the game over screen
 *
 * @param game_manager The game manager
 * @param game_over_screen The game over screen
 * @param mouse_manager The mouse manager
 */
void handle_game_over_screen_events(GameManager *game_manager, GameOverScreen game_over_screen, MouseManager mouse_manager);

#endif