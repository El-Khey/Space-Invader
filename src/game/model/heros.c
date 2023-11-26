#include "../../../include/game/model/heros.h"

Heros construct_heros()
{
    Heros heros;

    heros.dimension = construct_dimension(150, 150);
    heros.position = construct_position(WINDOW_WIDTH / 2 - get_width(heros.dimension) / 2, WINDOW_HEIGHT - get_height(heros.dimension) - 25);
    heros.speed = 5;

    heros.list.projectiles_count = 0;
    heros.animation = construct_animation("assets/image.png", 1, heros.dimension, FORWARD);

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

static void draw_heros_projectiles(Projectiles list)
{
    int i = 0;
    for (; i < list.projectiles_count; i++)
    {
        draw_projectile(list.projectiles[i]);
    }
}

void draw_heros(Heros heros)
{
    draw_heros_projectiles(heros.list);
    draw_animation(heros.animation, heros.position);
}