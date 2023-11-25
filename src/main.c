#include "../include/main.h"
#include "../include/utils/image/image.h"
#include "../include/game/model/window/window.h"
#include "../include/game/manager/event_manager/event_manager.h"
#include "../include/game/controller/player_controller.h"
#include "../include/game/model/heros.h"

int main()
{
    EventManager eventManager;
    Window window;
    Heros heros;
    int i;

    MLV_create_window("Space Invader", "Space Invader", WINDOW_WIDTH, WINDOW_HEIGHT);
    MLV_change_frame_rate(60);

    eventManager = construct_event_manager();
    window = construct_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    heros = construct_heros(5);

    while (!is_escape_key_pressed(eventManager.keyboard_manager))
    {
        handle_heros_movement(&heros, &eventManager);

        update_background_position(&window);
        draw_heros(heros);

        if (eventManager.keyboard_manager.event[0].attack_keys.key_attack_1 && heros.list.projectiles_count < MAX_PROJECTILES)
        {
            heros.list.projectiles[heros.list.projectiles_count] = construct_projectile(heros.position, heros.dimension);
            heros.list.projectiles_count += 1;
        }

        for (i = 0; i < heros.list.projectiles_count; i++)
        {
            move_position(&heros.list.projectiles[i].position, 0, -heros.list.projectiles[i].speed);
        }

        MLV_actualise_window(window.background);
        MLV_delay_according_to_frame_rate();
    }

    exit(EXIT_SUCCESS);
}
