#ifndef COLLISION_CONTROLLER_H
#define COLLISION_CONTROLLER_H

#include "../enemy_controller.h"
#include "../../controller/asteroid_controller/asteroid_controller.h"
#include "../../controller/players_controller.h"

void handle_heros_and_enemy_collision(Players *players, enemy_controller *enemy_controller);

void handle_asteroid_and_heros_collision(Players *players, asteroid_controller *asteroid_controller);

#endif
