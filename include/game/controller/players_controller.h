#ifndef PLAYERS_CONTROLLER_H
#define PLAYERS_CONTROLLER_H

#include "../manager/event_manager/event_manager.h"
#include "../model/player.h"
#include "./heros_controller.h"
#include "../../utils/utils.h"

void update_players(Players *players, EventManager event_manager);

#endif