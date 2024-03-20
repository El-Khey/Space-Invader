#ifndef SHIELD_H
#define SHIELD_H

#include "../../utils/animation/animation.h"
#include "../../utils/hitbox/hitbox.h"

/**
 * @brief Type de bouclier disponible.
 */
typedef enum
{
    SHIELD_NONE,           /**< Aucun bouclier */
    SHIELD_ALL_AROUND,     /**< Bouclier tout autour */
    SHIELD_FRONT_AND_SIDE, /**< Bouclier avant et côtés */
    SHIELD_FRONT,          /**< Bouclier avant */
    SHIELD_INVINCIBILITY   /**< Bouclier d'invincibilité */
} ShieldType;

/**
 * @struct Shield
 * @brief Représente un bouclier dans le jeu Space Invader.
 *
 * Cette structure contient les informations nécessaires pour représenter un bouclier dans le jeu.
 * Elle inclut une animation, un type de bouclier, un indicateur d'activation, un temps d'activation,
 * une durée du bouclier, une position et une dimension.
 */
typedef struct
{
    Animation animation; /**< L'animation du bouclier */
    ShieldType type;     /**< Le type de bouclier */
    int is_active;       /**< Indicateur d'activation du bouclier */
    int active_time;     /**< Temps d'activation du bouclier */
    int shield_duration; /**< Durée du bouclier */
    Position position;   /**< La position du bouclier */
    Dimension dimension; /**< La dimension du bouclier */
} Shield;

/**
 * @brief Construit un bouclier avec le type de bonus, la position et les dimensions donnés.
 *
 * @param bonus_type Le type de bonus du bouclier.
 * @param position La position du bouclier.
 * @param dimension Les dimensions du bouclier.
 * @return Le bouclier construit.
 */
Shield construct_shield(ShieldType bonus_type, Position position, Dimension dimension);

/**
 * @brief Charge les données de sauvegarde d'un bouclier dans la structure du bouclier donnée.
 *
 * @param shield Le bouclier dans lequel charger les données de sauvegarde.
 */
void load_shield_backup(Shield *shield);

/**
 * @brief Dessine le bouclier donné.
 *
 * @param shield Le bouclier à dessiner.
 */
void draw_shield(Shield shield);

/**
 * @brief Libère la mémoire allouée pour le bouclier donné.
 *
 * @param shield Le bouclier à libérer.
 */
void free_shield(Shield *shield);

#endif