#ifndef ASTEROID_CONTROLLER_H
#define ASTEROID_CONTROLLER_H

#include "../../manager/event_manager/event_manager.h"
#include "../projectile_controller/projectile_controller.h"
#include "../../model/asteroid/asteroid.h"
#include "../../model/heros.h"
#include "../../../utils/utils.h"

#define MAX_ASTEROID_SPAWN_COUNT 400

typedef struct
{
    Asteroid asteroids[MAX_ASTEROID_SPAWN_COUNT];

    int asteroid_spawn_count; /** The number of asteroid to spawn */
    int asteroid_spawned;     /** The number of asteroid spawned */

    int last_asteroid_spawn_time; /** The last time a asteroid was spawned */
    int delay_between_spawn;      /** The delay between each asteroid spawn */
} asteroid_controller;

asteroid_controller construct_asteroid_controller();

void generate_asteroids(asteroid_controller *controller);

void update_asteroids(asteroid_controller *controller);

#endif