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

void update_players(GameManager *game_manager, EventManager event_manager)
{
    int i = 0;
    int is_one_player_modifying_ship = 0;
    int player_id_to_update = 0;

    for (; i < game_manager->players.nb_players; i++)
    {
        handle_heros_actions(&game_manager->players.players[i], event_manager);
        handle_player_projectiles(&game_manager->players.players[i], event_manager);

        handle_player_bonus(&game_manager->players.players[i]);

        draw_player(game_manager->players.players[i]);
    }
}