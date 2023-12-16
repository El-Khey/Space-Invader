#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "../../../main.h"

/** Controllers */
#include "../../controller/collision_controller/collision_controller.h"
#include "../../controller/asteroid_controller/asteroid_controller.h"
#include "../../controller/bonus_controller/bonus_controller.h"
#include "../../controller/enemy_controller.h"

/** Models */
#include "../../model/window/window.h"
#include "../../model/player.h"

/** Views */
#include "../../view/settings_bar_view.h"
#include "../../view/screens/pause_screen.h"
#include "../../view/screens/game_over_screen.h"
#include "./game_details.h"

/**
 * @brief Structure représentant les contrôleurs du jeu.
 */
typedef struct
{
    enemy_controller enemy_controller;       /**< Contrôleur des ennemis */
    asteroid_controller asteroid_controller; /**< Contrôleur des astéroïdes */
    bonus_controller bonus_controller;       /**< Contrôleur des bonus */
} Controllers;

/**
 * @brief Structure contenant les différentes vues du jeu.
 */
typedef struct
{
    settings_bar_view settings_bar_view; /**< Vue de la barre de réglages. */
    PauseScreen pause_screen;            /**< Vue de l'écran de pause. */
    GameOverScreen game_over_screen;     /**< Vue de l'écran de fin de partie. */
} Views;

/**
 * @brief Structure représentant le gestionnaire de jeu.
 */
typedef struct
{
    Controllers controllers; /**< Les contrôleurs du jeu. */
    Views views;             /**< Les vues du jeu. */

    Window window;   /**< La fenêtre du jeu. */
    Players players; /**< Les joueurs du jeu. */

    int is_game_over;   /**< Indique si le jeu est terminé. */
    int is_game_paused; /**< Indique si le jeu est en pause. */
    int quit_game;      /**< Indique si le jeu doit être quitté. */

    GameMode game_mode;             /**< Le mode de jeu. */
    GameDifficulty game_difficulty; /**< La difficulté du jeu. */
} GameManager;

/**
 * @brief Construit un nouvel objet Game Manager
 * Le gestionnaire de jeu est une structure qui contient tous les contrôleurs et modèles du jeu.
 * Il met à jour l'état du jeu et dessine le jeu.
 *
 * @param players Les joueurs
 * @param game_mode Le mode de jeu
 * @param game_difficulty La difficulté du jeu
 *
 * @return GameManager
 */
GameManager construct_game_manager(Players players, GameMode game_mode, GameDifficulty game_difficulty);

/**
 * @brief Met à jour l'état du jeu
 * Cette fonction est responsable de la mise à jour de l'état du jeu, y compris le joueur, les ennemis, les projectiles, etc.
 *
 * @param game_manager Le gestionnaire de jeu
 */
void update_game(GameManager *game_manager, EventManager *event_manager, int time_on_menu);

/**
 * @brief Redémarre le jeu
 *
 * @param game_manager Le gestionnaire de jeu
 */
void restart_game(GameManager *game_manager);

/**
 * @brief Met en pause le jeu
 *
 * @param game_manager Le gestionnaire de jeu
 */
void pause_game(GameManager *game_manager);

/**
 * @brief Reprendre le jeu
 *
 * @param game_manager Le gestionnaire de jeu
 */
void resume_game(GameManager *game_manager);

/**
 * @brief Vérifie si le jeu est en pause
 *
 * @param game_manager Le gestionnaire de jeu
 * @return int
 */
int is_game_paused(GameManager *game_manager);

/**
 * @brief Quitter le jeu
 *
 * @param game_manager Le gestionnaire de jeu
 */
void quit_game(GameManager *game_manager);

/**
 * @brief Vérifie si le jeu est terminé
 *
 * @param game_manager Le gestionnaire de jeu
 * @return int
 */
int is_game_over(GameManager *game_manager);

#endif
