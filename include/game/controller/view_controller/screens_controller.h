#ifndef SCREENS_CONTROLLER_H_
#define SCREENS_CONTROLLER_H_

#include "../../manager/game_manager/game_manager.h"
#include "../../manager/event_manager/event_manager.h"
#include "../../manager/game_manager/backup_manager.h"

/**
 * @brief Handle the events of the pause screen
 * The BackupManager is used to save the game when the player click on the save and quit button,
 * the backup manager has the slot id of the save file that is why it is passed as a parameter
 *
 * @param game_manager The game manager
 * @param pause_screen The pause screen
 * @param mouse_manager The mouse manager
 * @param backup_manager The backup manager
 */
void handle_pause_screen_events(GameManager *game_manager, PauseScreen pause_screen, MouseManager mouse_manager, BackupManager backup_manager);

/**
 * @brief Handle the events of the game over screen
 *
 * @param game_manager The game manager
 * @param game_over_screen The game over screen
 * @param mouse_manager The mouse manager
 * @param menu_time The menu time
 */

void handle_game_over_screen_events(GameManager *game_manager, BackupManager backup_manager, GameOverScreen game_over_screen, MouseManager mouse_manager, int *menu_time);
#endif