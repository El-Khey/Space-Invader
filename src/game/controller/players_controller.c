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

static void handle_ship_customization_events(ShipCustomizationView *ship_customization, EventManager event_manager, int is_one_player_modifying_ship)
{
    int i = 0;
    for (i = 0; i < CUSTOMIZATION_NUMBER_OF_BUTTONS; i++)
    {
        if (is_button_clicked(ship_customization->bar.button[i], event_manager.mouse_manager))
        {
            if (is_one_player_modifying_ship)
            {
                ship_customization->is_modal_active = 0;
            }
            else
            {
                ship_customization->is_modal_active = !ship_customization->is_modal_active;
                ship_customization->active_modal = i;
            }
        }
    }
}

static void handle_ship_customization_selection(Player *player, EventManager event_manager)
{
    int i;
    for (i = 0; i < MAX_SHIP_LEVEL; i++)
    {
        if (player->ship_customization_view.is_modal_active && player->ship_customization_view.active_modal == MODAL_ENGINE && is_button_clicked(player->ship_customization_view.modal[player->id].engine_buttons[i], event_manager.mouse_manager))
        {
            if (player->gold >= get_engine_price(i))
            {
                player->gold -= get_engine_price(i);
                set_text_content(&player->view.gold.gold_text, convert_int_to_string(player->gold));
                player->heros.active_engine = i;
            }
        }
        else if (player->ship_customization_view.is_modal_active && player->ship_customization_view.active_modal == MODAL_WEAPON && is_button_clicked(player->ship_customization_view.modal[player->id].weapon_buttons[i], event_manager.mouse_manager))
        {
            if (player->gold >= get_weapon_price(i))
            {
                player->gold -= get_weapon_price(i);
                set_text_content(&player->view.gold.gold_text, convert_int_to_string(player->gold));
                player->heros.active_weapon = i;
                player->heros.list.active_bullet_type = player->heros.active_weapon;
            }
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
        draw_ship_customization(game_manager->players.players[i].ship_customization_view, event_manager.mouse_manager.position);
        if (game_manager->players.players[i].ship_customization_view.is_modal_active)
        {
            is_one_player_modifying_ship = 1;
            player_id_to_update = i;
        }
    }

    if (is_one_player_modifying_ship)
    {
        handle_ship_customization_selection(&game_manager->players.players[player_id_to_update], event_manager);
    }

    for (i = 0; i < game_manager->players.nb_players; i++)
    {
        handle_ship_customization_events(&game_manager->players.players[i].ship_customization_view, event_manager, is_one_player_modifying_ship);
    }
}