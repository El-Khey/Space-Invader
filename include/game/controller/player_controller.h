#ifndef PLAYER_H
#define PLAYER_H

#include "../manager/event_manager/event_manager.h"
#include "../model/heros.h"
#include "../../utils/utils.h"

void handle_heros_movement(Heros *heros, EventManager event_manager);

void handle_heros_projectiles(Heros *heros, EventManager event_manager);

#endif