#include "../../../include/game/controller/players_controller.h"

static void handle_heros_actions(Player *player, EventManager event_manager)
{
    if (is_position_with_dimension_inside_rect(construct_position(player->heros.position.x + player->heros.speed, player->heros.position.y), player->heros.dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)) && event_manager.keyboard_manager.event[player->id].arrow_keys.key_right)
    {
        move_heros_right(&player->heros);
    }
    if (is_position_with_dimension_inside_rect(construct_position(player->heros.position.x - player->heros.speed, player->heros.position.y), player->heros.dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)) && event_manager.keyboard_manager.event[player->id].arrow_keys.key_left)
    {
        move_heros_left(&player->heros);
    }
    if (is_position_with_dimension_inside_rect(construct_position(player->heros.position.x, player->heros.position.y + player->heros.speed), player->heros.dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)) && event_manager.keyboard_manager.event[player->id].arrow_keys.key_down)
    {
        move_heros_down(&player->heros);
    }
    if (is_position_with_dimension_inside_rect(construct_position(player->heros.position.x, player->heros.position.y - player->heros.speed), player->heros.dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)) && event_manager.keyboard_manager.event[player->id].arrow_keys.key_up)
    {
        player->heros.is_boost_activated = 1;
        move_heros_up(&player->heros);
    }
    else
    {
        player->heros.is_boost_activated = 0;
    }

    /**
     * TODO : a supprimer les moteurs se change depuis l'ecran
     */
    if (event_manager.keyboard_manager.event[player->id].attack_keys.key_attack_2)
    {
        player->heros.active_engine = (player->heros.active_engine + 1) % nb_engine_animations;
    }

    if (event_manager.keyboard_manager.event[player->id].attack_keys.key_attack_3)
    {
        player->heros.active_weapon = (player->heros.active_weapon + 1) % 4;
        player->heros.list.active_bullet_type = player->heros.active_weapon;
    }
}

static void handle_player_projectiles(Player *player, EventManager event_manager)
{
    if (event_manager.keyboard_manager.event[player->id].attack_keys.key_attack_1 && player->heros.list.projectiles_count < MAX_PROJECTILES)
    {
        if (!player->heros.is_firing)
        {
            play_animation(&player->heros.weapons_animations[player->heros.active_weapon].weapon_shooting);
            player->heros.is_firing = 1;

            player->heros.list.projectiles[player->heros.list.projectiles_count] = construct_heros_projectile(player->heros.list.active_bullet_type, player->heros.position, player->heros.dimension);
            player->heros.list.projectiles_count += 1;
        }
    }

    if (is_animation_finished(player->heros.weapons_animations[player->heros.active_weapon].weapon_shooting, MLV_get_time()) && player->heros.is_firing)
    {
        rewind_animation(&player->heros.weapons_animations[player->heros.active_weapon].weapon_shooting);
        stop_animation(&player->heros.weapons_animations[player->heros.active_weapon].weapon_shooting);

        player->heros.is_firing = 0;
    }

    update_projectiles(&player->heros.list);
}

static void handle_player_bonus(Player *player)
{
    if (player->heros.shield.is_active)
    {
        if (player->heros.shield.active_time <= MLV_get_time())
        {
            player->heros.shield = construct_shield(SHIELD_NONE, player->heros.position, player->heros.dimension);
        }
    }
}

void update_players(Players *players, EventManager event_manager)
{
    int i = 0;
    for (; i < players->nb_players; i++)
    {
        handle_heros_actions(&players->players[i], event_manager);
        handle_player_projectiles(&players->players[i], event_manager);

        handle_player_bonus(&players->players[i]);

        draw_player(players->players[i]);
    }
}