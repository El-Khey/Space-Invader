#include "../../../include/game/model/projectile.h"

Projectile construct_projectile(Position position, Dimension dimension, Animation animation)
{
    Projectile projectile;

    projectile.bullet_animation = animation;
    resize_animation(&projectile.bullet_animation, construct_dimension(64, 64));

    projectile.dimension = dimension;
    projectile.position = construct_position(position.x + dimension.width / 2 - 32, position.y);

    projectile.speed = 7;

    return projectile;
}

void draw_projectile(Projectile projectile)
{
    draw_animation(projectile.bullet_animation, projectile.position);
}