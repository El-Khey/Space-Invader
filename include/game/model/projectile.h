#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../../utils/position/position.h"
#include "../../utils/dimension/dimension.h"
#include "../../utils/animation/animation.h"

typedef struct
{
    Dimension dimension;
    Position position;

    Animation bullet_animation;

    int speed;
} Projectile;

Projectile construct_projectile(Position position, Dimension dimension, Animation animation);

void draw_projectile(Projectile projectile);

#endif