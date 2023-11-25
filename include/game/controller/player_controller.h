#ifndef PLAYER_H
#define PLAYER_H

#include "../manager/event_manager/event_manager.h"
#include "../model/heros.h"

void handle_heros_movement(Heros *heros, EventManager *event_manager);

#endif