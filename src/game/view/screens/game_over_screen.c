#include "../../../../include/game/view/screens/game_over_screen.h"

#define BUTTON_WIDTH 500
#define BUTTON_HEIGHT 50

#define BUTTON_COLOR MLV_rgba(39, 24, 17, 255)
#define BUTTON_HOVER_COLOR MLV_rgba(12, 12, 17, 200)

GameOverScreen construct_game_over_screen()
{
    GameOverScreen game_over_screen;
    game_over_screen.background_filter = construct_rectangle(construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT), MLV_rgba(125, 125, 125, 5));
    game_over_screen.restart_button = construct_button_with_text(
        "Recommencer",
        construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, WINDOW_HEIGHT / 2 - 75 - BUTTON_HEIGHT / 2),
        construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), MLV_COLOR_WHITE, BUTTON_HOVER_COLOR);

    game_over_screen.back_to_menu_button = construct_button_with_text(
        "Retourner au menu",
        construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, WINDOW_HEIGHT / 2 - 75 - BUTTON_HEIGHT / 2 + BUTTON_HEIGHT + 10),
        construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), MLV_COLOR_WHITE, BUTTON_HOVER_COLOR);

    game_over_screen.title = construct_text(
        "Game Over",
        construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, WINDOW_HEIGHT / 2 - 75 - BUTTON_HEIGHT / 2 - 50),
        "assets/fonts/Play-Bold.ttf",
        42,
        MLV_COLOR_WHITE);

    set_text_position(&game_over_screen.title, construct_position(WINDOW_WIDTH / 2 - get_text_width(game_over_screen.title) / 2, WINDOW_HEIGHT / 2 - 75 - get_text_height(game_over_screen.title) / 2 - BUTTON_HEIGHT - 10));

    return game_over_screen;
}

void draw_game_over_screen(GameOverScreen game_over_screen, Position mouse_position)
{
    draw_rectangle(game_over_screen.background_filter);
    draw_text(game_over_screen.title);

    draw_filled_button_with_hover_effect(game_over_screen.restart_button, mouse_position, MLV_COLOR_WHITE, PRIMARY_GRAY_COLOR);
    draw_filled_button_with_hover_effect(game_over_screen.back_to_menu_button, mouse_position, MLV_COLOR_WHITE, PRIMARY_GRAY_COLOR);
}

void free_game_over_screen(GameOverScreen *game_over_screen)
{
    free_button_text(&game_over_screen->back_to_menu_button);
    free_button_text(&game_over_screen->restart_button);
    free_text(&game_over_screen->title);
}