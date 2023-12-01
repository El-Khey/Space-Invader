#include "../../../../include/game/model/enemy/nairan.h"

void initialize_nairan_enemy(Enemy *enemy)
{
    switch (enemy->enemy_type)
    {
    case BATTLECRUISER:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Battlecruiser.png", 8, enemy->dimension, BACKWARD);
        break;
    case BOMBER:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Bomber.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Bomber.png", 8, enemy->dimension, BACKWARD);
        break;
    case DREADNOUGHT:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Dreadnought.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Dreadnought.png", 8, enemy->dimension, BACKWARD);
        break;
    case FIGHTER:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Fighter.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Fighter.png", 8, enemy->dimension, BACKWARD);
        break;
    case FRIGATE:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Frigate.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Frigate.png", 8, enemy->dimension, BACKWARD);
        break;
    case SCOUT:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Scout.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Scout.png", 8, enemy->dimension, BACKWARD);
        break;
    case SUPPORT:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Support.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Support.png", 8, enemy->dimension, BACKWARD);
        break;
    case TORPEDO:
        enemy->speed = 3;
        enemy->damage = 10;
        enemy->health = 100;

        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Torpedo.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Torpedo.png", 8, enemy->dimension, BACKWARD);
        break;
    default:
        fprintf(stderr, "Error: unknown enemy type : %d\n", enemy->enemy_type);
        break;
    }
}
