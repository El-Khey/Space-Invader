#include "../../../../include/game/model/enemy/enemy.h"

#include "../../../../include/game/model/enemy/klaed.h"
#include "../../../../include/game/model/enemy/nairan.h"
#include "../../../../include/game/model/enemy/nautolan.h"

static void initialize_enemy_class(Enemy *enemy);

Enemy construct_enemy(EnemyClass class)
{
    Enemy enemy;
    int hitbox_width, hitbox_height, hitbox_x, hitbox_y;

    enemy.dimension = construct_dimension(175, 175);
    enemy.position = construct_position(rand() % (WINDOW_WIDTH - get_width(enemy.dimension)), -get_height(enemy.dimension));

    hitbox_width = get_width(enemy.dimension) - 50;
    hitbox_height = get_height(enemy.dimension) - 50;
    hitbox_x = enemy.position.x + (get_width(enemy.dimension) - hitbox_width) / 2;
    hitbox_y = enemy.position.y + (get_height(enemy.dimension) - hitbox_height) / 2;

    enemy.hitbox = construct_hitbox(construct_position(hitbox_x, hitbox_y), construct_dimension(hitbox_width, hitbox_height));

    enemy.enemy_class = class;
    enemy.enemy_type = rand() % nb_enemy_type;
    enemy.enemy_animation.active_state = BASE;

    enemy.list.projectiles_count = 0;
    enemy.event_in_process = NOTHING;

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

int is_enemy_dead(Enemy enemy)
{
    return enemy.health <= 0;
}

void move_enemy(Enemy *enemy)
{
    move_position(&enemy->hitbox.position, 0, enemy->speed);
    move_position(&enemy->position, 0, enemy->speed);
}

static void draw_enemy_projectiles(Enemy enemy)
{
    int i = 0;
    for (; i < enemy.list.projectiles_count; i++)
    {
        draw_projectile(enemy.list.projectiles[i]);
    }
}

void draw_enemy(Enemy enemy)
{
    draw_hitbox(enemy.hitbox, MLV_COLOR_RED);

    draw_animation(enemy.enemy_animation.ship[enemy.enemy_animation.active_state], enemy.position);
    draw_animation(enemy.enemy_animation.engine_effect_boost, enemy.position);

    draw_enemy_projectiles(enemy);
}
