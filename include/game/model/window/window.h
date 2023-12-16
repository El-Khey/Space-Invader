#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#include "../../../utils/dimension/dimension.h"
#include "../../../utils/position/position.h"
#include "../../../utils/image/image.h"
#include "../../../utils/animation/animation.h"

#define NUMBER_OF_BACKGROUNDS 2
/**
 * @brief Structure représentant un arrière-plan animé.
 */
typedef struct
{
    Position layers_position; /**< Position des couches de l'arrière-plan. */
    Animation layer_01_void;  /**< Animation de la première couche. */
    Animation layer_02_stars; /**< Animation de la deuxième couche d'étoiles. */
    Animation layer_03_stars; /**< Animation de la troisième couche d'étoiles. */
} AnimatedBackground;

/**
 * @struct Window
 * @brief Représente la fenêtre du jeu.
 *
 * Cette structure contient les informations relatives à la fenêtre du jeu, telles que sa dimension, sa position,
 * les fonds d'écran animés, le temps écoulé, le temps de pause, le temps de fin de partie, etc.
 */
typedef struct
{
    Dimension dimension; /**< La dimension de la fenêtre */
    Position position;   /**< La position de la fenêtre */

    AnimatedBackground animated_backgrounds[NUMBER_OF_BACKGROUNDS]; /**< Les fonds d'écran animés */

    int elapsed_time; /**< Le temps écoulé */

    int start_pause_time; /**< Le temps de début de pause */
    int end_pause_time;   /**< Le temps de fin de pause */
    int total_pause_time; /**< Le temps total de pause */

    int start_game_over_time; /**< Le temps de début de fin de partie */
    int end_game_over_time;   /**< Le temps de fin de fin de partie */
    int total_game_over_time; /**< Le temps total de fin de partie */
} Window;
/**
 * @brief Construit une nouvelle fenêtre.
 *
 * Cette fonction construit et retourne une nouvelle fenêtre.
 *
 * @return La fenêtre construite.
 */
Window construct_window();

/**
 * @brief Met à jour la position de l'arrière-plan de la fenêtre.
 *
 * Cette fonction met à jour la position de l'arrière-plan de la fenêtre en fonction du déplacement du joueur.
 *
 * @param window La fenêtre à mettre à jour.
 */
void update_background_position(Window *window);

/**
 * @brief Charge la sauvegarde de la fenêtre.
 *
 * Cette fonction est utilisée pour charger l'animation de la fenêtre lorsque le jeu est démarré à partir d'une sauvegarde.
 *
 * @param window La fenêtre.
 */
void load_window_backup(Window *window);

/**
 * @brief Libère la mémoire occupée par la fenêtre.
 *
 * Cette fonction libère la mémoire occupée par la fenêtre spécifiée.
 *
 * @param window La fenêtre à libérer.
 */
void free_window(Window *window);

#endif