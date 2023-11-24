#include "../../../../include/game/model/window/window.h"

Window construct_window(int width, int height)
{
    Window window;

    window.background = load_image("assets/background/map3.jpg", construct_dimension(width, height));
    window.next_background = load_image("assets/background/map3.jpg", construct_dimension(width, height));

    set_image_position(&window.next_background, construct_position(0, -height));
    MLV_horizontal_image_mirror(window.next_background.image);

    window.dimension.height = WINDOW_HEIGHT;
    window.dimension.width = WINDOW_WIDTH;

    window.position.x = 0;
    window.position.y = 0;

    return window;
}

void update_background_position(Window *window)
{
    move_position(&window->background.position, 0, 1);
    move_position(&window->next_background.position, 0, 1);

    if (get_y(window->background.position) >= get_height(window->background.dimension))
    {
        set_image_position(&window->background, construct_position(0, -get_height(window->background.dimension)));
    }
    else if (get_y(window->next_background.position) >= get_height(window->next_background.dimension))
    {
        set_image_position(&window->next_background, construct_position(0, get_y(window->background.position) - get_height(window->next_background.dimension)));
    }

    draw_image(&window->background);
    draw_image(&window->next_background);
}
