#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "../../gui/button/button.h"
#include "../../utils/image/image.h"
#include "../../gui/shape/shape.h"

typedef enum
{
    PLAY_BUTTON,
    BEST_SCORE_BUTTON,
    SAVE_BUTTON,
    QUIT_BUTTON,
    nb_buttons
} MainMenuButton;

typedef struct
{
    Button buttons[nb_buttons];
} MainMenu;

MainMenu construct_main_menu_page();

void draw_main_menu_page(MainMenu menu, Position mouse_position);

#endif