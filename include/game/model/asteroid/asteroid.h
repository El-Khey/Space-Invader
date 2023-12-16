#ifndef ASTEROID_H
#define ASTEROID_H

#include "../../../utils/animation/animation.h"
#include "../../../utils/hitbox/hitbox.h"
#include "../../model/enemy/enemy.h"

typedef enum
{
    NONE,
    EXPLODE,
    nb_asteroid_animation
} AsteroidAnimation;

/**
 * @struct Asteroid
 * @brief Représente un astéroïde dans le jeu Space Invader.
 *
 * Cette structure contient les informations nécessaires pour représenter un astéroïde dans le jeu.
 * Elle inclut des animations, une hitbox, une position, des dimensions, une vitesse, une santé et des dégâts.
 * Elle permet également de gérer les événements en cours et la trajectoire de l'astéroïde.
 */
typedef struct
{
    Animation animation[nb_asteroid_animation]; /**< Les animations de l'astéroïde */
    AsteroidAnimation current_animation;        /**< L'animation actuelle de l'astéroïde */

    Animation effect_animation; /**< L'animation d'effet de l'astéroïde */

    Hitbox hitbox;       /**< La hitbox de l'astéroïde */
    Position position;   /**< La position de l'astéroïde */
    Dimension dimension; /**< Les dimensions de l'astéroïde */

    int speed;  /**< La vitesse de l'astéroïde */
    int health; /**< La santé de l'astéroïde */
    int damage; /**< Les dégâts infligés par l'astéroïde */

    int event_in_process; /**< L'événement en cours */
    Position trajectory;  /**< La trajectoire de l'astéroïde */
} Asteroid;

/**
 * @brief Construit un nouvel astéroïde.
 *
 * @return Le nouvel astéroïde construit.
 */
Asteroid construct_asteroid();

/**
 * @brief Charge les données de sauvegarde d'un astéroïde.
 *
 * @param asteroid L'astéroïde à charger les données de sauvegarde.
 */
void load_asteroid_backup(Asteroid *asteroid);

/**
 * @brief Déplace l'astéroïde.
 *
 * @param asteroid L'astéroïde à déplacer.
 */
void move_asteroid(Asteroid *asteroid);

/**
 * @brief Vérifie si l'astéroïde est détruit.
 *
 * @param asteroid L'astéroïde à vérifier.
 * @return 1 si l'astéroïde est détruit, 0 sinon.
 */
int is_asteroid_dead(Asteroid asteroid);

/**
 * @brief Dessine l'astéroïde.
 *
 * @param asteroid L'astéroïde à dessiner.
 */
void draw_asteroid(Asteroid asteroid);

/**
 * @brief Libère la mémoire allouée pour l'astéroïde.
 *
 * @param asteroid L'astéroïde à libérer.
 */
void free_asteroid(Asteroid *asteroid);

#endif