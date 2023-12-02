#ifndef ENEMY_H
#define ENEMY_H

#define MAX_ENEMYS 20

#include <stdio.h>
#include <stdlib.h>

#include "../../../utils/dimension/dimension.h"
#include "../../../utils/animation/animation.h"
#include "../../../utils/position/position.h"
#include "../../../utils/hitbox/hitbox.h"
#include "../projectile.h"

typedef enum
{
    KLAED,
    NAIRAN,
    NAUTOLAN,
    nb_enemy_class
} EnemyClass;

typedef enum
{
    BATTLECRUISER,
    /**
     BOMBER,
     DREADNOUGHT,
     FIGHTER,
     FRIGATE,
     SCOUT,
     SUPPORT,
     TORPEDO,
     */
    nb_enemy_type
} EnemyType;

typedef enum
{
    BASE,
    DESTRUCTION,
    ATTACK,
    nb_enemy_animation_state
} EnemyAnimationState;

typedef struct
{
    EnemyAnimationState active_state;
    Animation ship[nb_enemy_animation_state];
    Animation engine_effect_boost;
} EnemyAnimation;

typedef enum
{
    ATTACKING,
    NOTHING,
    DYING
} EnemyState;

typedef struct
{
    Hitbox hitbox;

    Position position;
    Dimension dimension;

    int speed;
    int damage;
    int health;

    Projectiles list;
    EnemyState event_in_process;

    EnemyType enemy_type;
    EnemyClass enemy_class;

    EnemyAnimation enemy_animation;
} Enemy;

Enemy construct_enemy(EnemyClass class);

int is_enemy_dead(Enemy enemy);

void move_enemy(Enemy *enemy);

void draw_enemy(Enemy enemy);

#endif