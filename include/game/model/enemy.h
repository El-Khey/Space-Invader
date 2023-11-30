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
    NAUTOLAN
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
    EnemyType type;
    EnemyAnimation enemy_animation;
} Enemy;

typedef struct
{
    Enemy enemy[MAX_ENEMYS];
    int nb_enemy;
    int max_enemy;
} Enemys;

Enemy construct_enemy();
Enemys construct_enemys();

void draw_enemys(Enemys *enemys);

#endif