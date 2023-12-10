#include "../include/game/controller/view_controller/screens_controller.h"
#include "../include/game/manager/game_manager/backup_manager.h"
#include "../include/game/manager/event_manager/event_manager.h"
#include "../include/game/manager/game_manager/game_manager.h"
#include "../include/menu/controller/menu_controller.h"

#include "../include/menu/menu.h"
#include "../include/main.h"

static void update_menu(MenuPage *menu_page);
static void launch_game(MenuPage *menu_page, BackupManager backup_manager);

static void handle_settings_action(GameManager *game_manager, MouseManager mouse_manager)
{
    if (is_button_clicked(game_manager->views.settings_bar_view.content.mute_button, mouse_manager))
    {
        /**
         * TODO: Add the mute / play sound logic here
         */
        set_music_button_state(&game_manager->views.settings_bar_view);
    }

    else if (is_button_clicked(game_manager->views.settings_bar_view.content.pause_button, mouse_manager))
    {
        pause_game(game_manager);
    }

    else if (is_button_clicked(game_manager->views.settings_bar_view.content.resume_button, mouse_manager))
    {
        resume_game(game_manager);
    }

    game_manager->views.settings_bar_view.is_paused = is_game_paused(game_manager);
}

GameManager create_game_manager_from_menu_config(MenuPage *menu_page)
{
    Players players;
    if (menu_page->difficulty_menu.button_mode_selected == MODE_SOLO - 1)
    {
        /**
         * TODO : replace the username by the one entered by the user inside the input box
         */
        players.players[MODE_SOLO - 1] = construct_player(0, "zestones");
        players.nb_players = 1;
    }
    else if (menu_page->difficulty_menu.button_mode_selected == MODE_MULTI - 1)
    {
        players = construct_players(construct_player(0, "zestones"), construct_player(1, "zsigmondy"));
    }

    return construct_game_manager(players, menu_page->difficulty_menu.button_mode_selected, menu_page->difficulty_menu.button_difficulty_selected);
}

static void launch_game(MenuPage *menu_page, BackupManager backup_manager)
{
    EventManager event_manager = construct_event_manager();
    GameManager game_manager;

    if (menu_page->backup_menu.selected_backup_slot_index != -1)
    {
        load_game(&backup_manager, &game_manager, menu_page->backup_menu.selected_backup_slot_index);
    }
    else
    {
        game_manager = create_game_manager_from_menu_config(menu_page);
    }

    while (!game_manager.quit_game)
    {
        handle_events(&event_manager, game_manager.game_mode);
        if (!is_game_paused(&game_manager))
        {
            update_game(&game_manager, &event_manager);
        }
        else
        {
            draw_pause_screen(game_manager.views.pause_screen, event_manager.mouse_manager.position);
            handle_pause_screen_events(&game_manager, game_manager.views.pause_screen, event_manager.mouse_manager, backup_manager);
        }

        if (is_game_over(&game_manager))
        {
            draw_game_over_screen(game_manager.views.game_over_screen, event_manager.mouse_manager.position);
            handle_game_over_screen_events(&game_manager, game_manager.views.game_over_screen, event_manager.mouse_manager);
        }

        handle_settings_action(&game_manager, event_manager.mouse_manager);
        draw_settings_bar_view(&game_manager.views.settings_bar_view, game_manager.window.elapsed_time);

        MLV_delay_according_to_frame_rate();
        MLV_actualise_window();
    }

    free_backup_manager(&backup_manager);
    menu_page->type = MAIN_MENU;
    update_menu(menu_page);
}

static void update_menu(MenuPage *menu_page)
{
    MouseManager mouse_manager = construct_mouse_manager();
    /***
     */

    BackupManager backup_manager = construct_backup_manager();
    menu_page->backup_menu = construct_backup_menu_page(backup_manager);
    MLV_change_frame_rate(60);
    while (menu_page->type != GAME_START)
    {
        draw_menu_page(*menu_page, get_mouse_position(mouse_manager));

        handle_mouse_events(&mouse_manager);
        handle_menu_events(menu_page, mouse_manager);

        MLV_delay_according_to_frame_rate();
        MLV_actualise_window();
    }

    launch_game(menu_page, backup_manager);
}

static void launch_menu()
{
    MenuPage menu_page = construct_menu_page(MAIN_MENU);
    update_menu(&menu_page);
}

int main()
{
    srand(time(NULL));

    MLV_create_window("Space Invader", "Space Invader", WINDOW_WIDTH, WINDOW_HEIGHT);
    MLV_change_frame_rate(60);

    launch_menu();
    exit(EXIT_SUCCESS);
}
