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

typedef struct
{
    enemy_controller enemy_controller;
    asteroid_controller asteroid_controller;
    bonus_controller bonus_controller;
} Controllers;

typedef struct
{
    settings_bar_view settings_bar_view;
    PauseScreen pause_screen;
    GameOverScreen game_over_screen;
} Views;

typedef struct
{
    Controllers controllers;
    Views views;

    Window window;
    Players players;

    int is_game_over;
    int is_game_paused;
    int quit_game;

    GameMode game_mode;
    GameDifficulty game_difficulty;
} GameManager;

/**
 * @brief Construct a new Game Manager object
 * The game manager is a structure that contains all the controllers and models of the game.
 * It update the game state and draw the game.
 *
 * @param players The players
 * @param game_mode The game mode
 * @param game_difficulty The game difficulty
 *
 * @return GameManager
 */
GameManager construct_game_manager(Players players, GameMode game_mode, GameDifficulty game_difficulty);

/**
 * @brief Update the game state
 * This function is responsible for updating the game state, including the player, the enemies, the projectiles, etc.
 *
 * @param game_manager The game manager
 */
void update_game(GameManager *game_manager, EventManager *event_manager, int time_on_menu);

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
