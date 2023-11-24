#ifndef CREATURE_H
#define CREATURE_H

#include "../objet.h"

typedef struct
{
    Objet objet;

} Creature;

Creature construct_creature(Position position, Dimension dimension);

#endif