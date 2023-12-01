#include "../include/main.h"
#include "../include/utils/image/image.h"
#include "../include/game/model/window/window.h"
#include "../include/game/manager/event_manager/event_manager.h"
#include "../include/game/controller/player_controller.h"
#include "../include/game/controller/enemy_controller.h"
#include "../include/game/model/heros.h"

static void launch_game()
{
    EventManager event_manager = construct_event_manager();
    enemy_controller enemy_controller = construct_enemy_controller();

    Window window = construct_window();
    Heros heros = construct_heros();

    while (!is_escape_key_pressed(event_manager.keyboard_manager))
    {
        handle_events(&event_manager, 0);

        update_background_position(&window);
        update_heros(&heros, event_manager);

        generate_enemies(&enemy_controller);
        update_enemies(&enemy_controller, heros);

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
