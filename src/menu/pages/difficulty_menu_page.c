#include "../../../include/menu/pages/difficulty_menu_page.h"

#define BUTTON_WIDTH 450
#define BUTTON_HEIGHT 50

#define BUTTON_MARGIN_TOP 100
#define BUTTON_SPACING 20

DifficultyMenu construct_difficulty_menu_page()
{
    DifficultyMenu page;

    MLV_Color foreground = MLV_COLOR_WHITE;
    MLV_Color background = MLV_rgba(12, 12, 17, 200);

    int button_y = 250;
    int button_x = WINDOW_WIDTH / 2 - (BUTTON_WIDTH + BUTTON_SPACING) * nb_difficulties / 2;

    page.buttons_difficulty[EASY] = construct_button_with_text("Facile", construct_position(button_x, button_y), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);
    button_x += BUTTON_WIDTH + BUTTON_SPACING;

    page.buttons_difficulty[MEDIUM] = construct_button_with_text("Moyen", construct_position(button_x, button_y), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);
    button_x += BUTTON_WIDTH + BUTTON_SPACING;

    page.buttons_difficulty[HARD] = construct_button_with_text("Difficile", construct_position(button_x, button_y), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);
    button_y += BUTTON_HEIGHT + BUTTON_MARGIN_TOP;

    page.buttons_mode[MODE_SOLO - 1] = construct_button_with_text("Solo", construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, button_y), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);
    button_y += BUTTON_HEIGHT + BUTTON_SPACING;

    page.buttons_mode[MODE_MULTI - 1] = construct_button_with_text("Multi", construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, button_y), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);

    page.button_back = construct_button_with_text("Retour", construct_position(50, WINDOW_HEIGHT - 100), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);
    page.button_validation = construct_button_with_text("Valider", construct_position(WINDOW_WIDTH - 50 - BUTTON_WIDTH, WINDOW_HEIGHT - 100), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);

    page.button_mode_selected = MODE_SOLO - 1;
    page.button_difficulty_selected = EASY;

    return page;
}

void draw_difficulty_menu_page(DifficultyMenu difficulty_menu, Position mouse_position)
{
    int i;
    for (i = 0; i < nb_difficulties; i++)
    {
        if (i == difficulty_menu.button_difficulty_selected)
        {
            draw_filled_rectangle(difficulty_menu.buttons_difficulty[i].position, difficulty_menu.buttons_difficulty[i].dimension, 2, MLV_rgba(6, 85, 102, 255), MLV_rgba(4, 80, 93, 200));
            draw_button_text(difficulty_menu.buttons_difficulty[i]);
        }
        else
        {
            draw_filled_button_with_hover_effect(difficulty_menu.buttons_difficulty[i], mouse_position, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150));
        }
    }

    for (i = 0; i < nb_modes - 1; i++)
    {

        if (i == difficulty_menu.button_mode_selected)
        {
            draw_filled_rectangle(difficulty_menu.buttons_mode[i].position, difficulty_menu.buttons_mode[i].dimension, 2, MLV_rgba(6, 85, 102, 255), MLV_rgba(4, 80, 93, 200));
            draw_button_text(difficulty_menu.buttons_mode[i]);
        }
        else
        {
            draw_filled_button_with_hover_effect(difficulty_menu.buttons_mode[i], mouse_position, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150));
        }
    }

    draw_filled_button_with_hover_effect(difficulty_menu.button_back, mouse_position, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150));
    draw_filled_button_with_hover_effect(difficulty_menu.button_validation, mouse_position, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150));
}