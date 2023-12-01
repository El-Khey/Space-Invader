#include "../../../include/game/model/projectile.h"

static void initialize_bullet_animation_from_weapon_type(Projectile *projectile, Position position, Dimension dimension);

Projectile construct_projectile(Position position, Dimension dimension, Weapon_Type type)
{
    Projectile projectile;

    projectile.active_bullet_type = type;
    initialize_bullet_animation_from_weapon_type(&projectile, position, dimension);

    return projectile;
}

static void initialize_bullet_animation_from_weapon_type(Projectile *projectile, Position position, Dimension dimension)
{
    int i = 0;
    switch (projectile->active_bullet_type)
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
        projectile->list.bullets[4].position = construct_position(position.x + dimension.width / 2 - 75, position.y + 70);
        projectile->list.bullets[4].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet + 300;

        projectile->list.bullets[5].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Rockets.png", 3, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[5].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[5].dimension = dimension;
        projectile->list.bullets[5].position = construct_position(position.x + dimension.width / 2 + 15, position.y + 70);
        projectile->list.bullets[5].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet + 500;

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
        projectile->list.bullets[0].position = construct_position(position.x + dimension.width / 2 - 70, position.y + 15);
        projectile->list.bullets[0].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet - 50;

        projectile->list.bullets[1].bullet_animation = construct_animation("assets/sprites/Ships/MainShip/Projectiles/Zapper.png", 8, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[1].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[1].dimension = dimension;
        projectile->list.bullets[1].position = construct_position(position.x + dimension.width / 2 + 6, position.y + 15);
        projectile->list.bullets[1].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet;
        break;

    case RED_RAY:
        projectile->list.bullets_count = 1;
        projectile->active_bullet_type = RED_RAY;

        projectile->damage = 5;
        projectile->speed = 5;
        projectile->delay_fire_bullet = 150;

        projectile->list.bullets[0].bullet_animation = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Projectiles/Red Big Bullet.png", 1, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[0].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[0].dimension = dimension;
        projectile->list.bullets[0].position = construct_position(position.x + dimension.width / 2 - 70, position.y + 15);
        projectile->list.bullets[0].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet - 50;
        break;

    /**
    case RED_BULLET:
        projectile->list.bullets_count = 1;
        projectile->active_bullet_type = RED_BULLET;

        projectile->damage = 5;
        projectile->speed = 5;
        projectile->delay_fire_bullet = 150;

        projectile->list.bullets[0].bullet_animation = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Projectiles/Red Bullet.png", 1, dimension, FORWARD);
        resize_animation(&projectile->list.bullets[0].bullet_animation, construct_dimension(64, 64));

        projectile->list.bullets[0].dimension = dimension;
        projectile->list.bullets[0].position = construct_position(position.x + dimension.width / 2 - 70, position.y + 15);
        projectile->list.bullets[0].start_fire_time = MLV_get_time() + projectile->delay_fire_bullet - 50;
        break;
    */
    default:
        fprintf(stderr, "Error: unknown projectile type %d\n", projectile->active_bullet_type);
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