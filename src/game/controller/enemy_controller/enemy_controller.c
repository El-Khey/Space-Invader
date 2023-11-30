#include "../../../../include/game/controller/enemy_controller.h"

static int last_generated_time = 0;

void handle_enemy_spawn(Enemys *enemys, int interval_seconds)
{
    int current_time = MLV_get_time();

    if (current_time - last_generated_time >= interval_seconds * 1000)
    {
        handle_enemy(enemys);
        last_generated_time = current_time;
    }
}
