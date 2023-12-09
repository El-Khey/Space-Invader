#ifndef PLAYERS_CONTROLLER_H
#define PLAYERS_CONTROLLER_H

#include "../manager/game_manager/game_manager.h"
#include "../manager/event_manager/event_manager.h"
#include "./heros_controller.h"
#include "../../utils/utils.h"
#include "../model/player.h"

void update_players(GameManager *game_manager, EventManager event_manager);

#endif