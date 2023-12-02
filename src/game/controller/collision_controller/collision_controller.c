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

static void handle_heros_projectiles_collision(Projectiles *list, enemy_controller *enemy_controller)
{
    int i, j, k;

    for (i = 0; i < list->projectiles_count; i++)
    {
        for (j = 0; j < enemy_controller->enemy_spawned; j++)
        {
            for (k = 0; k < list->projectiles[i].list.bullets_count; k++)
            {
                if (is_hitbox_colliding(list->projectiles[i].list.bullets[k].hitbox, enemy_controller->enemies[j].hitbox))
                {
                    enemy_controller->enemies[j].health -= list->projectiles[i].damage;

                    list->projectiles[i].list.bullets[k] = list->projectiles[i].list.bullets[list->projectiles[i].list.bullets_count - 1];
                    list->projectiles[i].list.bullets_count--;
                }
            }
        }
    }
}

void handle_collision(Heros *heros, enemy_controller *enemy_controller)
{
    handle_close_range_collision(heros, enemy_controller);
    handle_heros_projectiles_collision(&heros->list, enemy_controller);
}