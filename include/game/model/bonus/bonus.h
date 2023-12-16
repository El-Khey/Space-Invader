#ifndef BONUS_H
#define BONUS_H

#include "../../../utils/animation/animation.h"
#include "../../../utils/hitbox/hitbox.h"

/**
 * @brief Enumération des types de bonus.
 */
typedef enum
{
    BONUS_TYPE_LIFE,                  /** Bonus de vie */
    BONUS_TYPE_SHIELD_ALL_AROUND,     /** Bonus de bouclier tout autour */
    BONUS_TYPE_SHIELD_FRONT_AND_SIDE, /** Bonus de bouclier avant et latéral */
    BONUS_TYPE_SHIELD_FRONT,          /** Bonus de bouclier avant */
    BONUS_TYPE_SHIELD_INVINCIBILITY,  /** Bonus d'invincibilité */
    nb_bonus_type                     /** Nombre total de types de bonus */
} BonusType;

/**
 * @struct Bonus
 * @brief Représente un bonus dans le jeu Space Invader.
 *
 * Cette structure contient les informations relatives à un bonus, telles que sa position, sa dimension, sa hitbox, son type, son animation, son état de sélection et sa vitesse.
 */
typedef struct
{
    Position position;   /**< La position du bonus. */
    Dimension dimension; /**< Les dimensions du bonus. */
    Hitbox hitbox;       /**< La hitbox du bonus. */

    BonusType type;      /**< Le type de bonus. */
    Animation animation; /**< L'animation du bonus. */

    int is_selected; /**< Indique si le bonus est sélectionné ou non. */
    int speed;       /**< La vitesse du bonus. */
} Bonus;

/**
 * @brief Construit un bonus avec le type spécifié.
 *
 * @param type Le type de bonus.
 * @return Le bonus construit.
 */
Bonus construct_bonus(BonusType type);

/**
 * @brief Charge les données de sauvegarde d'un bonus.
 *
 * @param bonus Le bonus à charger.
 */
void load_bonus_backup(Bonus *bonus);

/**
 * @brief Déplace le bonus.
 *
 * @param bonus Le bonus à déplacer.
 */
void move_bonus(Bonus *bonus);

/**
 * @brief Vérifie si le bonus est sélectionné.
 *
 * @param bonus Le bonus à vérifier.
 * @return 1 si le bonus est sélectionné, 0 sinon.
 */
int is_bonus_selected(Bonus bonus);

/**
 * @brief Dessine le bonus.
 *
 * @param bonus Le bonus à dessiner.
 */
void draw_bonus(Bonus bonus);

/**
 * @brief Libère la mémoire allouée pour le bonus.
 *
 * @param bonus Le bonus à libérer.
 */
void free_bonus(Bonus *bonus);

#endif