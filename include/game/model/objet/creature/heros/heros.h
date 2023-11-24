#ifndef HEROS_H
#define HEROS_H

#include <stdio.h>
#include <stdlib.h>
#include "../creature.h"

typedef struct
{
    Creature creature;
    int speed;

} Heros;

Heros construct_heros(int speed);

#endif