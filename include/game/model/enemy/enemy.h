#ifndef ENEMY_H
#define ENEMY_H

#include <stdio.h>
#include <stdlib.h>

#include "../../../utils/dimension/dimension.h"
#include "../../../utils/animation/animation.h"
#include "../../../utils/position/position.h"
#include "../../../utils/hitbox/hitbox.h"
#include "../projectile.h"

/**
 * @file enemy.h
 * @brief Définition des énumérations pour les classes, les types et les états d'animation des ennemis.
 */

typedef enum
{
    KLAED,         /**< Classe d'ennemi Klaed */
    NAIRAN,        /**< Classe d'ennemi Nairan */
    NAUTOLAN,      /**< Classe d'ennemi Nautolan */
    nb_enemy_class /**< Nombre total de classes d'ennemis */
} EnemyClass;

typedef enum
{
    BATTLECRUISER, /**< Type d'ennemi Battlecruiser */
    BOMBER,        /**< Type d'ennemi Bomber */
    DREADNOUGHT,   /**< Type d'ennemi Dreadnought */
    FIGHTER,       /**< Type d'ennemi Fighter */
    FRIGATE,       /**< Type d'ennemi Frigate */
    SCOUT,         /**< Type d'ennemi Scout */
    SUPPORT,       /**< Type d'ennemi Support */
    TORPEDO,       /**< Type d'ennemi Torpedo */
    nb_enemy_type  /**< Nombre total de types d'ennemis */
} EnemyType;

typedef enum
{
    BASE,                    /**< État d'animation de base */
    DESTRUCTION,             /**< État d'animation de destruction */
    ATTACK,                  /**< État d'animation d'attaque */
    nb_enemy_animation_state /**< Nombre total d'états d'animation des ennemis */
} EnemyAnimationState;

/**
 * @brief Structure représentant l'animation d'un ennemi.
 */
typedef struct
{
    EnemyAnimationState active_state;         /**< État d'animation actif de l'ennemi. */
    Animation ship[nb_enemy_animation_state]; /**< Tableau des animations du vaisseau de l'ennemi. */
    Animation engine_effect_boost;            /**< Animation de l'effet de propulsion du moteur. */
} EnemyAnimation;

/**
 * @brief Énumération représentant l'état d'un ennemi.
 */
typedef enum
{
    ATTACKING, /**< L'ennemi est en train d'attaquer. */
    NOTHING,   /**< L'ennemi ne fait rien. */
    DYING      /**< L'ennemi est en train de mourir. */
} EnemyState;

/**
 * @struct Enemy
 * @brief Représente un ennemi dans le jeu Space Invader.
 *
 * Cette structure contient les informations relatives à un ennemi, telles que sa boîte de collision,
 * sa position, ses dimensions, sa vitesse, ses dégâts, sa santé, son score, sa liste de projectiles,
 * son état actuel, son type et sa classe, ainsi que son animation.
 */
typedef struct
{
    Hitbox hitbox;                  /**< La boîte de collision de l'ennemi */
    Position position;              /**< La position de l'ennemi */
    Dimension dimension;            /**< Les dimensions de l'ennemi */
    int speed;                      /**< La vitesse de déplacement de l'ennemi */
    int damage;                     /**< Les dégâts infligés par l'ennemi */
    int health;                     /**< La santé de l'ennemi */
    int score;                      /**< Le score attribué lorsque l'ennemi est détruit */
    Projectiles list;               /**< La liste des projectiles de l'ennemi */
    EnemyState event_in_process;    /**< L'état actuel de l'ennemi */
    EnemyType enemy_type;           /**< Le type de l'ennemi */
    EnemyClass enemy_class;         /**< La classe de l'ennemi */
    EnemyAnimation enemy_animation; /**< L'animation de l'ennemi */
} Enemy;

/**
 * @brief Construit un nouvel ennemi de la classe spécifiée.
 *
 * @param class La classe de l'ennemi.
 * @return L'ennemi construit.
 */
Enemy construct_enemy(EnemyClass class);

/**
 * @brief Charge les données de sauvegarde de l'ennemi spécifié.
 *
 * @param enemy L'ennemi à charger.
 */
void load_enemy_backup(Enemy *enemy);

/**
 * @brief Vérifie si l'ennemi spécifié est mort.
 *
 * @param enemy L'ennemi à vérifier.
 * @return 1 si l'ennemi est mort, 0 sinon.
 */
int is_enemy_dead(Enemy enemy);

/**
 * @brief Déplace l'ennemi spécifié.
 *
 * @param enemy L'ennemi à déplacer.
 */
void move_enemy(Enemy *enemy);

/**
 * @brief Dessine l'ennemi spécifié.
 *
 * @param enemy L'ennemi à dessiner.
 */
void draw_enemy(Enemy enemy);

/**
 * @brief Libère la mémoire allouée pour l'ennemi spécifié.
 *
 * @param enemy L'ennemi à libérer.
 */
void free_enemy(Enemy *enemy);

#endif