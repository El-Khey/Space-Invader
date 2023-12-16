#ifndef FRAME_RATE_H
#define FRAME_RATE_H

#include "../../main.h"

/**
 * @brief Structure représentant le taux de rafraîchissement de l'image.
 */
typedef struct
{
    int fps;   /**< Le nombre d'images par seconde. */
    int delay; /**< Le délai en millisecondes entre chaque image. */

    struct timespec start_time; /**< Le temps de début du rafraîchissement. */
    struct timespec end_time;   /**< Le temps de fin du rafraîchissement. */
} FrameRate;

/**
 * @brief Construit un objet FrameRate avec le taux de rafraîchissement spécifié.
 *
 * @param fps Le nombre d'images par seconde.
 * @return FrameRate L'objet FrameRate construit.
 */
FrameRate construct_frame_rate(int fps);

/**
 * @brief Définit le taux de rafraîchissement de l'objet FrameRate.
 *
 * @param frame_rate L'objet FrameRate à modifier.
 * @param fps Le nombre d'images par seconde.
 */
void set_frame_rate(FrameRate *frame_rate, int fps);

/**
 * @brief Définit le temps de démarrage du taux de rafraîchissement de l'objet FrameRate.
 *
 * @param frame_rate L'objet FrameRate à modifier.
 */
void set_frame_rate_start_time(FrameRate *frame_rate);

/**
 * @brief Effectue une pause pour respecter le taux de rafraîchissement de l'objet FrameRate.
 *
 * @param frame_rate L'objet FrameRate contenant le taux de rafraîchissement.
 */
void delay_according_to_frame_rate(FrameRate *frame_rate);

#endif