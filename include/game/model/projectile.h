#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../../utils/position/position.h"
#include "../../utils/dimension/dimension.h"

typedef struct
{
    Dimension dimension;
    Position position;

    int speed;
} Projectile;

Projectile construct_projectile(Position position, Dimension dimension);

void draw_projectile(Projectile projectile);

#endif