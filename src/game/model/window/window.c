#include "../../../../include/model/window.h"
#include "../../../../include/utils/image/image.h"

Window construct_window(int width, int height)
{
    Window window;

    MLV_Image *loaded_image = MLV_load_image("assets/background/map1.jpg");
    is_image_loaded_successfully(loaded_image, "assets/background/map1.jpg");

    window.dimension.height = height;
    window.dimension.width = width;

    MLV_resize_image(loaded_image, width, height);

    window.background = loaded_image;
    window.position.x = 0;
    window.position.y = 0;

    return window;
}

void draw_window_background(Window window)
{
    MLV_draw_image(window.background, window.position.x, window.position.y);
}
