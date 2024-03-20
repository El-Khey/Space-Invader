#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "../../gui/button/button.h"
#include "../../utils/image/image.h"
#include "../../gui/shape/shape.h"

/**
 * @brief Énumération des boutons du menu principal.
 */
typedef enum
{
    PLAY_BUTTON,       /**< Bouton "Jouer" */
    BEST_SCORE_BUTTON, /**< Bouton "Meilleur score" */
    SAVE_BUTTON,       /**< Bouton "Sauvegarder" */
    QUIT_BUTTON,       /**< Bouton "Quitter" */
    nb_buttons         /**< Nombre total de boutons */
} MainMenuButton;

/**
 * @brief Structure représentant le menu principal.
 */
typedef struct
{
    Button buttons[nb_buttons]; /**< Tableau des boutons du menu */
} MainMenu;

/**
 * @brief Construit une instance de la page du menu principal.
 *
 * @return L'instance du menu principal construite.
 */
MainMenu construct_main_menu_page();

/**
 * @brief Dessine la page du menu principal.
 *
 * @param menu L'instance du menu principal à dessiner.
 * @param mouse_position La position de la souris.
 */
void draw_main_menu_page(MainMenu menu, Position mouse_position);

#endif