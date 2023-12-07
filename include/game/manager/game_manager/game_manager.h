#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "../../controller/collision_controller/collision_controller.h"
#include "../../controller/asteroid_controller/asteroid_controller.h"
#include "../../controller/bonus_controller/bonus_controller.h"
#include "../../controller/players_controller.h"
#include "../../controller/enemy_controller.h"

#include "../../model/player.h"
#include "../../model/window/window.h"

typedef struct
{
    enemy_controller enemy_controller;
    asteroid_controller asteroid_controller;
    bonus_controller bonus_controller;
} Controllers;

typedef struct
{
    Controllers controllers;

    Window window;
    Players players;
} GameManager;

/**
 * @brief Construct a new Game Manager object
 * The game manager is a structure that contains all the controllers and models of the game.
 * It update the game state and draw the game.
 *
 * @return GameManager
 */
GameManager construct_game_manager();

void update_game(GameManager *game_manager, EventManager *event_manager);

#endif
