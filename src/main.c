#include "../include/main.h"
#include "../include/utils/image/image.h"
#include "../include/game/model/window/window.h"
#include "../include/game/manager/event_manager/event_manager.h"
#include "../include/game/controller/player_controller.h"
#include "../include/game/model/heros.h"

int main()
{
    EventManager event_manager;
    Window window;
    Heros heros;

    MLV_create_window("Space Invader", "Space Invader", WINDOW_WIDTH, WINDOW_HEIGHT);
    MLV_change_frame_rate(60);

    event_manager = construct_event_manager();
    window = construct_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    heros = construct_heros();

    while (!is_escape_key_pressed(event_manager.keyboard_manager))
    {
        handle_events(&event_manager, 0);

        handle_heros_movement(&heros, event_manager);
        handle_heros_projectiles(&heros, event_manager);

        update_background_position(&window);
        draw_heros(heros);

        MLV_actualise_window();
        MLV_delay_according_to_frame_rate();
    }

    exit(EXIT_SUCCESS);
}
