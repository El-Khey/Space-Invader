#ifndef HEROS_CONTROLLER_H
#define HEROS_CONTROLLER_H

#include "../manager/event_manager/event_manager.h"
#include "./projectile_controller/projectile_controller.h"

#include "../model/heros.h"
#include "../../utils/utils.h"

/**
 * Met à jour les informations du héros.
 * Cette fonction est appelée à chaque itération de la boucle de jeu pour mettre à jour la position et l'état du héros.
 *
 * @param delta Temps écoulé depuis la dernière mise à jour, en secondes.
 */
void update_heros(Heros *heros, EventManager event_manager);

/**
 * Déplace le héros vers le haut.
 *
 * @param heros Le pointeur vers l'objet Heros à déplacer.
 */
void move_heros_up(Heros *heros);

/**
 * Déplace le héros vers le bas.
 *
 * @param heros Le pointeur vers l'objet Heros à déplacer.
 */
void move_heros_down(Heros *heros);

/**
 * Déplace le héros vers la gauche.
 *
 * @param heros Le pointeur vers l'objet Heros à déplacer.
 */
void move_heros_left(Heros *heros);

/**
 * Déplace le héros vers la droite.
 *
 * @param heros Le pointeur vers l'objet Heros à déplacer.
 */
void move_heros_right(Heros *heros);

#endif