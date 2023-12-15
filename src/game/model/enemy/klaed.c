#include "../../../../include/game/model/enemy/klaed.h"

void initialize_klaed_enemy(Enemy *enemy)
{
    switch (enemy->enemy_type)
    {
    case BATTLECRUISER:
        enemy->speed = 2;
        enemy->damage = 1;

        enemy->health = 15;
        enemy->score = 100;

        enemy->list.active_bullet_type = WHITE_WAVE;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Weapons/Battlecruiser.png", 30, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Battlecruiser.png", 14, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Battlecruiser.png", 12, enemy->dimension, BACKWARD);
        break;

    case BOMBER:
        enemy->speed = 2;
        enemy->damage = 1;
        enemy->health = 15;

        enemy->score = 100;
        enemy->list.active_bullet_type = RED_RAY;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Bomber.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Bomber.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Bomber.png", 1, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Bomber.png", 10, enemy->dimension, BACKWARD);
        break;
    case DREADNOUGHT:
        enemy->speed = 3;
        enemy->damage = 1;
        enemy->health = 15;

        enemy->score = 100;
        enemy->list.active_bullet_type = RED_RAY;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Dreadnought.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Weapons/Dreadnought.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Dreadnought.png", 1, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Dreadnought.png", 60, enemy->dimension, BACKWARD);
        break;
    case FIGHTER:
        enemy->speed = 4;
        enemy->damage = 1;
        enemy->health = 15;

        enemy->score = 100;
        enemy->list.active_bullet_type = RED_RAY;
        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Fighter.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Weapons/Fighter.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Fighter.png", 1, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Fighter.png", 6, enemy->dimension, BACKWARD);
        break;
    case FRIGATE:
        enemy->speed = 5;
        enemy->damage = 1;
        enemy->health = 15;

        enemy->score = 100;
        enemy->list.active_bullet_type = RED_RAY;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Frigate.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Weapons/Frigate.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Frigate.png", 1, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Frigate.png", 6, enemy->dimension, BACKWARD);
        break;
    case SCOUT:
        enemy->speed = 6;
        enemy->damage = 1;
        enemy->health = 15;

        enemy->score = 100;
        enemy->list.active_bullet_type = RED_RAY;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Scout.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Weapons/Scout.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Scout.png", 1, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Scout.png", 6, enemy->dimension, BACKWARD);
        break;

    case TORPEDO:
        enemy->speed = 8;
        enemy->damage = 1;
        enemy->health = 15;

        enemy->score = 100;
        enemy->list.active_bullet_type = RED_RAY;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Torpedo.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Weapons/Torpedo.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Torpedo.png", 1, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Torpedo.png", 16, enemy->dimension, BACKWARD);
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

        enemy->health = 15;
        enemy->score = 100;

        enemy->list.active_bullet_type = WHITE_WAVE;

        enemy->enemy_animation.ship[BASE] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[ATTACK] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Weapons/Battlecruiser.png", 30, enemy->dimension, BACKWARD);
        enemy->enemy_animation.ship[DESTRUCTION] = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Destruction/Battlecruiser.png", 14, enemy->dimension, BACKWARD);

        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Battlecruiser.png", 12, enemy->dimension, BACKWARD);
        break;
    }
}
