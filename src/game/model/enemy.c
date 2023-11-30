#include "../../../include/game/model/enemy.h"

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
    enemy.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Frigate - Base.png", 1, enemy.dimension, BACKWARD);
    enemy.engine_effect_boost = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Engine/Frigate - Engine.png", 12, enemy.dimension, BACKWARD);

    return enemy;
}

void draw_enemys(Enemys *enemys)
{
    int i = 0;
    for (; i < enemys->nb_enemy; ++i)
    {
        draw_animation(enemys->enemy[i].engine_effect_boost, enemys->enemy[i].position);
        draw_animation(enemys->enemy[i].ship, enemys->enemy[i].position);
    }
}
