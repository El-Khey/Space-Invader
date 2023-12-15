#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../../utils/dimension/dimension.h"
#include "../../utils/animation/animation.h"
#include "../../utils/position/position.h"
#include "../../utils/hitbox/hitbox.h"

#define MAX_PROJECTILES 15
#define MAX_BULLETS 7

typedef enum
{
    AUTO_CANNON,
    BIG_SPACE,
    ROCKETS,
    ZAPPER,

    RED_RAY,
    RED_TORPEDO,
    RED_WAVE,

    WHITE_BOMB,
    WHITE_BULLET,
    WHITE_RAY,
    WHITE_ROCKET,
    WHTIE_SPINNING,
    WHITE_WAVE,

    GREEN_BOLT,
    GREEN_RAY,
    GREEN_ROCKET,
    GREEN_TORPEDO,
    nb_weapon
} Weapon_Type;

typedef struct
{
    Hitbox hitbox;

    Dimension dimension;
    Position position;

    Animation bullet_animation;
    int start_fire_time;
} Bullet;

typedef struct
{
    Bullet bullets[MAX_BULLETS];
    int bullets_count;
} Bullets;

typedef struct
{
    Bullets list;
    Weapon_Type active_bullet_type;

    int delay_fire_bullet;

    int speed;
    int damage;
} Projectile;

typedef struct
{
    Projectile projectiles[MAX_PROJECTILES];
    int projectiles_count;
    Weapon_Type active_bullet_type;
} Projectiles;

/**
 * @brief Construct a new Projectile object for the heros
 *
 * @param type The type of the projectile
 * @param position The position of the heros
 * @param dimension The dimension of the heros
 * @return Projectile
 */
Projectile construct_heros_projectile(Weapon_Type type, Position position, Dimension dimension);

/**
 * @brief Construct a new Projectile object for the enemy
 *
 * @param type The type of the projectile
 * @param position The position of the enemy
 * @param dimension The dimension of the enemy
 * @return Projectile
 */
Projectile construct_enemy_projectile(Weapon_Type type, Position position, Dimension dimension);

/**
 * @brief Load the projectile backup
 * This function is used to load the projectile animation when the game is started from a backup.
 *
 * @param projectile The projectile
 * @param position The position of the projectile
 * @param dimension The dimension of the projectile
 */
void load_heros_projectile_backup(Projectile *projectile, Position position, Dimension dimension);

/**
 * @brief Load the projectile backup
 * This function is used to load the projectile animation when the game is started from a backup.
 *
 * @param projectile The projectile
 * @param position The position of the projectile
 * @param dimension The dimension of the projectile
 */
void load_enemy_projectile_backup(Projectile *projectile, Position position, Dimension dimension);

/**
 * @brief Move the bullet on the screen
 *
 * @param bullet The bullet to move
 * @param speed The speed of the bullet
 */
void move_bullet(Bullet *bullet, int speed);

/**
 * @brief Draw the projectile
 *
 * @param projectile The projectile to draw
 */
void draw_projectile(Projectile projectile);

/**
 * @brief Free the projectile
 *
 * @param projectile The projectile to free
 */
void free_projectile(Projectile *projectile);

#endif