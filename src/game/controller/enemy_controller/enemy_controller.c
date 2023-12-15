#include "../../../../include/game/controller/enemy_controller.h"

enemy_controller construct_enemy_controller()
{
    enemy_controller enemy_controller;

    enemy_controller.last_enemy_spawn_time = 0;
    enemy_controller.delay_between_spawn = 3000;

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
static int can_ship_fire(Position heros_position, Dimension heros_dimension, Enemy enemy)
{
    return get_y(heros_position) > get_y(enemy.position) + get_height(enemy.dimension) &&
           get_x(heros_position) + get_width(heros_dimension) / 2 > get_x(enemy.position) &&
           get_x(heros_position) + get_width(heros_dimension) / 2 < get_x(enemy.position) + get_width(enemy.dimension) &&
           enemy.list.projectiles_count < MAX_PROJECTILES &&
           !is_enemy_dead(enemy);
}

static void handle_enemy_attacks(Enemy *enemy, Heros heros)
{
    if (can_ship_fire(heros.position, heros.dimension, *enemy))
    {
        if (enemy->event_in_process != ATTACKING)
        {
            enemy->list.projectiles[enemy->list.projectiles_count] = construct_enemy_projectile(enemy->list.active_bullet_type, enemy->position, enemy->dimension);
            enemy->list.projectiles[enemy->list.projectiles_count].speed = -enemy->list.projectiles[enemy->list.projectiles_count].speed;
            enemy->list.projectiles_count++;

            enemy->event_in_process = ATTACKING;
            enemy->enemy_animation.active_state = ATTACK;
            play_animation(&enemy->enemy_animation.ship[enemy->enemy_animation.active_state]);
        }
    }

    if (is_animation_finished(enemy->enemy_animation.ship[enemy->enemy_animation.active_state], MLV_get_time()) && enemy->event_in_process == ATTACKING)
    {
        rewind_animation(&enemy->enemy_animation.ship[enemy->enemy_animation.active_state]);
        stop_animation(&enemy->enemy_animation.ship[enemy->enemy_animation.active_state]);

        enemy->event_in_process = NOTHING;
        enemy->enemy_animation.active_state = BASE;
    }
}

static void handle_enemy_death(enemy_controller *controller, int index)
{
    if (is_enemy_dead(controller->enemies[index]))
    {
        if (controller->enemies[index].event_in_process != DYING)
        {
            controller->enemies[index].event_in_process = DYING;
            controller->enemies[index].enemy_animation.active_state = DESTRUCTION;

            play_animation(&controller->enemies[index].enemy_animation.ship[controller->enemies[index].enemy_animation.active_state]);
        }

        if (is_animation_finished(controller->enemies[index].enemy_animation.ship[controller->enemies[index].enemy_animation.active_state], MLV_get_time()) && controller->enemies[index].event_in_process == DYING)
        {
            controller->enemy_spawned--;
            controller->enemies[index] = controller->enemies[controller->enemy_spawned];
            controller->enemies[index].event_in_process = NOTHING;
        }
    }
}

void update_enemies(enemy_controller *controller, Players *players)
{
    int i, j;

    for (j = 0; j < controller->enemy_spawned; j++)
    {
        move_enemy(&controller->enemies[j]);
        draw_enemy(controller->enemies[j]);

        update_projectiles(&controller->enemies[j].list);
        handle_enemy_death(controller, j);

        if (is_enemy_out_of_screen(controller->enemies[j]))
        {
            controller->enemy_spawned--;
            controller->enemies[j] = controller->enemies[controller->enemy_spawned];
            for (i = 0; i < players->nb_players; i++)
            {
                players->players[i].heros.health -= 1;
            }
        }

        for (i = 0; i < players->nb_players; i++)
        {
            if (!is_heros_alive(players->players[i].heros))
            {
                continue;
            }
            handle_enemy_attacks(&controller->enemies[j], players->players[i].heros);
        }
    }
}

void free_enemy_controller(enemy_controller *controller)
{
    int i;
    for (i = 0; i < controller->enemy_spawned; i++)
    {
        free_enemy(&controller->enemies[i]);
    }
}