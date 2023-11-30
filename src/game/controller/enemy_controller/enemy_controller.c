#include "../../../../include/game/controller/enemy_controller.h"

void remove_ennemys(Enemys *enemys);
void update_enemy_positions(Enemys *enemys);
void handle_enemy(Enemys *enemys);

static int last_generated_time = 0;

void handle_enemy_spawn(Enemys *enemys, int interval_seconds)
{
    int current_time = MLV_get_time();

    if (current_time - last_generated_time >= interval_seconds * 1000)
    {
        handle_enemy(enemys);
        last_generated_time = current_time;
    }
    remove_ennemys(enemys);
}

void remove_ennemys(Enemys *enemys)
{
    int i;

    for (i = 0; i < enemys->nb_enemy; ++i)
    {
        if (get_y(enemys->enemy[i].position) > WINDOW_HEIGHT)
        {
            enemys->nb_enemy--;

            if (i < enemys->nb_enemy)
            {
                enemys->enemy[i] = enemys->enemy[enemys->nb_enemy];
            }
        }
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

void handle_enemy(Enemys *enemys)
{
    if (enemys->nb_enemy < MAX_ENEMYS)
    {
        enemys->enemy[enemys->nb_enemy] = construct_enemy();
        enemys->nb_enemy++;
    }
}
