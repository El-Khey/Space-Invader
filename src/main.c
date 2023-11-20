#include "../include/main.h"
#include "../include/utils/image/image.h"
#include "../include/model/window.h"

int main()
{
    Window window;

    MLV_create_window("Space Invader", "Space Invader", WINDOW_WIDTH, WINDOW_HEIGHT);

    window = construct_window(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (!0)
    {
        draw_window_background(window);
        MLV_actualise_window(window.background);
    }

    exit(EXIT_SUCCESS);
}
