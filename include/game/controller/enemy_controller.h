#ifndef ENEMY_CONTROLLER_H
#define ENEMY_CONTROLLER_H

#include "./projectile_controller/projectile_controller.h"
#include "../manager/event_manager/event_manager.h"
#include "../model/enemy/enemy.h"
#include "../../utils/utils.h"
#include "../model/player.h"

#define MAX_ENEMY_SPAWN_COUNT 15

typedef struct
{
    Enemy enemies[MAX_ENEMY_SPAWN_COUNT];

    int enemy_spawn_count; /** The number of enemy to spawn */
    int enemy_spawned;     /** The number of enemy spawned */

    int last_enemy_spawn_time; /** The last time a enemy was spawned */
    int delay_between_spawn;   /** The delay between each enemy spawn */
} enemy_controller;

enemy_controller construct_enemy_controller();

void generate_enemies(enemy_controller *controller);

void update_enemies(enemy_controller *controller, Players *players);

#endif