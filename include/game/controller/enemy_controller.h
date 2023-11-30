#ifndef ENEMY_CONTROLLER_H
#define ENEMY_CONTROLLER_H

#include "../manager/event_manager/event_manager.h"
#include "../model/enemy.h"
#include "../../utils/utils.h"

void handle_enemy_spawn(Enemys *enemys, int interval_seconds);
void handle_enemy(Enemys *enemys);
void update_enemy_positions(Enemys *enemys);

#endif