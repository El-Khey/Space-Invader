#ifndef PLAYER_H
#define PLAYER_H

#include "../manager/event_manager/event_manager.h"
#include "../model/objet/creature/heros/heros.h"

void handle_player_movement(Heros *heros, EventManager *event_manager);

#endif