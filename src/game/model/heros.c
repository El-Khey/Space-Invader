#include "../../../include/game/model/heros.h"

Heros construct_heros()
{
    Heros heros;

    heros.dimension = construct_dimension(50, 50);
    heros.position = construct_position(WINDOW_WIDTH / 2 - get_width(heros.dimension) / 2, WINDOW_HEIGHT - get_height(heros.dimension) - 25);
    heros.speed = 15;

    return heros;
}

void move_heros_up(Heros *Heros)
{
    move_position(&Heros->position, 0, -Heros->speed);
}

void move_heros_down(Heros *Heros)
{
    move_position(&Heros->position, 0, Heros->speed);
}

void move_heros_left(Heros *Heros)
{
    move_position(&Heros->position, -Heros->speed, 0);
}

void move_heros_right(Heros *Heros)
{
    move_position(&Heros->position, Heros->speed, 0);
}

void draw_heros(Heros heros)
{
    MLV_draw_filled_rectangle(get_x(heros.position), get_y(heros.position), get_width(heros.dimension), get_height(heros.dimension), MLV_COLOR_RED);
}