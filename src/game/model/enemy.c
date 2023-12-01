#include "../../../include/game/model/enemy.h"

static void initialize_enemy_class(Enemy *enemy);

static void initialize_klaed(Enemy *enemy);
static void initialize_nairan(Enemy *enemy);
static void initialize_nautolan(Enemy *enemy);

Enemy construct_enemy(EnemyClass class)
{
    Enemy enemy;

    enemy.dimension = construct_dimension(175, 175);
    enemy.position = construct_position(rand() % (WINDOW_WIDTH - get_width(enemy.dimension)), -get_height(enemy.dimension));

    enemy.speed = 3;
    enemy.enemy_class = class;
    enemy.enemy_type = rand() % nb_enemy_type;

    initialize_enemy_class(&enemy);

    return enemy;
}

static void initialize_enemy_class(Enemy *enemy)
{
    switch (enemy->enemy_class)
    {
    case KLAED:
        initialize_klaed(enemy);
        break;
    case NAIRAN:
        initialize_nairan(enemy);
        break;
    case NAUTOLAN:
        initialize_nautolan(enemy);
        break;
    default:
        fprintf(stderr, "Error: unknown enemy class : %d\n", enemy->enemy_class);
        break;
    }
}

static void initialize_klaed(Enemy *enemy)
{
    switch (enemy->enemy_type)
    {
    case BATTLECRUISER:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Battlecruiser.png", 12, enemy->dimension, BACKWARD);
        break;
    case BOMBER:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Bomber.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Bomber.png", 10, enemy->dimension, BACKWARD);
        break;
    case DREADNOUGHT:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Dreadnought.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Dreadnought.png", 12, enemy->dimension, BACKWARD);
        break;
    case FIGHTER:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Fighter.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Fighter.png", 10, enemy->dimension, BACKWARD);
        break;
    case FRIGATE:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Frigate.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Frigate.png", 12, enemy->dimension, BACKWARD);
        break;
    case SCOUT:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Scout.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Scout.png", 10, enemy->dimension, BACKWARD);
        break;
    case SUPPORT:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Support.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Support.png", 10, enemy->dimension, BACKWARD);
        break;
    case TORPEDO:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Torpedo.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Torpedo.png", 10, enemy->dimension, BACKWARD);
        break;
    default:
        fprintf(stderr, "Error: unknown enemy type : %d\n", enemy->enemy_type);
        break;
    }
}

static void initialize_nairan(Enemy *enemy)
{
    switch (enemy->enemy_type)
    {
    case BATTLECRUISER:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Battlecruiser.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Battlecruiser.png", 8, enemy->dimension, BACKWARD);
        break;
    case BOMBER:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Bomber.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Bomber.png", 8, enemy->dimension, BACKWARD);
        break;
    case DREADNOUGHT:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Dreadnought.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Dreadnought.png", 8, enemy->dimension, BACKWARD);
        break;
    case FIGHTER:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Fighter.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Fighter.png", 8, enemy->dimension, BACKWARD);
        break;
    case FRIGATE:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Frigate.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Frigate.png", 8, enemy->dimension, BACKWARD);
        break;
    case SCOUT:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Scout.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Scout.png", 8, enemy->dimension, BACKWARD);
        break;
    case SUPPORT:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Support.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Support.png", 8, enemy->dimension, BACKWARD);
        break;
    case TORPEDO:
        enemy->enemy_animation.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Base/Torpedo.png", 1, enemy->dimension, BACKWARD);
        enemy->enemy_animation.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Nairan/Engine/Torpedo.png", 8, enemy->dimension, BACKWARD);
        break;
    default:
        fprintf(stderr, "Error: unknown enemy type : %d\n", enemy->enemy_type);
        break;
    }
}

static void initialize_nautolan(Enemy *enemy)
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

void move_enemy(Enemy *enemy)
{
    move_position(&enemy->position, 0, enemy->speed);
}

void draw_enemy(Enemy enemy)
{
    draw_animation(enemy.enemy_animation.ship, enemy.position);
    draw_animation(enemy.enemy_animation.engine_effect_boost, enemy.position);
}
