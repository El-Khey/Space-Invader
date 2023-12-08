#include "../../../../include/game/controller/collision_controller/collision_controller.h"

static void handle_heros_and_enemy_close_range_collision(Heros *heros, enemy_controller *enemy_controller)
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
            if (!heros->shield.is_active)
            {
                heros->health -= enemy_controller->enemies[i].damage;
            }
            update_heros_active_ship(heros);
        }
    }
}

static void handle_heros_projectiles_and_enemy_collision(Projectiles *list, enemy_controller *enemy_controller)
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
                    if (!heros->shield.is_active)
                    {
                        heros->health -= enemy_controller->enemies[i].list.projectiles[j].damage;
                    }

                    enemy_controller->enemies[i].list.projectiles[j].list.bullets[k] = enemy_controller->enemies[i].list.projectiles[j].list.bullets[enemy_controller->enemies[i].list.projectiles[j].list.bullets_count - 1];
                    enemy_controller->enemies[i].list.projectiles[j].list.bullets_count--;

                    update_heros_active_ship(heros);
                }
            }
        }
    }
}

static void handle_bonus_selection(Heros *heros, Bonus bonus)
{
    switch (bonus.type)
    {
    case BONUS_TYPE_SHIELD_ALL_AROUND:
        heros->shield = construct_shield(SHIELD_ALL_AROUND, heros->position, heros->dimension);
        break;

    case BONUS_TYPE_SHIELD_FRONT_AND_SIDE:
        heros->shield = construct_shield(SHIELD_FRONT_AND_SIDE, heros->position, heros->dimension);
        break;

    case BONUS_TYPE_SHIELD_FRONT:
        heros->shield = construct_shield(SHIELD_FRONT, heros->position, heros->dimension);
        break;

    case BONUS_TYPE_SHIELD_INVINCIBILITY:
        heros->shield = construct_shield(SHIELD_INVINCIBILITY, heros->position, heros->dimension);
        break;

    case BONUS_TYPE_LIFE:
        heros->health = (heros->health == MAX_PLAYER_LIFE) ? heros->health : heros->health + 1;
        break;

    default:
        fprintf(stderr, "Error: unknown bonus type\n");
        break;
    }
}

static void handle_heros_and_bonus_collision(Player *player, bonus_controller *bonus_controller)
{
    int i;
    for (i = 0; i < bonus_controller->bonus_spawned; i++)
    {
        if (is_hitbox_colliding(player->heros.hitbox, bonus_controller->bonus[i].hitbox))
        {
            bonus_controller->bonus[i].is_selected = 1;
            handle_bonus_selection(&player->heros, bonus_controller->bonus[i]);
        }
    }
}

static void handle_heros_projectiles_and_bonus_collision(Heros *heros, bonus_controller *bonus_controller)
{
    int i, j, k;
    for (i = 0; i < heros->list.projectiles_count; i++)
    {
        for (j = 0; j < bonus_controller->bonus_spawned; j++)
        {
            for (k = 0; k < heros->list.projectiles[i].list.bullets_count; k++)
            {
                if (is_hitbox_colliding(heros->list.projectiles[i].list.bullets[k].hitbox, bonus_controller->bonus[j].hitbox))
                {
                    bonus_controller->bonus[j].is_selected = 1;
                    handle_bonus_selection(heros, bonus_controller->bonus[j]);

                    heros->list.projectiles[i].list.bullets[k] = heros->list.projectiles[i].list.bullets[heros->list.projectiles[i].list.bullets_count - 1];
                    heros->list.projectiles[i].list.bullets_count--;
                }
            }
        }
    }
}

static void handle_asteroid_and_heros_close_range_collision(Player *player, asteroid_controller *asteroid_controller)
{
    int i;
    for (i = 0; i < asteroid_controller->asteroid_spawned; i++)
    {
        if (is_hitbox_colliding(player->heros.hitbox, asteroid_controller->asteroids[i].hitbox))
        {
            asteroid_controller->asteroids[i].health = 0;
            if (!player->heros.shield.is_active)
            {
                player->heros.health -= asteroid_controller->asteroids[i].damage;
            }

            update_heros_active_ship(&player->heros);
        }
    }
}

static void handle_asteroid_and_heros_projectiles_collision(Projectiles *list, asteroid_controller *asteroid_controller)
{
    int i, j, k;
    for (i = 0; i < list->projectiles_count; i++)
    {
        for (k = 0; k < asteroid_controller->asteroid_spawned; k++)
        {
            for (j = 0; j < list->projectiles[i].list.bullets_count; j++)
            {
                if (is_hitbox_colliding(list->projectiles[i].list.bullets[j].hitbox, asteroid_controller->asteroids[k].hitbox))
                {
                    asteroid_controller->asteroids[k].health = 0;

                    list->projectiles[i].list.bullets[j] = list->projectiles[i].list.bullets[list->projectiles[i].list.bullets_count - 1];
                    list->projectiles[i].list.bullets_count--;
                    break;
                }
            }
        }
    }
}

static void handle_heros_asteroid_collision(Player *player, asteroid_controller *asteroid_controller)
{
    handle_asteroid_and_heros_close_range_collision(player, asteroid_controller);
    handle_asteroid_and_heros_projectiles_collision(&player->heros.list, asteroid_controller);
}

static void handle_heros_bonus_collision(Player *player, bonus_controller *bonus_controller)
{
    handle_heros_and_bonus_collision(player, bonus_controller);
    handle_heros_projectiles_and_bonus_collision(&player->heros, bonus_controller);
}

static void handle_heros_enemy_collision(Player *player, enemy_controller *enemy_controller)
{
    handle_heros_and_enemy_close_range_collision(&player->heros, enemy_controller);
    handle_heros_projectiles_and_enemy_collision(&player->heros.list, enemy_controller);
    handle_enemy_projectiles_collision(enemy_controller, &player->heros);
}

void handle_heros_collision(Players *players, enemy_controller *enemy_controller, bonus_controller *bonus_controller, asteroid_controller *asteroid_controller)
{
    int i = 0;
    for (; i < players->nb_players; i++)
    {
        handle_heros_enemy_collision(&players->players[i], enemy_controller);
        handle_heros_bonus_collision(&players->players[i], bonus_controller);
        handle_heros_asteroid_collision(&players->players[i], asteroid_controller);
    }
}
