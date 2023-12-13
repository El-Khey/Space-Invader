#ifndef SCORE_MENU_PAGE_H
#define SCORE_MENU_PAGE_H

#include "../../utils/text/text.h"
#include "../../gui/button/button.h"
#include "../../utils/utils.h"

#define TEXT_LENGTH_MAX 20
#define BEST_SCORES 10
typedef struct
{
    Button button_back;
    char title[TEXT_LENGTH_MAX];
    int backups_count;
} ScoreMenu;

/**
 * @brief Construct a new Score Menu Page object
 *
 * @return ScoreMenu
 */
ScoreMenu construct_score_menu_page();

/**
 * @brief Draw the score menu page
 *
 * @param score_menu The score menu page to draw
 * @param mouse_position The mouse position
 */

void draw_score_menu_page(ScoreMenu score_menu, Position mouse_position);

#endif