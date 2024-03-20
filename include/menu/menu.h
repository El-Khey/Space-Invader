#ifndef MENU_H
#define MENU_H

#include "./pages/main_menu_page.h"
#include "./pages/difficulty_menu_page.h"
#include "./pages/backup_menu_page.h"
#include "./pages/score_menu_page.h"

/**
 * @brief Type énuméré représentant les différents types de menus disponibles.
 */
typedef enum
{
    MAIN_MENU,       /**< Menu principal */
    DIFFICULTY_MENU, /**< Menu de difficulté */
    BEST_SCORE_MENU, /**< Menu des meilleurs scores */
    SAVE_MENU,       /**< Menu de sauvegarde */
    GAME_START       /**< Début du jeu */
} MenuType;

/**
 * @brief Structure représentant une page de menu.
 */
typedef struct
{
    MenuType type; /**< Type de menu */

    MainMenu main_menu;             /**< Menu principal */
    DifficultyMenu difficulty_menu; /**< Menu de difficulté */
    BackupMenu backup_menu;         /**< Menu de sauvegarde */
    ScoreMenu score_menu;           /**< Menu des meilleurs scores */

    Image background; /**< Image de fond */
    Text title;       /**< Titre du menu */

    int start_menu_time; /**< Temps de début du menu */
    int end_menu_time;   /**< Temps de fin du menu */
    int total_menu_time; /**< Temps total du menu */
    int elapsed_time;    /**< Temps écoulé */
} MenuPage;

/**
 * @brief Construit un nouvel objet Page de menu
 *
 * @return MenuPage
 */
MenuPage construct_menu_page(MenuType type);

/**
 * @brief Dessine la page de menu
 *
 * @param menu La page de menu à dessiner
 * @param mouse_position La position de la souris
 */
void draw_menu_page(MenuPage menu, Position mouse_position);

#endif
