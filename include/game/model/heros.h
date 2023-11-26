#ifndef HEROS_H
#define HEROS_H

#include <stdio.h>
#include <stdlib.h>

#include "../../utils/position/position.h"
#include "../../utils/dimension/dimension.h"
#include "./projectile.h"
#include "../../utils/animation/animation.h"

#define MAX_PROJECTILES 200

typedef struct
{
    Projectile projectiles[MAX_PROJECTILES];
    int projectiles_count;
} Projectiles;

typedef struct
{
    Position position;
    Dimension dimension;
    Animation animation;
    Projectiles list;

    int speed;
} Heros;

Heros construct_heros();

void move_heros_up(Heros *Heros);

void move_heros_down(Heros *Heros);

void move_heros_left(Heros *Heros);

void move_heros_right(Heros *Heros);

void draw_heros(Heros heros);

#endif