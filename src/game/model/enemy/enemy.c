#include "../../../../include/game/model/enemy/enemy.h"

#include "../../../../include/game/model/enemy/klaed.h"
#include "../../../../include/game/model/enemy/nairan.h"
#include "../../../../include/game/model/enemy/nautolan.h"

static void initialize_enemy_class(Enemy *enemy);

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
        initialize_klaed_enemy(enemy);
        break;
    case NAIRAN:
        initialize_nairan_enemy(enemy);
        break;
    case NAUTOLAN:
        initialize_nautolan_enemy(enemy);
        break;
    default:
        fprintf(stderr, "Error: unknown enemy class : %d\n", enemy->enemy_class);
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
