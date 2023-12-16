#ifndef BACKUP_MENU_PAGE_H
#define BACKUP_MENU_PAGE_H

#include "../../utils/text/text.h"
#include "../../gui/button/button.h"
#include "../../utils/utils.h"

#include "../../game/manager/game_manager/backup_manager.h"

#define MAX_BACKUP_BUTTONS 10

/**
 * @brief Structure représentant la page de menu de sauvegarde.
 */
typedef struct
{
    Button backup_buttons[MAX_BACKUP_BUTTONS]; /** Tableau de boutons de sauvegarde */
    Button button_back;                        /** Bouton de retour */

    int selected_backup_slot_index; /** Index de la sauvegarde sélectionnée */
    int backups_count;              /** Nombre de sauvegardes */
} BackupMenu;

/**
 * @brief Construit une page de menu de sauvegarde.
 *
 * @param backup_manager Le gestionnaire de sauvegarde.
 * @return BackupMenu La page de menu de sauvegarde construite.
 */
BackupMenu construct_backup_menu_page(BackupManager backup_manager);

/**
 * @brief Dessine la page de menu de sauvegarde.
 *
 * @param backup_menu La page de menu de sauvegarde à dessiner.
 * @param mouse_position La position de la souris.
 */
void draw_backup_menu_page(BackupMenu backup_menu, Position mouse_position);

#endif
