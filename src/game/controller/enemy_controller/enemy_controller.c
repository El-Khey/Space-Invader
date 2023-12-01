#include "../../../../include/game/controller/enemy_controller.h"

enemy_controller construct_enemy_controller()
{
    enemy_controller enemy_controller;

    enemy_controller.last_enemy_spawn_time = 0;
    enemy_controller.delay_between_spawn = 1000;

    enemy_controller.enemy_spawned = 0;
    enemy_controller.enemy_spawn_count = MAX_ENEMY_SPAWN_COUNT;

    return enemy_controller;
}

void generate_enemies(enemy_controller *controller)
{
    if (controller->last_enemy_spawn_time + controller->delay_between_spawn < MLV_get_time() && controller->enemy_spawned < controller->enemy_spawn_count)
    {
        controller->last_enemy_spawn_time = MLV_get_time();
        controller->enemies[controller->enemy_spawned] = construct_enemy(rand() % nb_enemy_class);
        controller->enemy_spawned++;
    }
}

static int is_enemy_out_of_screen(Enemy enemy)
{
    return get_y(enemy.position) > WINDOW_HEIGHT + get_height(enemy.dimension);
}

void update_enemies(enemy_controller *controller)
{
    int i = 0;
    for (; i < controller->enemy_spawned; i++)
    {
        move_enemy(&controller->enemies[i]);
        draw_enemy(controller->enemies[i]);

        /** TODO: si collision entre deux vaisseau explosion */
        if (is_enemy_out_of_screen(controller->enemies[i]))
        {
            controller->enemy_spawned--;
            controller->enemies[i] = controller->enemies[controller->enemy_spawned];

            /** TODO: enelver une vie au joeur quand un enemy traverse l'ecran */
        }
    }
}