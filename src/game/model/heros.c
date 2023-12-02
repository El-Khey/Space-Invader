#include "../../../include/game/model/heros.h"

static void initialize_engine_animations(EngineAnimation *engine_animations, Dimension dimension);
static void initialize_weapon_animation(Heros *heros, Dimension dimension);

Heros construct_heros()
{
    Heros heros;
    int hitbox_width, hitbox_height, hitbox_x, hitbox_y;

    heros.dimension = construct_dimension(150, 150);
    heros.position = construct_position(WINDOW_WIDTH / 2 - get_width(heros.dimension) / 2, WINDOW_HEIGHT - get_height(heros.dimension) - 25);

    hitbox_width = get_width(heros.dimension) - 50;
    hitbox_height = get_height(heros.dimension) - 50;
    hitbox_x = heros.position.x + (get_width(heros.dimension) - hitbox_width) / 2;
    hitbox_y = heros.position.y + (get_height(heros.dimension) - hitbox_height) / 2;

    heros.hitbox = construct_hitbox(construct_position(hitbox_x, hitbox_y), construct_dimension(hitbox_width, hitbox_height));
    heros.speed = 10;

    heros.list.active_bullet_type = AUTO_CANNON;
    heros.list.projectiles_count = 0;
    heros.is_boost_activated = 0;

    heros.ship = construct_animation("assets/sprites/Ships/MainShip/Bases/Full health.png", 1, heros.dimension, FORWARD);

    initialize_engine_animations(heros.engine_animations, heros.dimension);
    heros.active_engine = BASE_ENGINE;

    initialize_weapon_animation(&heros, heros.dimension);
    heros.active_weapon = AUTO_CANNON;

    heros.is_firing = 0;
    heros.health = 100;

    return heros;
}

static void initialize_engine_animations(EngineAnimation *engine_animations, Dimension dimension)
{
    engine_animations[BASE_ENGINE].engine = construct_animation("assets/sprites/Ships/MainShip/Engines/Base Engine.png", 1, dimension, FORWARD);
    engine_animations[BASE_ENGINE].engine_effect_idle = construct_animation("assets/sprites/Ships/MainShip/Engine Effects/Base Engine - Idle.png", 3, dimension, FORWARD);
    engine_animations[BASE_ENGINE].engine_effect_boost = construct_animation("assets/sprites/Ships/MainShip/Engine Effects/Base Engine - Powering.png", 4, dimension, FORWARD);

    play_animation(&engine_animations[BASE_ENGINE].engine_effect_idle);
    play_animation(&engine_animations[BASE_ENGINE].engine_effect_boost);

    engine_animations[BIG_PULSE_ENGINE].engine = construct_animation("assets/sprites/Ships/MainShip/Engines/Big Pulse Engine.png", 1, dimension, FORWARD);
    engine_animations[BIG_PULSE_ENGINE].engine_effect_idle = construct_animation("assets/sprites/Ships/MainShip/Engine Effects/Big Pulse Engine - Idle.png", 4, dimension, FORWARD);
    engine_animations[BIG_PULSE_ENGINE].engine_effect_boost = construct_animation("assets/sprites/Ships/MainShip/Engine Effects/Big Pulse Engine - Powering.png", 4, dimension, FORWARD);

    play_animation(&engine_animations[BIG_PULSE_ENGINE].engine_effect_idle);
    play_animation(&engine_animations[BIG_PULSE_ENGINE].engine_effect_boost);

    engine_animations[BURST_ENGINE].engine = construct_animation("assets/sprites/Ships/MainShip/Engines/Burst Engine.png", 1, dimension, FORWARD);
    engine_animations[BURST_ENGINE].engine_effect_idle = construct_animation("assets/sprites/Ships/MainShip/Engine Effects/Burst Engine - Idle.png", 7, dimension, FORWARD);
    engine_animations[BURST_ENGINE].engine_effect_boost = construct_animation("assets/sprites/Ships/MainShip/Engine Effects/Burst Engine - Powering.png", 6, dimension, FORWARD);

    play_animation(&engine_animations[BURST_ENGINE].engine_effect_idle);
    play_animation(&engine_animations[BURST_ENGINE].engine_effect_boost);

    engine_animations[SUPERCHARGED_ENGINE].engine = construct_animation("assets/sprites/Ships/MainShip/Engines/Supercharged Engine.png", 1, dimension, FORWARD);
    engine_animations[SUPERCHARGED_ENGINE].engine_effect_idle = construct_animation("assets/sprites/Ships/MainShip/Engine Effects/Supercharged Engine - Idle.png", 4, dimension, FORWARD);
    engine_animations[SUPERCHARGED_ENGINE].engine_effect_boost = construct_animation("assets/sprites/Ships/MainShip/Engine Effects/Supercharged Engine - Powering.png", 4, dimension, FORWARD);

    play_animation(&engine_animations[SUPERCHARGED_ENGINE].engine_effect_idle);
    play_animation(&engine_animations[SUPERCHARGED_ENGINE].engine_effect_boost);
}

static void initialize_weapon_animation(Heros *heros, Dimension dimension)
{
    heros->weapons_animations[AUTO_CANNON].weapon_shooting = construct_animation("assets/sprites/Ships/MainShip/Weapons/Auto Cannon.png", 7, dimension, FORWARD);
    heros->weapons_animations[BIG_SPACE].weapon_shooting = construct_animation("assets/sprites/Ships/MainShip/Weapons/Big Space Gun.png", 6, dimension, FORWARD);
    heros->weapons_animations[ROCKETS].weapon_shooting = construct_animation("assets/sprites/Ships/MainShip/Weapons/Rockets.png", 17, dimension, FORWARD);
    heros->weapons_animations[ZAPPER].weapon_shooting = construct_animation("assets/sprites/Ships/MainShip/Weapons/Zapper.png", 7, dimension, FORWARD);
}

void move_heros_up(Heros *heros)
{
    move_position(&heros->hitbox.position, 0, -heros->speed);
    move_position(&heros->position, 0, -heros->speed);
}

void move_heros_down(Heros *heros)
{
    move_position(&heros->hitbox.position, 0, heros->speed);
    move_position(&heros->position, 0, heros->speed);
}

void move_heros_left(Heros *heros)
{
    move_position(&heros->hitbox.position, -heros->speed, 0);
    move_position(&heros->position, -heros->speed, 0);
}

void move_heros_right(Heros *heros)
{
    move_position(&heros->hitbox.position, heros->speed, 0);
    move_position(&heros->position, heros->speed, 0);
}

static void draw_heros_projectiles(Projectiles list)
{
    int i = 0;
    for (; i < list.projectiles_count; i++)
    {
        draw_projectile(list.projectiles[i]);
    }
}

void draw_heros(Heros heros)
{
    draw_hitbox(heros.hitbox, MLV_COLOR_RED);
    draw_heros_projectiles(heros.list);

    draw_animation(heros.engine_animations[heros.active_engine].engine, heros.position);
    (heros.is_boost_activated) ? draw_animation(heros.engine_animations[heros.active_engine].engine_effect_boost, heros.position)
                               : draw_animation(heros.engine_animations[heros.active_engine].engine_effect_idle, heros.position);

    draw_animation(heros.weapons_animations[heros.active_weapon].weapon_shooting, heros.position);
    draw_animation(heros.ship, heros.position);
}