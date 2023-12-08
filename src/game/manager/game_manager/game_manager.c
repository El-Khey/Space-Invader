#include "../../../../include/game/manager/game_manager/game_manager.h"

GameManager construct_game_manager()
{
    GameManager game_manager;

    game_manager.controllers.enemy_controller = construct_enemy_controller();
    game_manager.controllers.asteroid_controller = construct_asteroid_controller();
    game_manager.controllers.bonus_controller = construct_bonus_controller();

    game_manager.window = construct_window();
    game_manager.players = construct_players(construct_player(0, "zestones"), construct_player(1, "zsigmondy"));

    /**
    game_manager.players.players[0] = construct_player(0, "zestones");
    game_manager.players.nb_players = 1;
     */
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

    update_players(&game_manager->players, *event_manager);
}