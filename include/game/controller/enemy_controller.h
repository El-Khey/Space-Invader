#ifndef ENEMY_CONTROLLER_H
#define ENEMY_CONTROLLER_H

#include "./projectile_controller/projectile_controller.h"
#include "../manager/event_manager/event_manager.h"
#include "../model/enemy/enemy.h"
#include "../../utils/utils.h"
#include "../model/player.h"

#define MAX_ENEMY_SPAWN_COUNT 3

/**
 * @struct enemy_controller
 * @brief Structure représentant le contrôleur des ennemis.
 */
typedef struct
{
    Enemy enemies[MAX_ENEMY_SPAWN_COUNT]; /** La liste des ennemis */

    int enemy_spawn_count; /** Le nombre d'ennemis à générer */
    int enemy_spawned;     /** Le nombre d'ennemis générés */

    int last_enemy_spawn_time; /** Le dernier moment où un ennemi a été généré */
    int delay_between_spawn;   /** Le délai entre chaque génération d'ennemi */
} enemy_controller;

/**
 * @brief Construit et retourne un contrôleur d'ennemis initialisé.
 * @return Le contrôleur d'ennemis initialisé.
 */
enemy_controller construct_enemy_controller();

/**
 * @brief Génère les ennemis en fonction du contrôleur donné.
 * @param controller Le contrôleur d'ennemis.
 */
void generate_enemies(enemy_controller *controller);

/**
 * @brief Met à jour les ennemis en fonction du contrôleur et des joueurs donnés.
 * @param controller Le contrôleur d'ennemis.
 * @param players Les joueurs.
 */
void update_enemies(enemy_controller *controller, Players *players);

/**
 * @brief Libère la mémoire allouée pour le contrôleur d'ennemis.
 * @param controller Le contrôleur d'ennemis à libérer.
 */
void free_enemy_controller(enemy_controller *controller);

#endif