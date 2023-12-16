#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../../utils/dimension/dimension.h"
#include "../../utils/animation/animation.h"
#include "../../utils/position/position.h"
#include "../../utils/hitbox/hitbox.h"

#define MAX_PROJECTILES 15
#define MAX_BULLETS 7

/**
 * @brief Type d'arme disponible dans le jeu.
 */
typedef enum
{
    AUTO_CANNON, /**< Canon automatique */
    BIG_SPACE,   /**< Grand espace */
    ROCKETS,     /**< Roquettes */
    ZAPPER,      /**< Zappeur */

    RED_RAY,     /**< Rayon rouge */
    RED_TORPEDO, /**< Torpille rouge */
    RED_WAVE,    /**< Vague rouge */

    WHITE_BOMB,     /**< Bombe blanche */
    WHITE_BULLET,   /**< Balle blanche */
    WHITE_RAY,      /**< Rayon blanc */
    WHITE_ROCKET,   /**< Roquette blanche */
    WHTIE_SPINNING, /**< Rotation blanche */
    WHITE_WAVE,     /**< Vague blanche */

    GREEN_BOLT,    /**< Éclair vert */
    GREEN_RAY,     /**< Rayon vert */
    GREEN_ROCKET,  /**< Roquette verte */
    GREEN_TORPEDO, /**< Torpille verte */
    nb_weapon      /**< Nombre d'armes */
} Weapon_Type;

/**
 * @brief Structure représentant une balle.
 */
typedef struct
{
    Hitbox hitbox; /**< La hitbox de la balle. */

    Dimension dimension; /**< Les dimensions de la balle. */
    Position position;   /**< La position de la balle. */

    Animation bullet_animation; /**< L'animation de la balle. */
    int start_fire_time;        /**< Le temps de départ du tir de la balle. */
} Bullet;

/**
 * @brief Structure représentant les balles.
 */
typedef struct
{
    Bullet bullets[MAX_BULLETS];
    int bullets_count;
} Bullets;

/**
 * @brief Structure représentant un projectile.
 *
 * Cette structure représente un projectile utilisé dans le jeu Space Invader.
 * Un projectile est caractérisé par une liste de balles, un type de balle active,
 * un délai de tir, une vitesse et des dégâts.
 */
typedef struct
{
    Bullets list;                   /**< Liste des balles */
    Weapon_Type active_bullet_type; /**< Type de balle active */
    int delay_fire_bullet;          /**< Délai de tir */
    int speed;                      /**< Vitesse du projectile */
    int damage;                     /**< Dégâts du projectile */
} Projectile;

/**
 * @brief Structure représentant les projectiles du jeu.
 *
 * Cette structure contient un tableau de projectiles, le nombre de projectiles actifs
 * et le type de projectile actif.
 */
typedef struct
{
    Projectile projectiles[MAX_PROJECTILES]; /** Tableau de projectiles */
    int projectiles_count;                   /** Nombre de projectiles actifs */
    Weapon_Type active_bullet_type;          /** Type de projectile actif */
} Projectiles;

/**
 * @brief Construit un nouvel objet Projectile pour le héros
 *
 * @param type Le type de projectile
 * @param position La position du héros
 * @param dimension La dimension du héros
 * @return Projectile
 */
Projectile construct_heros_projectile(Weapon_Type type, Position position, Dimension dimension);

/**
 * @brief Construit un nouvel objet Projectile pour l'ennemi
 *
 * @param type Le type de projectile
 * @param position La position de l'ennemi
 * @param dimension La dimension de l'ennemi
 * @return Projectile
 */
Projectile construct_enemy_projectile(Weapon_Type type, Position position, Dimension dimension);

/**
 * @brief Charge la sauvegarde du projectile
 * Cette fonction est utilisée pour charger l'animation du projectile lorsque le jeu est démarré à partir d'une sauvegarde.
 *
 * @param projectile Le projectile
 * @param position La position du projectile
 * @param dimension La dimension du projectile
 */
void load_heros_projectile_backup(Projectile *projectile, Position position, Dimension dimension);

/**
 * @brief Charge la sauvegarde du projectile
 * Cette fonction est utilisée pour charger l'animation du projectile lorsque le jeu est démarré à partir d'une sauvegarde.
 *
 * @param projectile Le projectile
 * @param position La position du projectile
 * @param dimension La dimension du projectile
 */
void load_enemy_projectile_backup(Projectile *projectile, Position position, Dimension dimension);

/**
 * @brief Déplace la balle à l'écran
 *
 * @param bullet La balle à déplacer
 * @param speed La vitesse de la balle
 */
void move_bullet(Bullet *bullet, int speed);

/**
 * @brief Dessine le projectile
 *
 * @param projectile Le projectile à dessiner
 */
void draw_projectile(Projectile projectile);

/**
 * @brief Libère le projectile
 *
 * @param projectile Le projectile à libérer
 */
void free_projectile(Projectile *projectile);

#endif