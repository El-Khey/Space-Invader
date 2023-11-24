#include "../../../../../include/game/model/objet/creature/creature.h"

Creature construct_creature(Position position, Dimension dimension)
{
    Creature creature;
    creature.objet = construct_objet(position, dimension);

    return creature;
}