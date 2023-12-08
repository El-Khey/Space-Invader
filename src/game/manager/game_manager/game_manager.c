#include "../../../../include/game/manager/game_manager/game_manager.h"
#include "../../../../include/game/controller/players_controller.h"

GameManager construct_game_manager()
{
    GameManager game_manager;

    game_manager.window.elapsed_time = 0;
    game_manager.window.start_pause_time = 0;
    game_manager.window.end_pause_time = 0;

    game_manager.is_game_paused = 0;
    game_manager.is_game_over = 0;

    game_manager.controllers.enemy_controller = construct_enemy_controller();
    game_manager.controllers.asteroid_controller = construct_asteroid_controller();
    game_manager.controllers.bonus_controller = construct_bonus_controller();

    game_manager.settings_bar_view = construct_settings_bar_view();

    game_manager.window = construct_window();
    game_manager.players = construct_players(construct_player(0, "zestones"), construct_player(1, "zsigmondy"));

    return game_manager;
}

void update_game(GameManager *game_manager, EventManager *event_manager)
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
    game_manager->window.elapsed_time = MLV_get_time() - game_manager->window.total_pause_time;
}

void restart_game(GameManager *game_manager)
{
    game_manager->players = construct_players(construct_player(0, "zestones"), construct_player(1, "zsigmondy"));

    game_manager->controllers.enemy_controller = construct_enemy_controller();
    game_manager->controllers.asteroid_controller = construct_asteroid_controller();
    game_manager->controllers.bonus_controller = construct_bonus_controller();

    game_manager->window.total_pause_time = MLV_get_time();
    game_manager->window.elapsed_time = 0;
    game_manager->window.start_pause_time = 0;
    game_manager->window.end_pause_time = 0;

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
    game_manager->quit_game = 1;
}

int is_game_over(GameManager *game_manager)
{
    int i = 0;
    for (; i < game_manager->players.nb_players; i++)
    {
        if (game_manager->players.players[i].lives > 0)
        {
            return 0;
        }
    }

    return 1;
}