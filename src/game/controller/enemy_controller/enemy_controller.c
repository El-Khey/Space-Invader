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

/**
 * x0 = position of the enemy ship
 * x1 = position of the player's ship
 * w0 = width of the enemy ship
 * w1 = width of the player's ship
 *
 * x0 < (x1 + w1) / 2 < x0 + w0
 *
 * We check that the center of the player's ship is between the left and right edges of the enemy ship
 * and that the player's ship is below the enemy ship.
 *
 * TODO : Add a margin of error for the enemy ship to fire.
 */
static int can_ship_fire(Position heros_position, Dimension heros_dimension, Position enemy_position, Dimension enemy_dimension, int projectiles_count)
{
    return get_y(heros_position) > get_y(enemy_position) + get_height(enemy_dimension) &&
           get_x(heros_position) + get_width(heros_dimension) / 2 > get_x(enemy_position) &&
           get_x(heros_position) + get_width(heros_dimension) / 2 < get_x(enemy_position) + get_width(enemy_dimension) &&
           projectiles_count < MAX_PROJECTILES;
}

void update_enemies(enemy_controller *controller, Heros heros)
{
    int i = 0;
    for (; i < controller->enemy_spawned; i++)
    {
        move_enemy(&controller->enemies[i]);
        draw_enemy(controller->enemies[i]);

        if (can_ship_fire(heros.position, heros.dimension, controller->enemies[i].position, controller->enemies[i].dimension, controller->enemies[i].list.projectiles_count))
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