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

void move_heros_up(Heros *Heros);

void move_heros_down(Heros *Heros);

void move_heros_left(Heros *Heros);

void move_heros_right(Heros *Heros);

void draw_heros(Heros heros);

#endif