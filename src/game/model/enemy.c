#include "../../../include/game/model/enemy.h"

Enemy construct_enemy()
{
    Enemy enemy;

    enemy.dimension = construct_dimension(150, 150);
    enemy.position = construct_position(rand() % WINDOW_WIDTH - get_width(enemy.dimension), 0);
    enemy.speed = 2;
    enemy.animation_ennemy = construct_animation("assets/sprites/Ships/EnemyFleet/Kla'ed/Base/Frigate - Base.png", 1, enemy.dimension, BACKWARD);

    return enemy;
}

void handle_enemy(Enemy *enemy)
{
    Enemys enemys;
    move_position(&enemy->position, 0, enemy->speed);
}

void draw_enemy(Enemy enemy)
{
    draw_animation(enemy.animation_ennemy, enemy.position);
}