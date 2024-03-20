#ifndef GAME_OVER_SCREEN_H
#define GAME_OVER_SCREEN_H

#include "../../../gui/shape/shape.h"
#include "../../../gui/button/button.h"
#include "../../../utils/text/text.h"

/**
 * @struct GameOverScreen
 * @brief Représente l'écran de fin de partie.
 *
 * Cette structure contient les éléments graphiques nécessaires pour afficher l'écran de fin de partie.
 * Elle comprend un filtre de fond, des boutons de redémarrage et de retour au menu, ainsi qu'un titre.
 */
typedef struct
{
    Shape background_filter;    /**< Le filtre de fond de l'écran de fin de partie. */
    Button restart_button;      /**< Le bouton de redémarrage de la partie. */
    Button back_to_menu_button; /**< Le bouton de retour au menu principal. */
    Text title;                 /**< Le titre de l'écran de fin de partie. */
} GameOverScreen;

/**
 * @brief Construit un nouvel objet d'écran de fin de jeu.
 *
 * @param game_over_screen L'écran de fin de jeu
 */
GameOverScreen construct_game_over_screen();

/**
 * @brief Dessine l'écran de fin de jeu.
 *
 * @param game_over_screen L'écran de fin de jeu
 * @param mouse_position La position de la souris
 */
void draw_game_over_screen(GameOverScreen game_over_screen, Position mouse_position);

/**
 * @brief Libère la mémoire allouée pour l'écran de fin de jeu.
 *
 * @param game_over_screen L'écran de fin de jeu
 */
void free_game_over_screen(GameOverScreen *game_over_screen);

#endif