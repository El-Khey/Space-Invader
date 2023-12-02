#ifndef COLLISION_CONTROLLER_H
#define COLLISION_CONTROLLER_H

#include "../enemy_controller.h"
#include "../../model/heros.h"
#include "../../controller/asteroid_controller/asteroid_controller.h"

void handle_heros_and_enemy_collision(Heros *heros, enemy_controller *enemy_controller);

void handle_asteroid_and_heros_collision(Heros *heros, asteroid_controller *asteroid_controller);

#endif
