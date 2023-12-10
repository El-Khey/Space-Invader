#include "../../../include/menu/controller/menu_controller.h"

static void handle_main_menu_events(MenuPage *menu, MouseManager mouse_manager)
{
    if (is_button_clicked(menu->main_menu.buttons[PLAY_BUTTON], mouse_manager))
    {
        menu->type = DIFFICULTY_MENU;
    }

    if (is_button_clicked(menu->main_menu.buttons[BEST_SCORE_BUTTON], mouse_manager))
    {
        menu->type = BEST_SCORE_MENU;
    }

    if (is_button_clicked(menu->main_menu.buttons[SAVE_BUTTON], mouse_manager))
    {
        menu->type = SAVE_MENU;
    }

    if (is_button_clicked(menu->main_menu.buttons[QUIT_BUTTON], mouse_manager))
    {
        exit(EXIT_SUCCESS);
    }
}

static void handle_difficulty_menu_events(MenuPage *menu, MouseManager mouse_manager)
{
    int i = 0;
    if (is_button_clicked(menu->difficulty_menu.button_back, mouse_manager))
    {
        menu->type = MAIN_MENU;
    }

    for (; i < nb_difficulties; i++)
    {
        if (is_button_clicked(menu->difficulty_menu.buttons_difficulty[i], mouse_manager))
        {
            menu->difficulty_menu.button_difficulty_selected = i;
            break;
        }
    }

    for (i = 0; i < nb_modes - 1; i++)
    {
        if (is_button_clicked(menu->difficulty_menu.buttons_mode[i], mouse_manager))
        {
            menu->difficulty_menu.button_mode_selected = i;
            break;
        }
    }

    if (is_button_clicked(menu->difficulty_menu.button_validation, mouse_manager))
    {
        menu->type = GAME_START;
    }
}

static void handle_backup_menu_events(MenuPage *menu, MouseManager mouse_manager)
{
    int i = 0;
    if (is_button_clicked(menu->backup_menu.button_back, mouse_manager))
    {
        menu->type = MAIN_MENU;
    }

    for (; i < menu->backup_menu.backups_count; i++)
    {
        if (is_button_clicked(menu->backup_menu.backup_buttons[i], mouse_manager))
        {
            menu->backup_menu.selected_backup_slot_index = i;
            menu->type = GAME_START;

            break;
        }
    }
}

void handle_menu_events(MenuPage *menu_page, MouseManager mouse_manager)
{
    switch (menu_page->type)
    {
    case MAIN_MENU:
        handle_main_menu_events(menu_page, mouse_manager);
        break;

    case DIFFICULTY_MENU:
        handle_difficulty_menu_events(menu_page, mouse_manager);
        break;

    case SAVE_MENU:
        handle_backup_menu_events(menu_page, mouse_manager);
        break;
    default:
        break;
    }
}