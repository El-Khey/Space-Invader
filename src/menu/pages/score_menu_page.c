#include "../../../include/menu/pages/score_menu_page.h"
#include "../../../include/game/manager/game_manager/backup_manager.h"

#define BUTTON_WIDTH 850
#define BUTTON_HEIGHT 42

ScoreMenu construct_score_menu_page(BackupManager backup_manager)
{
    ScoreMenu page;
    int button_count, button_y;
    int i = 0;

    MLV_Color foreground = MLV_COLOR_WHITE;
    MLV_Color background = MLV_rgba(12, 12, 17, 200);

    page.button_back = construct_button_with_text("Retour", construct_position(50, WINDOW_HEIGHT - 100), construct_dimension(220, BUTTON_HEIGHT), foreground, background);

    button_count = backup_manager.best_score_list.best_scores_count > 10 ? 10 : backup_manager.best_score_list.best_scores_count;
    button_y = (WINDOW_HEIGHT - (button_count * (BUTTON_HEIGHT + 20))) / 2 + 95;

    for (; i < button_count; i++)
    {
        char slot_name[350];
        sprintf(slot_name, "%s : %d - %s", backup_manager.best_score_list.best_scores[i].name, backup_manager.best_score_list.best_scores[i].score, convert_timestamp(backup_manager.best_score_list.best_scores[i].timestamp));
        page.best_scores_buttons[i] = construct_button_with_text(slot_name, construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, button_y + i * (BUTTON_HEIGHT + 7)), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);
        page.best_scores_buttons[i].text.font_size = 15;
    }

    page.best_scores_count = backup_manager.best_score_list.best_scores_count;
    return page;
}

void draw_score_menu_page(ScoreMenu score_menu, Position mouse_position)
{
    int i = 0;

    for (; i < score_menu.best_scores_count; i++)
    {
        draw_filled_button_with_hover_effect(score_menu.best_scores_buttons[i], mouse_position, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150));
    }

    draw_filled_button_with_hover_effect(score_menu.button_back, mouse_position, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150));
}
