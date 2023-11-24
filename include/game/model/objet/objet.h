#ifndef OBJET_H
#define OBJET_H

#include "../../../utils/position/position.h"
#include "../../../utils/dimension/dimension.h"

typedef struct
{
    Position position;
    Dimension dimension;
} Objet;

Objet construct_objet(Position position, Dimension dimension);

#endif