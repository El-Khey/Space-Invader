#include "../../../../include/game/model/objet/objet.h"

Objet construct_objet(Position position, Dimension dimension)
{
    Objet objet;

    objet.dimension = construct_dimension(get_width(dimension), get_height(dimension));
    objet.position = construct_position(get_x(position), get_y(position));

    return objet;
}