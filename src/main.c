#include "../include/game/manager/event_manager/event_manager.h"
#include "../include/game/manager/game_manager/game_manager.h"
#include "../include/game/view/settings_bar_view.h"
#include "../include/main.h"

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

static void handle_settings_action(GameManager *game_manager, MouseManager mouse_manager)
{
    if (is_button_clicked(game_manager->settings_bar_view.content.mute_button, mouse_manager))
    {
        /**
         * TODO: Add the mute / play sound logic here
         */
        set_music_button_state(&game_manager->settings_bar_view);
    }

    else if (is_button_clicked(game_manager->settings_bar_view.content.pause_button, mouse_manager))
    {
        pause_game(game_manager);
    }

    else if (is_button_clicked(game_manager->settings_bar_view.content.resume_button, mouse_manager))
    {
        resume_game(game_manager);
    }

    game_manager->settings_bar_view.is_paused = is_game_paused(game_manager);
}

static void manage_customization(GameManager *game_manager, EventManager event_manager)
{
    int i = 0;
    int is_one_player_modifying_ship = 0;
    int player_id_to_update = 0;

    for (; i < game_manager->players.nb_players; i++)
    {
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
        pause_game(game_manager);
    }

    for (i = 0; i < game_manager->players.nb_players; i++)
    {
        handle_ship_customization_events(&game_manager->players.players[i].ship_customization_view, event_manager, is_one_player_modifying_ship);
    }
}

static void launch_game()
{
    EventManager event_manager = construct_event_manager();
    GameManager game_manager = construct_game_manager();

    while (!is_escape_key_pressed(event_manager.keyboard_manager))
    {
        handle_events(&event_manager, 1);

        if (!is_game_paused(&game_manager))
        {
            update_game(&game_manager, &event_manager);
        }

        manage_customization(&game_manager, event_manager);

        handle_settings_action(&game_manager, event_manager.mouse_manager);
        draw_settings_bar_view(&game_manager.settings_bar_view, game_manager.window.elapsed_time);

        MLV_delay_according_to_frame_rate();
        MLV_actualise_window();
    }
}

int main()
{
    srand(time(NULL));

    MLV_create_window("Space Invader", "Space Invader", WINDOW_WIDTH, WINDOW_HEIGHT);
    MLV_change_frame_rate(60);

    launch_game();
    exit(EXIT_SUCCESS);
}
