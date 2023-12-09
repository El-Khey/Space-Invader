#include "../../../../include/game/controller/view_controller/screens_controller.h"

void handle_pause_screen_events(GameManager *game_manager, PauseScreen pause_screen, MouseManager mouse_manager)
{
    if (is_button_clicked(pause_screen.resume_button, mouse_manager))
    {
        resume_game(game_manager);
    }
    else if (is_button_clicked(pause_screen.quit_button, mouse_manager))
    {
        quit_game(game_manager);
    }
    else if (is_button_clicked(pause_screen.save_and_quit_button, mouse_manager))
    {
        /**
         * TODO: Save and quit
            save_and_quit_game(game_manager);
         */
    }
}

void handle_game_over_screen_events(GameManager *game_manager, GameOverScreen game_over_screen, MouseManager mouse_manager)
{
    if (is_button_clicked(game_over_screen.back_to_menu_button, mouse_manager))
    {
        /**
         * TODO: Back to menu
         */
        quit_game(game_manager);
    }
    else if (is_button_clicked(game_over_screen.restart_button, mouse_manager))
    {
        restart_game(game_manager);
    }
}