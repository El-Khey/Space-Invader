#include "../../../include/game/model/heros.h"

Heros construct_heros()
{
    Heros heros;

    heros.dimension = construct_dimension(50, 50);
    heros.position = construct_position(WINDOW_WIDTH / 2 - get_width(heros.dimension) / 2, WINDOW_HEIGHT - get_height(heros.dimension) - 25);
    heros.speed = 15;

    return heros;
}