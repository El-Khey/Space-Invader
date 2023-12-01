#include "../../../../include/game/model/enemy/nautolan.h"

void initialize_nautolan_enemy(Enemy *enemy)
{
    switch (enemy->enemy_type)
    {
    case BATTLECRUISER:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Battlecruiser.png", 8, enemy->dimension, BACKWARD);
        break;
    case BOMBER:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Bomber.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Bomber.png", 8, enemy->dimension, BACKWARD);
        break;
    case DREADNOUGHT:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Dreadnought.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Dreadnought.png", 8, enemy->dimension, BACKWARD);
        break;
    case FIGHTER:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Fighter.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Fighter.png", 8, enemy->dimension, BACKWARD);
        break;
    case FRIGATE:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Frigate.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Frigate.png", 8, enemy->dimension, BACKWARD);
        break;
    case SCOUT:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Scout.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Scout.png", 8, enemy->dimension, BACKWARD);
        break;
    case SUPPORT:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Support.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Support.png", 8, enemy->dimension, BACKWARD);
        break;
    case TORPEDO:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Torpedo.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Torpedo.png", 8, enemy->dimension, BACKWARD);
        break;
    default:
        fprintf(stderr, "Error: unknown enemy type : %d\n", enemy->enemy_type);
        break;
    }
}