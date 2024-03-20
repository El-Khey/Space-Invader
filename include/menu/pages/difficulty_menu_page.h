#ifndef DIFFICULTY_MENU_PAGE_H
#define DIFFICULTY_MENU_PAGE_H

#include "../../gui/button/button.h"
#include "../../utils/image/image.h"
#include "../../gui/shape/shape.h"
#include "../../game/manager/game_manager/game_details.h"

/**
 * @struct DifficultyMenu
 * @brief Représente la page de menu de sélection de difficulté.
 *
 * Cette structure contient les boutons de sélection de difficulté et de mode,
 * ainsi que les boutons de retour et de validation.
 */
typedef struct
{
    Button buttons_difficulty[nb_difficulties]; /**< Les boutons de sélection de difficulté */
    int button_difficulty_selected;             /**< L'index du bouton de difficulté sélectionné */

    Button buttons_mode[nb_modes - 1]; /**< Les boutons de sélection de mode */
    int button_mode_selected;          /**< L'index du bouton de mode sélectionné */

    Button button_back;       /**< Le bouton de retour */
    Button button_validation; /**< Le bouton de validation */
} DifficultyMenu;

/**
 * @brief Construit une page de menu de difficulté.
 *
 * @return La page de menu de difficulté construite.
 */
DifficultyMenu construct_difficulty_menu_page();

/**
 * @brief Dessine la page de menu de difficulté.
 *
 * @param difficulty_menu La page de menu de difficulté à dessiner.
 * @param mouse_position La position de la souris.
 */
void draw_difficulty_menu_page(DifficultyMenu difficulty_menu, Position mouse_position);

#endif