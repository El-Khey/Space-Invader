#include "../../../include/game/model/projectile.h"

static void initialize_bullet_animation_from_weapon_type(Weapon_Type type, Projectile *projectile, Dimension dimension, Position position);

Projectile construct_projectile(Position position, Dimension dimension, Weapon_Type type)
{
    Projectile projectile;

    initialize_bullet_animation_from_weapon_type(type, &projectile, dimension, position);
    projectile.active_bullet_type = type;

    return projectile;
}

static void initialize_bullet_animation_from_weapon_type(Weapon_Type type, Projectile *projectile, Dimension dimension, Position position)
{
    switch (type)
    {
        /**
    case BIG_SPACE:
        projectile->list.bullets_count = 2;
        projectile->active_bullet_type = BIG_SPACE;

        projectile->damage = 5;
        projectile->speed = 2;
        projectile->delay_fire_bullet = 15;

        projectile->list.bullets[0].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Big Space Gun.png", 10, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[0].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[0].dimension = dimension;
        projectile->list.bullets[0].position = construct_position(position.x + dimension.width / 2 - 64, position.y);

        projectile->list.bullets[1].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Big Space Gun.png", 10, dimension, FORWARD);
        projectile->list.bullets[1].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Big Space Gun.png", 10, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[1].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[1].dimension = dimension;
        projectile->list.bullets[1].position = construct_position(position.x + dimension.width / 2, position.y);

        break;

    case ROCKETS:
        projectile->list.bullets_count = 2;
        projectile->active_bullet_type = ROCKETS;

        projectile->damage = 5;
        projectile->speed = 2;
        projectile->delay_fire_bullet = 15;

        projectile->list.bullets[0].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Rockets.png", 3, dimension, FORWARD);
        projectile->list.bullets[0].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Rockets.png", 3, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[0].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[0].dimension = dimension;
        projectile->list.bullets[0].position = construct_position(position.x + dimension.width / 2 - 32, position.y);

        projectile->list.bullets[1].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Rockets.png", 3, dimension, FORWARD);
        projectile->list.bullets[1].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Rockets.png", 3, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[1].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[1].dimension = dimension;
        projectile->list.bullets[1].position = construct_position(position.x + dimension.width / 2, position.y);

        break;
*/
    default:
        projectile->list.bullets_count = 2;
        projectile->active_bullet_type = BIG_SPACE;

        projectile->damage = 5;
        projectile->speed = 5;
        projectile->delay_fire_bullet = 150;

        projectile->list.bullets[0].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Big Space Gun.png", 10, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[0].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[0].dimension = dimension;
        projectile->list.bullets[0].position = construct_position(position.x + dimension.width / 2 - 70, position.y - 10);
        projectile->list.bullets[0].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet - 50;

        projectile->list.bullets[1].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Big Space Gun.png", 10, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[1].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[1].dimension = dimension;
        projectile->list.bullets[1].position = construct_position(position.x + dimension.width / 2 + 6, position.y - 10);
        projectile->list.bullets[1].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet;
        break;
    }

    play_animation(&projectile->list.bullets[0].bullet_animation);
    play_animation(&projectile->list.bullets[1].bullet_animation);
}

void draw_projectile(Projectile projectile)
{
    int i = 0;
    for (; i < projectile.list.bullets_count; i++)
    {
        if (MLV_get_time() >= projectile.list.bullets[i].start_fire_time)
        {
            draw_animation(projectile.list.bullets[i].bullet_animation, projectile.list.bullets[i].position);
        }
    }
}