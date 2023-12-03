#ifndef HEROS_CONTROLLER_H
#define HEROS_CONTROLLER_H

#include "../manager/event_manager/event_manager.h"
#include "./projectile_controller/projectile_controller.h"

#include "../model/heros.h"
#include "../../utils/utils.h"

void update_heros(Heros *heros, EventManager event_manager);

void move_heros_up(Heros *heros);

void move_heros_down(Heros *heros);

void move_heros_left(Heros *heros);

void move_heros_right(Heros *heros);

#endif