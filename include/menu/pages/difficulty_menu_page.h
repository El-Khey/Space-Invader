#ifndef DIFFICULTY_MENU_PAGE_H
#define DIFFICULTY_MENU_PAGE_H

#include "../../gui/button/button.h"
#include "../../utils/image/image.h"
#include "../../gui/shape/shape.h"
#include "../../game/manager/game_manager/game_details.h"

typedef struct
{
    Button buttons_difficulty[nb_difficulties];
    int button_difficulty_selected;

    Button buttons_mode[nb_modes - 1];
    int button_mode_selected;

    Button button_back;
    Button button_validation;
} DifficultyMenu;

DifficultyMenu construct_difficulty_menu_page();

void draw_difficulty_menu_page(DifficultyMenu difficulty_menu, Position mouse_position);

#endif