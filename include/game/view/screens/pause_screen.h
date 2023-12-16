#ifndef PAUSE_SCREEN_H
#define PAUSE_SCREEN_H

#include "../../../gui/shape/shape.h"
#include "../../../gui/button/button.h"
#include "../../../utils/text/text.h"

/**
 * @brief Structure représentant l'écran de pause du jeu.
 */
typedef struct
{
    Shape background_filter;     /**< Filtre de fond */
    Button resume_button;        /**< Bouton de reprise */
    Button quit_button;          /**< Bouton de quitter */
    Button save_and_quit_button; /**< Bouton de sauvegarde et quitter */
    Text title;                  /**< Titre */
} PauseScreen;

/**
 * @brief Initialise l'écran de pause
 *
 * @param pause_screen L'écran de pause
 */
PauseScreen construct_pause_screen();

/**
 * @brief Dessine l'écran de pause
 *
 * @param pause_screen L'écran de pause
 * @param mouse_position La position de la souris
 */
void draw_pause_screen(PauseScreen pause_screen, Position mouse_position);

/**
 * @brief Libère l'écran de pause
 *
 * @param pause_screen L'écran de pause
 */
void free_pause_screen(PauseScreen *pause_screen);

#endif