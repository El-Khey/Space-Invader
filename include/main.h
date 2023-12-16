#ifndef MAIN_H
#define MAIN_H

/**
 * TODO : Tester si on peut enlever ça sur les machines de la fac
 */
#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <MLV/MLV_all.h>

#define WINDOW_WIDTH 1400 /**< Largeur de la fenêtre du jeu. */
#define WINDOW_HEIGHT 800 /**< Hauteur de la fenêtre du jeu. */

#define MAX_PLAYER_LIFE 7 /**< Nombre maximum de vies pour le joueur. */
#define MAX_PLAYERS 2     /**< Nombre maximum de joueurs. */

#define PRIMARY_GRAY_COLOR MLV_rgba(75, 75, 75, 255)  /**< Couleur grise primaire utilisée dans le jeu. */
#define PRIMARY_RED_COLOR MLV_rgba(255, 41, 41, 255)  /**< Couleur rouge primaire utilisée dans le jeu. */
#define PRIMARY_BLUE_COLOR MLV_rgba(50, 89, 255, 255) /**< Couleur bleue primaire utilisée dans le jeu. */

#endif