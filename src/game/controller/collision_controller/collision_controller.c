#include "../../../../include/game/controller/collision_controller/collision_controller.h"

static void handle_close_range_collision(Heros *heros, enemy_controller *enemy_controller)
{
    int i;
    for (i = 0; i < enemy_controller->enemy_spawned; i++)
    {
        if (is_hitbox_colliding(heros->hitbox, enemy_controller->enemies[i].hitbox))
        {
            if (enemy_controller->enemies[i].health <= 0)
            {
                continue;
            }

            enemy_controller->enemies[i].health = 0;
            heros->health -= enemy_controller->enemies[i].damage;
            update_heros_active_ship(heros);
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

static void handle_enemy_projectiles_collision(enemy_controller *enemy_controller, Heros *heros)
{
    int i, j, k;

    for (i = 0; i < enemy_controller->enemy_spawned; i++)
    {
        for (j = 0; j < enemy_controller->enemies[i].list.projectiles_count; j++)
        {
            for (k = 0; k < enemy_controller->enemies[i].list.projectiles[j].list.bullets_count; k++)
            {
                if (is_hitbox_colliding(enemy_controller->enemies[i].list.projectiles[j].list.bullets[k].hitbox, heros->hitbox))
                {
                    heros->health -= enemy_controller->enemies[i].list.projectiles[j].damage;

                    enemy_controller->enemies[i].list.projectiles[j].list.bullets[k] = enemy_controller->enemies[i].list.projectiles[j].list.bullets[enemy_controller->enemies[i].list.projectiles[j].list.bullets_count - 1];
                    enemy_controller->enemies[i].list.projectiles[j].list.bullets_count--;

                    update_heros_active_ship(heros);
                }
            }
        }
    }
}

void handle_collision(Heros *heros, enemy_controller *enemy_controller)
{
    handle_close_range_collision(heros, enemy_controller);
    handle_heros_projectiles_collision(&heros->list, enemy_controller);
    handle_enemy_projectiles_collision(enemy_controller, heros);
}