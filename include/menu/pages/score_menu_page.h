#ifndef SCORE_MENU_PAGE_H
#define SCORE_MENU_PAGE_H

#include "../../game/manager/game_manager/backup_manager.h"

#include "../../utils/text/text.h"
#include "../../gui/button/button.h"
#include "../../utils/utils.h"

#define MAX_BACKUP_BUTTONS 10
#define TEXT_LENGTH_MAX 20
#define BEST_SCORES 10

typedef struct
{
    Button button_back;
    Button best_scores_buttons[MAX_BACKUP_BUTTONS];
    int best_scores_count;
} ScoreMenu;

/**
 * @brief Construct a new Score Menu Page object
 *
 * @return ScoreMenu
 */
ScoreMenu construct_score_menu_page(BackupManager backup_manager);

/**
 * @brief Draw the score menu page
 *
 * @param score_menu The score menu page to draw
 * @param mouse_position The mouse position
 */

void draw_score_menu_page(ScoreMenu score_menu, Position mouse_position);

#endif