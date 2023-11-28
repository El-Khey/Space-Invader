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
    int i = 0;

    switch (type)
    {
    case AUTO_CANNON:
        projectile->list.bullets_count = 2;
        projectile->active_bullet_type = AUTO_CANNON;

        projectile->damage = 5;
        projectile->speed = 5;
        projectile->delay_fire_bullet = 150;

        projectile->list.bullets[0].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Auto Cannon.png", 4, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[0].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[0].dimension = dimension;
        projectile->list.bullets[0].position = construct_position(position.x + dimension.width / 2 - 60, position.y + 15);
        projectile->list.bullets[0].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet - 50;

        projectile->list.bullets[1].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Auto Cannon.png", 4, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[1].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[1].dimension = dimension;
        projectile->list.bullets[1].position = construct_position(position.x + dimension.width / 2 - 4, position.y + 15);
        projectile->list.bullets[1].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet;
        break;

    case BIG_SPACE:
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

    case ROCKETS:
        projectile->list.bullets_count = 6;
        projectile->active_bullet_type = ROCKETS;

        projectile->damage = 5;
        projectile->speed = 5;
        projectile->delay_fire_bullet = 150;

        projectile->list.bullets[0].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Rockets.png", 3, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[0].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[0].dimension = dimension;
        projectile->list.bullets[0].position = construct_position(position.x + dimension.width / 2 - 50, position.y + 50);
        projectile->list.bullets[0].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet;
        projectile->list.bullets[1].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Rockets.png", 3, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[1].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[1].dimension = dimension;
        projectile->list.bullets[1].position = construct_position(position.x + dimension.width / 2 - 10, position.y + 50);
        projectile->list.bullets[1].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet + 125;

        projectile->list.bullets[2].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Rockets.png", 3, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[2].bullet_animation, construct_dimension(64, 64));
        projectile->list.bullets[2].dimension = dimension;
        projectile->list.bullets[2].position = construct_position(position.x + dimension.width / 2 - 65, position.y + 70);
        projectile->list.bullets[2].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet + 125;

        projectile->list.bullets[3].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Rockets.png", 3, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[3].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[3].dimension = dimension;
        projectile->list.bullets[3].position = construct_position(position.x + dimension.width / 2 + 2, position.y + 70);
        projectile->list.bullets[3].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet + 250;

        projectile->list.bullets[4].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Rockets.png", 3, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[4].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[4].dimension = dimension;
        projectile->list.bullets[4].position = construct_position(position.x + dimension.width / 2 - 75, position.y + 80);
        projectile->list.bullets[4].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet + 250;

        projectile->list.bullets[5].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Rockets.png", 3, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[5].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[5].dimension = dimension;
        projectile->list.bullets[5].position = construct_position(position.x + dimension.width / 2 + 15, position.y + 80);
        projectile->list.bullets[5].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet + 325;

        projectile->list.bullets[6].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Rockets.png", 3, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[6].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[6].dimension = dimension;
        projectile->list.bullets[6].position = construct_position(position.x + dimension.width / 2 + 6, position.y - 10);
        projectile->list.bullets[6].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet;

        break;

    case ZAPPER:
        projectile->list.bullets_count = 2;
        projectile->active_bullet_type = ZAPPER;

        projectile->damage = 5;
        projectile->speed = 5;
        projectile->delay_fire_bullet = 150;

        projectile->list.bullets[0].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Zapper.png", 8, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[0].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[0].dimension = dimension;
        projectile->list.bullets[0].position = construct_position(position.x + dimension.width / 2 - 70, position.y - 10);
        projectile->list.bullets[0].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet - 50;

        projectile->list.bullets[1].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Zapper.png", 8, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[1].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[1].dimension = dimension;
        projectile->list.bullets[1].position = construct_position(position.x + dimension.width / 2 + 6, position.y - 10);
        projectile->list.bullets[1].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet;
        break;
    }

    for (i = 0; i < projectile->list.bullets_count; i++)
    {
        play_animation(&projectile->list.bullets[i].bullet_animation);
    }
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