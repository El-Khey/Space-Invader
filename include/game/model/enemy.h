#ifndef ENEMY_H
#define ENEMY_H

#define MAX_ENEMYS 20

#include <stdio.h>
#include <stdlib.h>

#include "../../utils/position/position.h"
#include "../../utils/dimension/dimension.h"
#include "./projectile.h"
#include "../../utils/animation/animation.h"

typedef struct
{
    Position position;
    Dimension dimension;
    int speed;
    Animation animation_ennemy;
} Enemy;

typedef struct
{
    Enemy enemy[MAX_ENEMYS];

} Enemys;

Enemy construct_enemy();
void draw_enemy(Enemy enemy);
void handle_enemy(Enemy *enemy);

#endif