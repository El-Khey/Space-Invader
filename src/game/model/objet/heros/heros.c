#include "../../../../../include/game/model/objet/creature/heros/heros.h"

Heros construct_heros(int speed)
{
    Position position_heros;
    Dimension dimension_heros;
    Heros heros;

    position_heros = construct_position(WINDOW_HEIGHT / 2, WINDOW_WIDTH / 2);
    dimension_heros = construct_dimension(50, 50);

    heros.creature = construct_creature(position_heros, dimension_heros);
    heros.speed = speed;
    return heros;
}