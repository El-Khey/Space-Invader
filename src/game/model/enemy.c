#include "../../../include/game/model/enemy.h"

static void initialize_enemy_type(Enemy *enemy);

Enemy construct_enemy(EnemyType type)
{
    Enemy enemy;

    enemy.dimension = construct_dimension(150, 150);
    enemy.position = construct_position(rand() % WINDOW_WIDTH - get_width(enemy.dimension), -get_height(enemy.dimension));

    enemy.speed = 3;
    enemy.enemy_type = type;

    initialize_enemy_type(&enemy);

    return enemy;
}

static void initialize_enemy_type(Enemy *enemy)
{
    switch (enemy->enemy_type)
    {
    case KLAED:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Battlecruiser.png", 12, enemy->dimension, BACKWARD);
        break;
    case NAIRAN:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Battlecruiser.png", 12, enemy->dimension, BACKWARD);
        break;
    case NAUTOLAN:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nautolan/Engine/Battlecruiser.png", 12, enemy->dimension, BACKWARD);
        break;
    default:
        fprintf(stderr, "Error: unknown enemy type : %d\n", enemy->enemy_type);
        break;
    }
}

void move_enemy(Enemy *enemy)
{
    move_position(&enemy->position, 0, enemy->speed);
}

void draw_enemy(Enemy enemy)
{
    draw_animation(enemy.enemy_animation.ship, enemy.position);
    draw_animation(enemy.enemy_animation.engine_effect_boost, enemy.position);
}
