#include "../../../include/menu/controller/menu_controller.h"

/**
 * Gère les événements du menu principal.
 * @param menu Le pointeur vers la page de menu actuelle.
 * @param mouse_manager Le gestionnaire de souris.
 */
static void handle_main_menu_events(MenuPage *menu, MouseManager mouse_manager)
{
    /** Vérifie si le bouton "Jouer" a été cliqué */
    if (is_button_clicked(menu->main_menu.buttons[PLAY_BUTTON], mouse_manager))
    {
        menu->type = DIFFICULTY_MENU;
    }

    /** Vérifie si le bouton "Meilleur score" a été cliqué */
    if (is_button_clicked(menu->main_menu.buttons[BEST_SCORE_BUTTON], mouse_manager))
    {
        menu->type = BEST_SCORE_MENU;
    }

    /** Vérifie si le bouton "Sauvegarder" a été cliqué */
    if (is_button_clicked(menu->main_menu.buttons[SAVE_BUTTON], mouse_manager))
    {
        menu->type = SAVE_MENU;
    }

    /** Vérifie si le bouton "Quitter" a été cliqué */
    if (is_button_clicked(menu->main_menu.buttons[QUIT_BUTTON], mouse_manager))
    {
        exit(EXIT_SUCCESS);
    }
}

/**
 * Gère les événements du menu de difficulté.
 * @param menu Le pointeur vers la page de menu actuelle.
 * @param mouse_manager Le gestionnaire de souris.
 */
static void handle_difficulty_menu_events(MenuPage *menu, MouseManager mouse_manager)
{
    int i = 0;

    /** Vérifie si le bouton "Retour" a été cliqué */
    if (is_button_clicked(menu->difficulty_menu.button_back, mouse_manager))
    {
        menu->type = MAIN_MENU;
    }

    /** Vérifie si l'un des boutons de difficulté a été cliqué */
    for (; i < nb_difficulties; i++)
    {
        if (is_button_clicked(menu->difficulty_menu.buttons_difficulty[i], mouse_manager))
        {
            menu->difficulty_menu.button_difficulty_selected = i;
            break;
        }
    }

    /** Vérifie si l'un des boutons de mode a été cliqué */
    for (i = 0; i < nb_modes - 1; i++)
    {
        if (is_button_clicked(menu->difficulty_menu.buttons_mode[i], mouse_manager))
        {
            menu->difficulty_menu.button_mode_selected = i;
            break;
        }
    }

    /** Vérifie si le bouton de validation a été cliqué */
    if (is_button_clicked(menu->difficulty_menu.button_validation, mouse_manager))
    {
        menu->type = GAME_START;
    }
}

/**
 * Gère les événements du menu de sauvegarde.
 *
 * Cette fonction est responsable de la gestion des événements du menu de sauvegarde.
 * Elle vérifie si un bouton a été cliqué et effectue les actions correspondantes.
 * Si le bouton "Retour" est cliqué, le menu principal est affiché.
 * Si un bouton de sauvegarde est cliqué, l'index de la sauvegarde sélectionnée est mis à jour
 * et le jeu est démarré.
 *
 * @param menu Le pointeur vers la structure MenuPage représentant le menu actuel.
 * @param mouse_manager Le gestionnaire de souris utilisé pour détecter les clics de souris.
 */
static void handle_backup_menu_events(MenuPage *menu, MouseManager mouse_manager)
{
    int i = 0;
    if (is_button_clicked(menu->backup_menu.button_back, mouse_manager))
    {
        menu->type = MAIN_MENU;
        return;
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

/**
 * Gère les événements du menu des scores.
 *
 * Cette fonction est responsable de la gestion des événements du menu des scores.
 * Elle vérifie si le bouton "Retour" a été cliqué et met à jour le menu actuel en conséquence.
 *
 * @param menu Le pointeur vers la structure MenuPage représentant le menu actuel.
 * @param mouse_manager Le gestionnaire de souris utilisé pour détecter les clics de souris.
 */
static void handle_score_menu_events(MenuPage *menu, MouseManager mouse_manager)
{
    if (is_button_clicked(menu->score_menu.button_back, mouse_manager))
    {
        menu->type = MAIN_MENU;
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

    case BEST_SCORE_MENU:
        handle_score_menu_events(menu_page, mouse_manager);
        break;

    default:
        fprintf(stderr, "Unknown menu type : %d\n", menu_page->type);
        break;
    }
}