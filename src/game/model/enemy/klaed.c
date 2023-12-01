#include "../../../../include/game/model/enemy/klaed.h"

void initialize_klaed_enemy(Enemy *enemy)
{
    switch (enemy->enemy_type)
    {
    case BATTLECRUISER:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Battlecruiser.png", 12, enemy->dimension, BACKWARD);
        break;
    case BOMBER:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Bomber.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Bomber.png", 10, enemy->dimension, BACKWARD);
        break;
    case DREADNOUGHT:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Dreadnought.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Dreadnought.png", 12, enemy->dimension, BACKWARD);
        break;
    case FIGHTER:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Fighter.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Fighter.png", 10, enemy->dimension, BACKWARD);
        break;
    case FRIGATE:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Frigate.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Frigate.png", 12, enemy->dimension, BACKWARD);
        break;
    case SCOUT:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Scout.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Scout.png", 10, enemy->dimension, BACKWARD);
        break;
    case SUPPORT:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Support.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Support.png", 10, enemy->dimension, BACKWARD);
        break;
    case TORPEDO:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Torpedo.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Torpedo.png", 10, enemy->dimension, BACKWARD);
        break;
    default:
        fprintf(stderr, "Error: unknown enemy type : %d\n", enemy->enemy_type);
        break;
    }
}
