#include "../../../include/menu/pages/main_menu_page.h"

#define BUTTON_WIDTH 450
#define BUTTON_HEIGHT 50

#define BUTTON_MARGIN_TOP 100
#define BUTTON_SPACING 20

MainMenu construct_main_menu_page()
{
    MainMenu page;

    int button_y = BUTTON_MARGIN_TOP + 200;

    MLV_Color foreground = MLV_COLOR_WHITE;
    MLV_Color background = MLV_rgba(12, 12, 17, 200);

    page.buttons[PLAY_BUTTON] = construct_button_with_text("Commencer une partie", construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, button_y), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);
    button_y += BUTTON_HEIGHT + BUTTON_SPACING;

    page.buttons[BEST_SCORE_BUTTON] = construct_button_with_text("Meilleurs scores", construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, button_y), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);
    button_y += BUTTON_HEIGHT + BUTTON_SPACING;

    page.buttons[SAVE_BUTTON] = construct_button_with_text("Partie sauvegardée", construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, button_y), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);
    button_y += BUTTON_HEIGHT + BUTTON_SPACING;

    page.buttons[QUIT_BUTTON] = construct_button_with_text("Quitter", construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, button_y), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);

    return page;
}

void draw_main_menu_page(MainMenu menu, Position mouse_position)
{
    int i = 0;
    for (; i < nb_buttons; i++)
    {
        draw_filled_button_with_hover_effect(menu.buttons[i], mouse_position, MLV_COLOR_WHITE, MLV_rgba(4, 80, 93, 155));
    }
}
