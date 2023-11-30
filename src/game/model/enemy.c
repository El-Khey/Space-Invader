#include "../../../include/game/model/enemy.h"

void initialize_enemy_animation_from_ship_type(EnemyType type, EnemyAnimation *enemy, Dimension dimension, Position position);

Enemys construct_enemys()
{
    Enemys enemys;
    enemys.nb_enemy = 0;

    return enemys;
}

Enemy construct_enemy()
{
    Enemy enemy;

    enemy.dimension = construct_dimension(150, 150);
    enemy.position = construct_position(rand() % WINDOW_WIDTH - get_width(enemy.dimension), -get_height(enemy.dimension));
    enemy.speed = 3;
    enemy.type = KLAED;
    initialize_enemy_animation_from_ship_type(enemy.type, &enemy.enemy_animation, enemy.dimension, enemy.position);

    return enemy;
}

void draw_enemys(Enemys *enemys)
{
    int i = 0;
    for (; i < enemys->nb_enemy; ++i)
    {
        draw_animation(enemys->enemy[i].enemy_animation.engine_effect_boost, enemys->enemy[i].position);
        draw_animation(enemys->enemy[i].enemy_animation.ship, enemys->enemy[i].position);
    }
}

void initialize_enemy_animation_from_ship_type(EnemyType type, EnemyAnimation *enemy, Dimension dimension, Position position)
{
    enemy->ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Frigate - Base.png", 1, dimension, BACKWARD);
    enemy->engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Frigate - Engine.png", 12, dimension, BACKWARD);
}