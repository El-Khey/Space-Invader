#include "../../../include/game/model/heros.h"

static void initialize_engine_animations(EngineAnimation *engine_animations, Dimension dimension);

Heros construct_heros()
{
    Heros heros;

    heros.dimension = construct_dimension(150, 150);
    heros.position = construct_position(WINDOW_WIDTH / 2 - get_width(heros.dimension) / 2, WINDOW_HEIGHT - get_height(heros.dimension) - 25);
    heros.speed = 3;

    heros.list.projectiles_count = 0;
    heros.is_boost_activated = 0;

    heros.ship = construct_animation("assets/sprites/Ships/MainShip/Bases/Full health.png", 1, heros.dimension, FORWARD);
    initialize_engine_animations(heros.engine_animations, heros.dimension);
    heros.active_engine = BASE_ENGINE;

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

void move_heros_up(Heros *heros)
{
    move_position(&heros->position, 0, -heros->speed);
}

void move_heros_down(Heros *Heros)
{
    move_position(&Heros->position, 0, Heros->speed);
}

void move_heros_left(Heros *Heros)
{
    move_position(&Heros->position, -Heros->speed, 0);
}

void move_heros_right(Heros *Heros)
{
    move_position(&Heros->position, Heros->speed, 0);
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
    draw_heros_projectiles(heros.list);

    draw_animation(heros.engine_animations[heros.active_engine].engine, heros.position);
    (heros.is_boost_activated) ? draw_animation(heros.engine_animations[heros.active_engine].engine_effect_boost, heros.position)
                               : draw_animation(heros.engine_animations[heros.active_engine].engine_effect_idle, heros.position);

    draw_animation(heros.ship, heros.position);
}