#include "../../../../include/game/view/screens/pause_screen.h"
#include "../../../../include/main.h"

#define BUTTON_WIDTH 500
#define BUTTON_HEIGHT 50

#define BUTTON_COLOR MLV_rgba(39, 24, 17, 255)
#define BUTTON_HOVER_COLOR MLV_rgba(12, 12, 17, 200)

PauseScreen construct_pause_screen()
{
    PauseScreen pause_screen;

    pause_screen.background_filter = construct_rectangle(construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT), MLV_rgba(125, 125, 125, 5));
    pause_screen.resume_button = construct_button_with_text(
        "Reprendre",
        construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, WINDOW_HEIGHT / 2 - 75 - BUTTON_HEIGHT / 2),
        construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), MLV_COLOR_WHITE, BUTTON_HOVER_COLOR);

    pause_screen.save_and_quit_button = construct_button_with_text(
        "Sauvegarder et quitter",
        construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, WINDOW_HEIGHT / 2 - 75 - BUTTON_HEIGHT / 2 + BUTTON_HEIGHT + 10),
        construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), MLV_COLOR_WHITE, BUTTON_HOVER_COLOR);

    pause_screen.quit_button = construct_button_with_text(
        "Quitter sans sauvegarder",
        construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, WINDOW_HEIGHT / 2 - 75 - BUTTON_HEIGHT / 2 + 2 * (BUTTON_HEIGHT + 10)),
        construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), MLV_COLOR_WHITE, BUTTON_HOVER_COLOR);

    pause_screen.title = construct_text(
        "Pause",
        construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, WINDOW_HEIGHT / 2 - 75 - BUTTON_HEIGHT / 2 - 50),
        "assets/fonts/Play-Bold.ttf",
        42,
        MLV_COLOR_WHITE);

    set_text_position(&pause_screen.title, construct_position(WINDOW_WIDTH / 2 - get_text_width(pause_screen.title) / 2, WINDOW_HEIGHT / 2 - 75 - get_text_height(pause_screen.title) / 2 - BUTTON_HEIGHT - 10));

    return pause_screen;
}

void draw_pause_screen(PauseScreen pause_screen, Position mouse_position)
{
    draw_rectangle(pause_screen.background_filter);
    draw_text(pause_screen.title);

    draw_filled_button_with_hover_effect(pause_screen.resume_button, mouse_position, MLV_COLOR_WHITE, PRIMARY_GRAY_COLOR);
    draw_filled_button_with_hover_effect(pause_screen.save_and_quit_button, mouse_position, MLV_COLOR_WHITE, PRIMARY_GRAY_COLOR);
    draw_filled_button_with_hover_effect(pause_screen.quit_button, mouse_position, MLV_COLOR_WHITE, PRIMARY_GRAY_COLOR);
}
