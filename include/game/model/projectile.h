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
    nb_weapon
} Weapon_Type;

typedef struct
{
    Dimension dimension;
    Position position;

    Animation bullet_animation;
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