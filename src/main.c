#include "../include/game/manager/event_manager/event_manager.h"
#include "../include/game/manager/game_manager/game_manager.h"

#include "../include/main.h"

static void launch_game()
{
    EventManager event_manager = construct_event_manager();
    GameManager game_manager = construct_game_manager();

    while (!is_escape_key_pressed(event_manager.keyboard_manager))
    {
        handle_events(&event_manager, 1);
        update_game(&game_manager, &event_manager);

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
