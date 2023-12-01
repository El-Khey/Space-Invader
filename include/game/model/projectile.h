#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../../utils/position/position.h"
#include "../../utils/dimension/dimension.h"
#include "../../utils/animation/animation.h"

#define MAX_PROJECTILES 200
#define MAX_BULLETS 7

typedef enum
{
    AUTO_CANNON,
    BIG_SPACE,
    ROCKETS,
    ZAPPER,

    RED_RAY,
    /**
    RED_BIG_BULLET,
    RED_BULLET,
    RED_TORPEDO,
    RED_WAVE,

    GREEN_BOLT,
    GREEN_RAY,
    GREEN_ROCKET,
    GREEN_TORPEDO,

    WHITE_BOMB,
    WHITE_BULLET,
    WHITE_RAY,
    WHITE_ROCKET,
    WHTIE_SPINNING,
    WHITE_WAVE,
    */
    nb_weapon
} Weapon_Type;

typedef struct
{
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

Projectile construct_projectile(Position position, Dimension dimension, Weapon_Type type);

void draw_projectile(Projectile projectile);

#endif