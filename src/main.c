#include "../include/main.h"
#include "../include/utils/image/image.h"
#include "../include/game/model/window/window.h"
#include "../include/game/manager/event_manager/event_manager.h"
#include "../include/game/controller/player_controller.h"
#include "../include/game/controller/enemy_controller.h"

#include "../include/game/model/heros.h"
#include "../include/game/model/enemy.h"

static void launch_game()
{
    EventManager event_manager = construct_event_manager();
    Window window = construct_window();
    Heros heros = construct_heros();

    while (!is_escape_key_pressed(event_manager.keyboard_manager))
    {
        update_background_position(&window);

        handle_events(&event_manager, 0);
        update_heros(&heros, event_manager);

        MLV_actualise_window();
        MLV_delay_according_to_frame_rate();
    }
}

int main()
{
    srand(time(NULL));

    MLV_create_window("Space Invader", "Space Invader", WINDOW_WIDTH, WINDOW_HEIGHT);
    MLV_change_frame_rate(30);

    launch_game();
    exit(EXIT_SUCCESS);
}
