#ifndef ASTEROID_CONTROLLER_H
#define ASTEROID_CONTROLLER_H

#include "../../manager/event_manager/event_manager.h"
#include "../projectile_controller/projectile_controller.h"
#include "../../model/asteroid/asteroid.h"
#include "../../model/heros.h"
#include "../../../utils/utils.h"

#define MAX_ASTEROID_SPAWN_COUNT 2

/**
 * @brief Structure représentant le contrôleur des astéroïdes.
 */
typedef struct
{
    Asteroid asteroids[MAX_ASTEROID_SPAWN_COUNT]; /** La liste des astéroïdes */

    int asteroid_spawn_count; /** Le nombre d'astéroïdes à générer */
    int asteroid_spawned;     /** Le nombre d'astéroïdes générés */

    int last_asteroid_spawn_time; /** Le dernier moment où un astéroïde a été généré */
    int delay_between_spawn;      /** Le délai entre chaque génération d'astéroïde */
} asteroid_controller;

/**
 * @brief Cette fonction est responsable de la génération des astéroïdes,
 * elle gère la fréquence de génération et le nombre d'astéroïdes à générer.
 *
 * @return asteroid_controller
 */
asteroid_controller construct_asteroid_controller();

/**
 * @brief Cette fonction est responsable de la génération des astéroïdes,
 * elle génère les astéroïdes et les ajoute au contrôleur d'astéroïdes si les conditions de
 * délai et de nombre d'astéroïdes à générer sont remplies.
 *
 * @param controller Le contrôleur d'astéroïdes
 * @param event_manager Le gestionnaire d'événements
 * @param heros Le héros
 * @param projectile_controller Le contrôleur de projectiles
 */
void generate_asteroids(asteroid_controller *controller);

/**
 * @brief Cette fonction gère le mouvement et la destruction des astéroïdes,
 * ainsi que l'animation de destruction des astéroïdes.
 *
 * @param controller Le contrôleur d'astéroïdes
 */
void update_asteroids(asteroid_controller *controller);

/**
 * @brief Cette fonction libère la mémoire allouée pour le contrôleur d'astéroïdes.
 *
 * @param controller Le contrôleur d'astéroïdes
 */
void free_asteroid_controller(asteroid_controller *controller);

#endif