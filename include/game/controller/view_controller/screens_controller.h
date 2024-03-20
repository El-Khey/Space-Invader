#ifndef SCREENS_CONTROLLER_H_
#define SCREENS_CONTROLLER_H_

#include "../../manager/game_manager/game_manager.h"
#include "../../manager/event_manager/event_manager.h"
#include "../../manager/game_manager/backup_manager.h"

/**
 * @brief Gère les événements de l'écran de pause.
 * Le BackupManager est utilisé pour sauvegarder la partie lorsque le joueur clique sur le bouton "sauvegarder et quitter",
 * le gestionnaire de sauvegarde a l'identifiant de l'emplacement de sauvegarde du fichier, c'est pourquoi il est passé en paramètre.
 *
 * @param game_manager Le gestionnaire de jeu
 * @param pause_screen L'écran de pause
 * @param mouse_manager Le gestionnaire de souris
 * @param backup_manager Le gestionnaire de sauvegarde
 */
void handle_pause_screen_events(GameManager *game_manager, PauseScreen pause_screen, MouseManager mouse_manager, BackupManager backup_manager);

/**
 * @brief Gère les événements de l'écran de fin de partie.
 *
 * @param game_manager Le gestionnaire de jeu
 * @param backup_manager Le gestionnaire de sauvegarde
 * @param game_over_screen L'écran de fin de partie
 * @param mouse_manager Le gestionnaire de souris
 * @param menu_time Le temps du menu
 */
void handle_game_over_screen_events(GameManager *game_manager, BackupManager backup_manager, GameOverScreen game_over_screen, MouseManager mouse_manager, int *menu_time);

#endif