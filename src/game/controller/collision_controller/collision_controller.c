#include "../../../../include/game/controller/collision_controller/collision_controller.h"

static void handle_close_range_collision(Heros *heros, enemy_controller *enemy_controller)
{
    int i;
    for (i = 0; i < enemy_controller->enemy_spawned; i++)
    {
        if (is_hitbox_colliding(heros->hitbox, enemy_controller->enemies[i].hitbox))
        {
            enemy_controller->enemies[i].health = 0;
        }
    }
}

void handle_collision(Heros *heros, enemy_controller *enemy_controller)
{
    handle_close_range_collision(heros, enemy_controller);
}