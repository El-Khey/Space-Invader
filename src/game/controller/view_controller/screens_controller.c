#include "../../../../include/game/controller/view_controller/screens_controller.h"

void handle_pause_screen_events(GameManager *game_manager, PauseScreen pause_screen, MouseManager mouse_manager, BackupManager backup_manager)
{
    if (is_button_clicked(pause_screen.resume_button, mouse_manager))
    {
        resume_game(game_manager);
    }
    else if (is_button_clicked(pause_screen.quit_button, mouse_manager))
    {
        save_best_scores(&backup_manager, *game_manager);
        quit_game(game_manager);
    }
    else if (is_button_clicked(pause_screen.save_and_quit_button, mouse_manager))
    {
        save_game(game_manager, backup_manager.backup_list.backups_count);
        save_best_scores(&backup_manager, *game_manager);
        quit_game(game_manager);
    }
}

void handle_game_over_screen_events(GameManager *game_manager, BackupManager backup_manager, GameOverScreen game_over_screen, MouseManager mouse_manager, int *menu_time)
{
    if (is_button_clicked(game_over_screen.back_to_menu_button, mouse_manager))
    {
        save_best_scores(&backup_manager, *game_manager);
        quit_game(game_manager);
    }
    else if (is_button_clicked(game_over_screen.restart_button, mouse_manager))
    {

        game_manager->window.total_game_over_time = MLV_get_time() - game_manager->window.start_game_over_time;
        *menu_time += game_manager->window.elapsed_time + game_manager->window.total_pause_time + game_manager->window.total_game_over_time;
        restart_game(game_manager);
    }
}