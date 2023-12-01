#include "../../../../include/game/controller/enemy_controller.h"

enemy_controller construct_enemy_controller()
{
    enemy_controller enemy_controller;

    enemy_controller.last_enemy_spawn_time = 0;
    enemy_controller.delay_between_spawn = 2000;

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

void update_enemies(enemy_controller *controller, Heros heros)
{
    int i = 0;
    for (; i < controller->enemy_spawned; i++)
    {
        move_enemy(&controller->enemies[i]);
        draw_enemy(controller->enemies[i]);

        if (get_y(heros.position) > get_y(controller->enemies[i].position) && abs(get_x(controller->enemies[i].position) - get_x(heros.position)) < 10 && controller->enemies[i].list.projectiles_count < MAX_PROJECTILES)
        {
            if (!controller->enemies[i].is_firing)
            {
                controller->enemies[i].list.projectiles[controller->enemies[i].list.projectiles_count] = construct_projectile(controller->enemies[i].position, controller->enemies[i].dimension, controller->enemies[i].list.active_bullet_type);
                controller->enemies[i].list.projectiles[controller->enemies[i].list.projectiles_count].speed = -controller->enemies[i].list.projectiles[controller->enemies[i].list.projectiles_count].speed;
                controller->enemies[i].list.projectiles_count++;

                controller->enemies[i].is_firing = 1;
                controller->enemies[i].enemy_animation.active_state = ATTACK;
                play_animation(&controller->enemies[i].enemy_animation.ship[controller->enemies[i].enemy_animation.active_state]);
            }
        }

        if (is_animation_finished(controller->enemies[i].enemy_animation.ship[controller->enemies[i].enemy_animation.active_state], MLV_get_time()) && controller->enemies[i].is_firing)
        {
            rewind_animation(&controller->enemies[i].enemy_animation.ship[controller->enemies[i].enemy_animation.active_state]);
            stop_animation(&controller->enemies[i].enemy_animation.ship[controller->enemies[i].enemy_animation.active_state]);

            controller->enemies[i].is_firing = 0;
            controller->enemies[i].enemy_animation.active_state = BASE;
        }

        update_projectiles(&controller->enemies[i].list);

        /** TODO: si collision entre deux vaisseau explosion */
        if (is_enemy_out_of_screen(controller->enemies[i]))
        {
            controller->enemy_spawned--;
            controller->enemies[i] = controller->enemies[controller->enemy_spawned];

            /** TODO: enelver une vie au joeur quand un enemy traverse l'ecran */
        }
    }
}