#ifndef ENEMY_H
#define ENEMY_H

#define MAX_ENEMYS 20

#include <stdio.h>
#include <stdlib.h>

#include "../../utils/position/position.h"
#include "../../utils/dimension/dimension.h"
#include "./projectile.h"
#include "../../utils/animation/animation.h"

typedef enum
{
    KLAED,
    NAIRAN,
    NAUTOLAN,
    nb_enemy_type
} EnemyType;

typedef struct
{
    Animation ship;
    Animation engine_effect_boost;
} EnemyAnimation;

typedef struct
{
    Position position;
    Dimension dimension;

    int speed;

    EnemyType enemy_type;
    EnemyAnimation enemy_animation;
} Enemy;

Enemy construct_enemy(EnemyType type);

void move_enemy(Enemy *enemy);

void draw_enemy(Enemy enemy);

#endif