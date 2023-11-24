#include "../include/main.h"
#include "../include/utils/image/image.h"
#include "../include/game/model/window/window.h"
#include "../include/game/manager/event_manager/event_manager.h"
#include "../include/game/controller/player_controller.h"
#include "../include/game/model/objet/creature/heros/heros.h"

int main()
{
    EventManager eventManager;
    Window window;
    Heros heros;

    MLV_create_window("Space Invader", "Space Invader", WINDOW_WIDTH, WINDOW_HEIGHT);
    MLV_change_frame_rate(60);

    eventManager = construct_event_manager();
    window = construct_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    heros = construct_heros(5);

    while (!0)
    {
        handle_player_movement(&heros, &eventManager);

        update_background_position(&window);

        MLV_draw_filled_rectangle(get_x(heros.creature.objet.position), get_y(heros.creature.objet.position), get_width(heros.creature.objet.dimension), get_height(heros.creature.objet.dimension), MLV_COLOR_RED);

        if (eventManager.keyboard_manager.event[0].attack_keys.key_attack_1)
        {
            MLV_draw_filled_rectangle(get_x(heros.creature.objet.position) + get_width(heros.creature.objet.dimension) / 2 - 5, get_y(heros.creature.objet.position) - 10, 10, 10, MLV_COLOR_GREEN1);
        }

        MLV_actualise_window(window.background);
        MLV_delay_according_to_frame_rate();
    }

    exit(EXIT_SUCCESS);
}
