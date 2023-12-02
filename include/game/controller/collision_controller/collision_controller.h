#ifndef COLLISION_CONTROLLER_H
#define COLLISION_CONTROLLER_H

#include "../../controller/asteroid_controller/asteroid_controller.h"
#include "../../controller/bonus_controller/bonus_controller.h"
#include "../../controller/players_controller.h"
#include "../enemy_controller.h"

void handle_heros_collision(Players *players, enemy_controller *enemy_controller, bonus_controller *bonus_controller, asteroid_controller *asteroid_controller);

#endif
