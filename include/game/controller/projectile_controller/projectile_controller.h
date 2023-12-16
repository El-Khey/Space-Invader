#ifndef PROJECTILE_CONTROLLER_H
#define PROJECTILE_CONTROLLER_H

#include "../../model/projectile.h"
#include "../../../utils/utils.h"

/**
 * @brief Met à jour les projectiles dans la liste donnée.
 *
 * Cette fonction met à jour la position et l'état de chaque projectile dans la liste.
 *
 * @param list La liste de projectiles à mettre à jour.
 */
void update_projectiles(Projectiles *list);

#endif