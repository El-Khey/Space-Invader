
#include "../../../include/game/manager/game_manager/backup_manager.h"
#include "../../../include/menu/pages/backup_menu_page.h"

#define BUTTON_WIDTH 450
#define BUTTON_HEIGHT 50

BackupMenu construct_backup_menu_page(BackupManager backup_manager)
{
    BackupMenu page;
    int i = 0;
    MLV_Color foreground = MLV_COLOR_WHITE;
    MLV_Color background = MLV_rgba(12, 12, 17, 200);

    page.button_back = construct_button_with_text("Retour", construct_position(50, WINDOW_HEIGHT - 100), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);
    page.selected_backup_slot_index = -1;

    for (; i < backup_manager.backups_count; i++)
    {
        char slot_name[50];
        sprintf(slot_name, "-Slot %d- %s", i, convert_timestamp(backup_manager.backups[i].timestamp));
        page.backup_buttons[i] = construct_button_with_text(slot_name, construct_position(WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, 250 + i * (BUTTON_HEIGHT + 20)), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), foreground, background);
    }

    page.backups_count = backup_manager.backups_count;
    return page;
}

void draw_backup_menu_page(BackupMenu backup_menu, Position mouse_position)
{
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

    draw_filled_button_with_hover_effect(backup_menu.button_back, mouse_position, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150));
}