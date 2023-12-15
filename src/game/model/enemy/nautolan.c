#include "../../../../include/game/model/enemy/nautolan.h"

void initialize_nautolan_enemy(Enemy *enemy)
{
    switch (enemy->enemy_type)
    {
    case BATTLECRUISER:
        enemy->speed = 2;
        enemy->damage = 1;
        enemy->health = 100;
        enemy->score = 100;

        enemy->list.active_bullet_type = WHITE_WAVE;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Weapons/Battlecruiser.png", 9, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Destruction/Battlecruiser.png", 13, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Battlecruiser.png", 8, enemy->dimension, BACKWARD);
        break;
    case BOMBER:
        enemy->speed = 2;
        enemy->damage = 1;
        enemy->health = 100;
        enemy->score = 100;

        enemy->list.active_bullet_type = WHITE_WAVE;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Bomber.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Bomber.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Destruction/Bomber.png", 10, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Bomber.png", 8, enemy->dimension, BACKWARD);
        break;
    case DREADNOUGHT:
        enemy->speed = 3;
        enemy->damage = 1;
        enemy->health = 100;
        enemy->score = 100;

        enemy->list.active_bullet_type = WHITE_WAVE;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Dreadnought.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Weapons/Dreadnought.png", 35, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Destruction/Dreadnought.png", 12, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Dreadnought.png", 8, enemy->dimension, BACKWARD);
        break;
    case FIGHTER:
        enemy->speed = 4;
        enemy->damage = 1;
        enemy->health = 100;
        enemy->score = 100;

        enemy->list.active_bullet_type = WHITE_WAVE;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Fighter.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Weapons/Fighter.png", 9, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Destruction/Fighter.png", 9, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Fighter.png", 8, enemy->dimension, BACKWARD);
        break;
    case FRIGATE:
        enemy->speed = 5;
        enemy->damage = 1;
        enemy->health = 100;
        enemy->score = 100;

        enemy->list.active_bullet_type = WHITE_WAVE;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Frigate.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Weapons/Frigate.png", 9, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Destruction/Frigate.png", 9, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Frigate.png", 8, enemy->dimension, BACKWARD);
        break;
    case SCOUT:
        enemy->speed = 6;
        enemy->damage = 1;
        enemy->health = 100;
        enemy->score = 100;

        enemy->list.active_bullet_type = WHITE_WAVE;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Scout.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Weapons/Scout.png", 7, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Destruction/Scout.png", 9, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Scout.png", 8, enemy->dimension, BACKWARD);
        break;
    case SUPPORT:
        enemy->speed = 7;
        enemy->damage = 1;
        enemy->health = 100;
        enemy->score = 100;

        enemy->list.active_bullet_type = WHITE_WAVE;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Support.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Support.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Destruction/Support.png", 8, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Support.png", 8, enemy->dimension, BACKWARD);
        break;
    case TORPEDO:
        enemy->speed = 8;
        enemy->damage = 1;
        enemy->health = 100;
        enemy->score = 100;

        enemy->list.active_bullet_type = WHITE_WAVE;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Torpedo.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Weapons/Torpedo.png", 16, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Destruction/Torpedo.png", 8, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Torpedo.png", 8, enemy->dimension, BACKWARD);
        break;

    default:
        /**
         * @brief In case of error, we set the enemy to a default value
         * This is a security to avoid a crash of the game if the enemy type is not set correctly for example the scout
         * type is not present for all class of enemy
         *
         */
        enemy->speed = 2;
        enemy->damage = 1;
        enemy->health = 100;
        enemy->score = 100;

        enemy->list.active_bullet_type = RED_RAY;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Weapons/Battlecruiser.png", 9, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Destruction/Battlecruiser.png", 13, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Battlecruiser.png", 8, enemy->dimension, BACKWARD);
        break;
    }
}