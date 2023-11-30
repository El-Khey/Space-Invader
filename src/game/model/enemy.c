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
    enemy.speed = 5;
    enemy.ship = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Frigate - Base.png", 1, enemy.dimension, BACKWARD);

    return enemy;
}

void handle_enemy(Enemys *enemys)
{
    if (enemys->nb_enemy < MAX_ENEMYS)
    {
        enemys->enemy[enemys->nb_enemy] = construct_enemy();
        enemys->nb_enemy++;
    }
}

void update_enemy_positions(Enemys *enemys)
{
    int i;
    for (i = 0; i < enemys->nb_enemy; ++i)
    {
        move_position(&enemys->enemy[i].position, 0, enemys->enemy[i].speed);
    }
}

void draw_enemys(Enemys *enemys)
{
    int i = 0;
    for (; i < enemys->nb_enemy; ++i)
    {
        draw_animation(enemys->enemy[i].ship, enemys->enemy[i].position);
    }
}
