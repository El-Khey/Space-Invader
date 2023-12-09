#ifndef BONUS_CONTROLLER_H
#define BONUS_CONTROLLER_H

#include "../../manager/event_manager/event_manager.h"
#include "../projectile_controller/projectile_controller.h"
#include "../../model/bonus/bonus.h"
#include "../../../utils/utils.h"
#include "../../model/heros.h"

#define MAX_BONUS_SPAWN_COUNT 2

typedef struct
{
    Bonus bonus[MAX_BONUS_SPAWN_COUNT];

    int bonus_spawn_count; /** The number of bonus to spawn */
    int bonus_spawned;     /** The number of bonus spawned */

    int last_bonus_spawn_time; /** The last time a bonus was spawned */
    int delay_between_spawn;   /** The delay between each bonus spawn */
} bonus_controller;

bonus_controller construct_bonus_controller();

void generate_bonus(bonus_controller *controller);

void update_bonus(bonus_controller *controller);

#endif