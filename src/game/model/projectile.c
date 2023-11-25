#include "../../../include/game/model/projectile.h"

Projectile construct_projectile(Position position, Dimension dimension)
{
    Projectile projectile;

    projectile.dimension = construct_dimension(10, 25);
    projectile.position = construct_position(get_x(position) + get_width(dimension) / 2 - get_width(projectile.dimension) / 2, get_y(position) - get_height(projectile.dimension));

    projectile.speed = 7;

    return projectile;
}

void draw_projectile(Projectile projectile)
{
    MLV_draw_filled_rectangle(get_x(projectile.position), get_y(projectile.position), get_width(projectile.dimension), get_height(projectile.dimension), MLV_COLOR_GREEN);
}