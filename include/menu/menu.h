#ifndef MENU_H
#define MENU_H

#include "./pages/main_menu_page.h"
#include "./pages/difficulty_menu_page.h"
#include "./pages/backup_menu_page.h"

typedef enum
{
    MAIN_MENU,
    DIFFICULTY_MENU,
    BEST_SCORE_MENU,
    SAVE_MENU,
    GAME_START
} MenuType;

typedef struct
{
    MenuType type;

    MainMenu main_menu;
    DifficultyMenu difficulty_menu;
    BackupMenu backup_menu;

    Image background;
    Text title;
} MenuPage;

/**
 * @brief Construct a new Menu Page object
 *
 * @return MenuPage
 */
MenuPage construct_menu_page(MenuType type);

/**
 * @brief Draw the menu page
 *
 * @param menu The menu page to draw
 * @param mouse_position The mouse position
 */
void draw_menu_page(MenuPage menu, Position mouse_position);

#endif
