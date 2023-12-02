#include "../include/game/controller/collision_controller/collision_controller.h"
#include "../include/game/controller/asteroid_controller/asteroid_controller.h"
#include "../include/game/controller/bonus_controller/bonus_controller.h"
#include "../include/game/manager/event_manager/event_manager.h"
#include "../include/game/controller/players_controller.h"
#include "../include/game/controller/enemy_controller.h"
#include "../include/game/model/window/window.h"
#include "../include/game/model/player.h"
#include "../include/main.h"

static void launch_game()
{
    EventManager event_manager = construct_event_manager();

    enemy_controller enemy_controller = construct_enemy_controller();
    asteroid_controller asteroid_controller = construct_asteroid_controller();
    bonus_controller bonus_controller = construct_bonus_controller();

    Window window = construct_window();
    Player player_1 = construct_player(0, "Player 1");

    Players players = construct_players(player_1, construct_player(1, "Player 2"));
    while (!is_escape_key_pressed(event_manager.keyboard_manager))
    {
        handle_events(&event_manager, 1);

        update_background_position(&window);
        update_players(&players, event_manager);

        generate_enemies(&enemy_controller);
        update_enemies(&enemy_controller, &players);

        handle_heros_collision(&players, &enemy_controller, &bonus_controller, &asteroid_controller);

        generate_asteroids(&asteroid_controller);
        update_asteroids(&asteroid_controller);

        generate_bonus(&bonus_controller);
        update_bonus(&bonus_controller);

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
