#ifndef BONUS_CONTROLLER_H
#define BONUS_CONTROLLER_H

#include "../../manager/event_manager/event_manager.h"
#include "../projectile_controller/projectile_controller.h"
#include "../../model/bonus/bonus.h"
#include "../../../utils/utils.h"
#include "../../model/heros.h"

#define MAX_BONUS_SPAWN_COUNT 5

typedef struct
{
    Bonus bonus[MAX_BONUS_SPAWN_COUNT]; /** La liste des bonus */

    int bonus_spawn_count; /** Le nombre de bonus à générer */
    int bonus_spawned;     /** Le nombre de bonus générés */

    int last_bonus_spawn_time; /** Le dernier moment où un bonus a été généré */
    int delay_between_spawn;   /** Le délai entre chaque génération de bonus */
} bonus_controller;

/**
 * @brief Cette fonction est responsable de la génération des bonus,
 * elle gère la fréquence de génération et le nombre de bonus à générer.
 *
 * @return bonus_controller
 */
bonus_controller construct_bonus_controller();

/**
 * @brief Cette fonction est responsable de la génération des bonus,
 * elle génère les bonus et les ajoute au bonus_controller si les conditions
 * de délai et de nombre de bonus à générer sont remplies.
 *
 * @param controller Le bonus_controller
 * @param event_manager Le event_manager
 * @param heros Le heros
 * @param projectile_controller Le projectile_controller
 */
void generate_bonus(bonus_controller *controller);

/**
 * @brief Cette fonction gère le mouvement et la destruction des bonus,
 * ainsi que l'animation de destruction des bonus.
 *
 * @param controller Le bonus_controller
 */
void update_bonus(bonus_controller *controller);

/**
 * @brief Cette fonction libère la mémoire allouée pour le bonus_controller.
 *
 * @param controller Le bonus_controller
 */
void free_bonus_controller(bonus_controller *controller);

#endif