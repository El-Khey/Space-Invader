#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "../../controller/collision_controller/collision_controller.h"
#include "../../controller/asteroid_controller/asteroid_controller.h"
#include "../../controller/bonus_controller/bonus_controller.h"
#include "../../controller/enemy_controller.h"

#include "../../model/window/window.h"
#include "../../model/player.h"

#include "../../view/settings_bar_view.h"

typedef struct
{
    enemy_controller enemy_controller;
    asteroid_controller asteroid_controller;
    bonus_controller bonus_controller;
} Controllers;

typedef struct
{
    Controllers controllers;
    settings_bar_view settings_bar_view;

    Window window;
    Players players;

    int is_game_over;
    int is_game_paused;
    int quit_game;
} GameManager;

/**
 * @brief Construct a new Game Manager object
 * The game manager is a structure that contains all the controllers and models of the game.
 * It update the game state and draw the game.
 *
 * @return GameManager
 */
GameManager construct_game_manager();

/**
 * @brief Update the game state
 * This function is responsible for updating the game state, including the player, the enemies, the projectiles, etc.
 *
 * @param game_manager The game manager
 */
void update_game(GameManager *game_manager, EventManager *event_manager);

/**
 * @brief Restart the game
 *
 * @param game_manager The game manager
 */
void restart_game(GameManager *game_manager);

/**
 * @brief Pause the game
 *
 * @param game_manager The game manager
 */
void pause_game(GameManager *game_manager);

/**
 * @brief Resume the game
 *
 * @param game_manager The game manager
 */
void resume_game(GameManager *game_manager);

/**
 * @brief Check if the game is paused
 *
 * @param game_manager The game manager
 * @return int
 */
int is_game_paused(GameManager *game_manager);

/**
 * @brief Quit the game
 *
 * @param game_manager The game manager
 */
void quit_game(GameManager *game_manager);

/**
 * @brief Check if the game is over
 *
 * @param game_manager The game manager
 * @return int
 */
int is_game_over(GameManager *game_manager);

#endif
