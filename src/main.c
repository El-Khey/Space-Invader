#include "../include/game/manager/event_manager/event_manager.h"
#include "../include/game/manager/game_manager/game_manager.h"
#include "../include/game/controller/view_controller/screens_controller.h"

#include "../include/main.h"

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

static void launch_game()
{
    EventManager event_manager = construct_event_manager();
    GameManager game_manager = construct_game_manager(construct_players(construct_player(0, "zestones"), construct_player(1, "zsigmondy")), MODE_MULTI, DIFFICULTY_HARD);

    while (!is_escape_key_pressed(event_manager.keyboard_manager))
    {
        handle_events(&event_manager, game_manager.game_mode - 1);
        if (!is_game_paused(&game_manager))
        {
            update_game(&game_manager, &event_manager);
        }
        else
        {
            draw_pause_screen(game_manager.views.pause_screen, event_manager.mouse_manager.position);
        }

        if (is_game_over(&game_manager))
        {
            draw_game_over_screen(game_manager.views.game_over_screen, event_manager.mouse_manager.position);
        }

        handle_settings_action(&game_manager, event_manager.mouse_manager);
        draw_settings_bar_view(&game_manager.views.settings_bar_view, game_manager.window.elapsed_time);

        handle_pause_screen_events(&game_manager, game_manager.views.pause_screen, event_manager.mouse_manager);
        handle_game_over_screen_events(&game_manager, game_manager.views.game_over_screen, event_manager.mouse_manager);

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
