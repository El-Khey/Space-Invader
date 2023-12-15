#ifndef BACKUP_MENU_PAGE_H
#define BACKUP_MENU_PAGE_H

#include "../../utils/text/text.h"
#include "../../gui/button/button.h"
#include "../../utils/utils.h"

#include "../../game/manager/game_manager/backup_manager.h"

#define MAX_BACKUP_BUTTONS 10

typedef struct
{
    Button backup_buttons[MAX_BACKUP_BUTTONS];
    Button button_back;

    int selected_backup_slot_index;
    int backups_count;
} BackupMenu;

BackupMenu construct_backup_menu_page(BackupManager backup_manager);

void draw_backup_menu_page(BackupMenu backup_menu, Position mouse_position);

#endif
