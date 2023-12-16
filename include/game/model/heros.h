#ifndef HEROS_H
#define HEROS_H

#include <stdio.h>
#include <stdlib.h>

#include "../../utils/dimension/dimension.h"
#include "../../utils/animation/animation.h"
#include "../../utils/position/position.h"
#include "../../utils/hitbox/hitbox.h"
#include "./projectile.h"
#include "./shield.h"

/**
 * @brief Type d'animation du moteur du héros.
 */
typedef enum
{
    BASE_ENGINE,         /**< Moteur de base */
    BIG_PULSE_ENGINE,    /**< Moteur à impulsion puissante */
    BURST_ENGINE,        /**< Moteur à explosion */
    SUPERCHARGED_ENGINE, /**< Moteur suralimenté */
    nb_engine_animations /**< Nombre d'animations de moteur */
} EngineType;

/**
 * @brief État de santé du vaisseau du héros.
 */
typedef enum
{
    FULL_HEALTH,         /**< Santé complète */
    SLIGHTLY_DAMAGED,    /**< Légèrement endommagé */
    DAMAGED,             /**< Endommagé */
    VERY_DAMAGED,        /**< Très endommagé */
    nb_ship_health_state /**< Nombre d'états de santé du vaisseau */
} ShipHealthState;

/**
 * @brief Structure représentant les animations du moteur du héros.
 */
typedef struct
{
    Animation engine;              /** Animation du moteur */
    Animation engine_effect_idle;  /** Animation de l'effet du moteur au repos */
    Animation engine_effect_boost; /** Animation de l'effet du moteur en accélération */
} EngineAnimation;

/**
 * @brief Structure représentant l'animation de l'arme du héros.
 */
typedef struct
{
    Animation weapon_shooting; /**< Animation de tir de l'arme. */
} WeaponAnimation;

/**
 * @struct Heros
 * @brief Représente le héros du jeu.
 *
 * Cette structure contient les informations relatives au héros du jeu, telles que sa position, sa dimension, sa santé, etc.
 * Elle est utilisée pour gérer les mouvements, les animations, les armes et les projectiles du héros.
 */
typedef struct
{
    Hitbox hitbox;       /**< La hitbox du héros */
    Position position;   /**< La position du héros */
    Dimension dimension; /**< La dimension du héros */

    Shield shield;                        /**< Le bouclier du héros */
    Animation ship[nb_ship_health_state]; /**< Les animations du vaisseau du héros */
    int active_ship;                      /**< L'indice de l'animation du vaisseau actif */

    EngineAnimation engine_animations[nb_engine_animations]; /**< Les animations du moteur du héros */
    EngineType active_engine;                                /**< Le type de moteur actif */

    WeaponAnimation weapons_animations[nb_weapon]; /**< Les animations des armes du héros */
    Weapon_Type active_weapon;                     /**< Le type d'arme actif */

    Projectiles list; /**< La liste des projectiles du héros */

    int is_boost_activated; /**< Indique si le boost est activé pour le héros */
    int is_firing;          /**< Indique si le héros est en train de tirer */

    int speed;  /**< La vitesse du héros */
    int health; /**< La santé du héros */
} Heros;
/**
 * @brief Construit un objet Heros avec la position et les dimensions spécifiées.
 *
 * @param position La position du héros.
 * @param dimension Les dimensions du héros.
 * @return Heros L'objet Heros construit.
 */
Heros construct_heros(Position position, Dimension dimension);

/**
 * @brief Charge les données de sauvegarde du héros spécifié.
 *
 * @param heros Le pointeur vers l'objet Heros.
 */
void load_heros_backup(Heros *heros);

/**
 * @brief Met à jour le vaisseau actif du héros spécifié.
 *
 * @param heros Le pointeur vers l'objet Heros.
 */
void update_heros_active_ship(Heros *heros);

/**
 * @brief Vérifie si le héros spécifié est en vie.
 *
 * @param heros L'objet Heros à vérifier.
 * @return int 1 si le héros est en vie, 0 sinon.
 */
int is_heros_alive(Heros heros);

/**
 * @brief Dessine le héros spécifié.
 *
 * @param heros L'objet Heros à dessiner.
 */
void draw_heros(Heros heros);

/**
 * @brief Libère la mémoire allouée pour l'objet Heros spécifié.
 *
 * @param heros Le pointeur vers l'objet Heros.
 */
void free_heros(Heros *heros);

#endif