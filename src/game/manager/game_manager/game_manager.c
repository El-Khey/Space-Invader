#include "../../../../include/game/manager/game_manager/game_manager.h"
#include "../../../../include/game/controller/players_controller.h"
#include "../../../../include/menu/pages/score_menu_page.h"

#define MAX_BEST_SCORES 10

GameManager construct_game_manager(Players players, GameMode game_mode, GameDifficulty game_difficulty)
{
    GameManager game_manager;

    game_manager.is_game_paused = 0;
    game_manager.is_game_over = 0;
    game_manager.quit_game = 0;

    game_manager.game_mode = game_mode;
    game_manager.game_difficulty = game_difficulty;
    game_manager.players = players;

    set_players_health(&game_manager.players, MAX_PLAYER_LIFE - game_difficulty);

    game_manager.controllers.enemy_controller = construct_enemy_controller();
    game_manager.controllers.asteroid_controller = construct_asteroid_controller();
    game_manager.controllers.bonus_controller = construct_bonus_controller();

    game_manager.views.settings_bar_view = construct_settings_bar_view();
    game_manager.views.pause_screen = construct_pause_screen();
    game_manager.views.game_over_screen = construct_game_over_screen();

    game_manager.window = construct_window();
    return game_manager;
}

void update_game(GameManager *game_manager, EventManager *event_manager, int total_menu_time)
{
    update_background_position(&game_manager->window);

    generate_enemies(&game_manager->controllers.enemy_controller);
    update_enemies(&game_manager->controllers.enemy_controller, &game_manager->players);

    /**
     * TODO : pass the controllers as a pointer
     */
    handle_heros_collision(&game_manager->players, &game_manager->controllers.enemy_controller, &game_manager->controllers.bonus_controller, &game_manager->controllers.asteroid_controller);

    generate_asteroids(&game_manager->controllers.asteroid_controller);
    update_asteroids(&game_manager->controllers.asteroid_controller);

    generate_bonus(&game_manager->controllers.bonus_controller);
    update_bonus(&game_manager->controllers.bonus_controller);

    update_players(game_manager, *event_manager);
    if (!is_game_over(game_manager))
    {
        game_manager->window.elapsed_time = MLV_get_time() - game_manager->window.total_pause_time - total_menu_time - game_manager->window.total_game_over_time;
    }
}

void restart_game(GameManager *game_manager)
{
    if (game_manager->players.nb_players == MODE_MULTI)
    {
        game_manager->players = construct_players(construct_player(0, game_manager->players.players[0].username),
                                                  construct_player(1, game_manager->players.players[1].username));
    }
    else
    {
        game_manager->players.players[0] = construct_player(0, game_manager->players.players[0].username);
    }

    game_manager->controllers.enemy_controller = construct_enemy_controller();
    game_manager->controllers.asteroid_controller = construct_asteroid_controller();
    game_manager->controllers.bonus_controller = construct_bonus_controller();

    game_manager->window.elapsed_time = 0;

    game_manager->window.total_pause_time = 0;
    game_manager->window.start_pause_time = 0;
    game_manager->window.end_pause_time = 0;

    game_manager->window.total_game_over_time = 0;
    game_manager->window.start_game_over_time = 0;
    game_manager->window.end_game_over_time = 0;

    game_manager->is_game_paused = 0;
    game_manager->is_game_over = 0;
}

void pause_game(GameManager *game_manager)
{
    game_manager->window.start_pause_time = MLV_get_time();
    game_manager->is_game_paused = 1;
}

void resume_game(GameManager *game_manager)
{
    game_manager->is_game_paused = 0;

    game_manager->window.end_pause_time = MLV_get_time();
    game_manager->window.total_pause_time += game_manager->window.end_pause_time - game_manager->window.start_pause_time;
}

int is_game_paused(GameManager *game_manager)
{
    return game_manager->is_game_paused;
}

void quit_game(GameManager *game_manager)
{
    if (is_game_paused(game_manager))
    {
        game_manager->window.end_pause_time = MLV_get_time();
        game_manager->window.total_pause_time += game_manager->window.end_pause_time - game_manager->window.start_pause_time;
    }
    else if (is_game_over(game_manager))
    {
        game_manager->window.end_game_over_time = MLV_get_time();
        game_manager->window.total_game_over_time += game_manager->window.end_game_over_time - game_manager->window.start_game_over_time;
        printf("total game over time : %d\n", game_manager->window.total_game_over_time);
    }

    free_players(&game_manager->players);

    /**
        free_enemy_controller(&game_manager->controllers.enemy_controller);
        free_bonus_controller(&game_manager->controllers.bonus_controller);
        free_asteroid_controller(&game_manager->controllers.asteroid_controller);

        free_settings_bar_view(&game_manager->views.settings_bar_view);
        free_game_over_screen(&game_manager->views.game_over_screen);
        free_pause_screen(&game_manager->views.pause_screen);

        free_window(&game_manager->window);
     */

    game_manager->quit_game = 1;
}

int is_game_over(GameManager *game_manager)
{
    int i = 0;
    for (; i < game_manager->players.nb_players; i++)
    {
        if (game_manager->players.players[i].heros.health > 0)
        {
            return 0;
        }
    }

    if (game_manager->window.start_game_over_time == 0)
    {
        game_manager->window.start_game_over_time = MLV_get_time();
    }

    return 1;
}
