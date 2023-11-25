#ifndef HEROS_H
#define HEROS_H

#include <stdio.h>
#include <stdlib.h>

#include "../../utils/position/position.h"
#include "../../utils/dimension/dimension.h"

typedef struct
{
    Position position;
    Dimension dimension;

    int speed;
} Heros;

Heros construct_heros();

#endif