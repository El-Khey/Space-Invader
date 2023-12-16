#ifndef COLLISION_CONTROLLER_H
#define COLLISION_CONTROLLER_H

#include "../../controller/asteroid_controller/asteroid_controller.h"
#include "../../controller/bonus_controller/bonus_controller.h"
#include "../enemy_controller.h"

/**
 * Gère les collisions avec le héros.
 *
 * Cette fonction est responsable de la gestion des collisions entre le héros et les différents éléments du jeu, tels que les ennemis, les bonus et les astéroïdes.
 *
 * @param players Le pointeur vers la structure Players contenant les informations sur les joueurs.
 * @param enemy_controller Le pointeur vers la structure enemy_controller contenant les informations sur les ennemis.
 * @param bonus_controller Le pointeur vers la structure bonus_controller contenant les informations sur les bonus.
 * @param asteroid_controller Le pointeur vers la structure asteroid_controller contenant les informations sur les astéroïdes.
 */
void handle_heros_collision(Players *players, enemy_controller *enemy_controller, bonus_controller *bonus_controller, asteroid_controller *asteroid_controller);

#endif
