#include "../../../include/menu/pages/score_menu_page.h"

#define BUTTON_WIDTH 850
#define BUTTON_HEIGHT 42

ScoreMenu construct_score_menu_page()
{
    ScoreMenu score_menu;

    MLV_Color foreground = MLV_COLOR_WHITE;
    MLV_Color background = MLV_rgba(12, 12, 17, 200);

    score_menu.button_back = construct_button_with_text("Retour", construct_position(50, WINDOW_HEIGHT - 100), construct_dimension(220, BUTTON_HEIGHT), foreground, background);

    return score_menu;
}

void draw_score_menu_page(ScoreMenu score_menu, Position mouse_position)
{
    /**
       int i = 0;

        for (; i < backup_menu.backups_count; i++)
        {
            if (i == backup_menu.selected_backup_slot_index)
            {
                draw_filled_rectangle(backup_menu.backup_buttons[i].position, backup_menu.backup_buttons[i].dimension, 2, MLV_rgba(6, 85, 102, 255), MLV_rgba(4, 80, 93, 200));
                draw_button_text(backup_menu.backup_buttons[i]);
            }
            else
            {
                draw_filled_button_with_hover_effect(backup_menu.backup_buttons[i], mouse_position, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150));
            }
        }
     */

    draw_filled_button_with_hover_effect(score_menu.button_back, mouse_position, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150));
}
