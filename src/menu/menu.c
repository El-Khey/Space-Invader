#include "../../include/menu/menu.h"

MenuPage construct_menu_page(MenuType type)
{
    MenuPage menu;

    menu.type = type;
    menu.background = load_image("assets/background/menu_1.jpg", construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT));

    menu.title = construct_text("Space Invader", construct_position(WINDOW_WIDTH / 2, 50), "assets/fonts/Play-Bold.ttf", 100, MLV_COLOR_WHITE);
    set_text_position(&menu.title, construct_position(get_x(menu.title.position) - get_text_width(menu.title) / 2, get_y(menu.title.position)));

    menu.main_menu = construct_main_menu_page();
    menu.difficulty_menu = construct_difficulty_menu_page();
    menu.score_menu = construct_score_menu_page();

    menu.elapsed_time = 0;
    menu.start_menu_time = 0;
    menu.end_menu_time = 0;
    menu.total_menu_time = 0;

    return menu;
}

void draw_menu_page(MenuPage menu, Position mouse_position)
{
    draw_image(&menu.background);
    draw_text_with_shadow(menu.title, 5);

    switch (menu.type)
    {
    case MAIN_MENU:
        draw_main_menu_page(menu.main_menu, mouse_position);
        break;

    case DIFFICULTY_MENU:
        draw_difficulty_menu_page(menu.difficulty_menu, mouse_position);
        break;

    case SAVE_MENU:
        draw_backup_menu_page(menu.backup_menu, mouse_position);
        break;

    case BEST_SCORE_MENU:
        draw_score_menu_page(menu.score_menu, mouse_position);
        break;

    default:
        printf("Unknown menu type\n");
        break;
    }
}