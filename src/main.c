#include "../include/main.h"
#include "../include/utils/image/image.h"
#include "../include/game/model/window/window.h"
#include "../include/game/manager/event_manager/event_manager.h"
#include "../include/game/controller/player_controller.h"
#include "../include/game/model/heros.h"

typedef struct
{
    Position position;
    Dimension dimension;
    Animation animation_ennemy;
    int speed;
} Ennemys;

int main()
{
    EventManager event_manager;
    Window window;
    Heros heros;
    Ennemys ennemys;

    srand(time(NULL));

    MLV_create_window("Space Invader", "Space Invader", WINDOW_WIDTH, WINDOW_HEIGHT);
    MLV_change_frame_rate(60);

    event_manager = construct_event_manager();
    window = construct_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    heros = construct_heros();
    ennemys.position = construct_position(rand() % WINDOW_WIDTH, 0);
    ennemys.dimension = construct_dimension(get_width(heros.dimension), get_height(heros.dimension));
    ennemys.speed = 2;

    ennemys.animation_ennemy = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Battlecruiser - Base.png", 1, ennemys.dimension, BACKWARD);

    while (!is_escape_key_pressed(event_manager.keyboard_manager))
    {
        handle_events(&event_manager, 0);

        handle_heros_movement(&heros, event_manager);
        handle_heros_projectiles(&heros, event_manager);

        update_background_position(&window);

        move_position(&ennemys.position, 0, ennemys.speed);

        draw_animation(ennemys.animation_ennemy, ennemys.position);
        draw_heros(heros);

        MLV_actualise_window();
        MLV_delay_according_to_frame_rate();
    }

    exit(EXIT_SUCCESS);
}
