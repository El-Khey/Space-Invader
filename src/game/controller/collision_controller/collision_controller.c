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

void handle_heros_and_enemy_collision(Players *players, enemy_controller *enemy_controller)
{
    int i = 0;
    for (; i < players->nb_players; i++)
    {
        handle_close_range_collision(&players->players[i].heros, enemy_controller);
        handle_heros_projectiles_collision(&players->players[i].heros.list, enemy_controller);
        handle_enemy_projectiles_collision(enemy_controller, &players->players[i].heros);
    }
}

void handle_asteroid_and_heros_collision(Players *players, asteroid_controller *asteroid_controller)
{
    int i, j;

    for (i = 0; i < players->nb_players; i++)
    {
        for (j = 0; j < asteroid_controller->asteroid_spawned; j++)
        {
            if (is_hitbox_colliding(players->players[i].heros.hitbox, asteroid_controller->asteroids[j].hitbox))
            {
                asteroid_controller->asteroids[j].health = 0;
                players->players[i].heros.health -= asteroid_controller->asteroids[j].damage;
                update_heros_active_ship(&players->players[i].heros);
            }
        }
    }
}