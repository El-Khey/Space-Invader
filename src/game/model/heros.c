#include "../../../include/game/model/heros.h"

static void initialize_engine_animations(EngineAnimation *engine_animations, Dimension dimension);
static void initialize_weapon_animation(Heros *heros, Dimension dimension);

Heros construct_heros(Position position, Dimension dimension)
{
    Heros heros;
    int hitbox_width, hitbox_height, hitbox_x, hitbox_y;

    heros.dimension = dimension;
    heros.position = position;

    hitbox_width = get_width(heros.dimension) - 50;
    hitbox_height = get_height(heros.dimension) - 50;
    hitbox_x = heros.position.x + (get_width(heros.dimension) - hitbox_width) / 2;
    hitbox_y = heros.position.y + (get_height(heros.dimension) - hitbox_height) / 2;

    heros.hitbox = construct_hitbox(construct_position(hitbox_x, hitbox_y), construct_dimension(hitbox_width, hitbox_height));
    heros.speed = 10;

    heros.list.active_bullet_type = AUTO_CANNON;
    heros.list.projectiles_count = 0;
    heros.is_boost_activated = 0;

    heros.ship[FULL_HEALTH] = construct_animation("assets/sprites/Ships/MainShip/Bases/Full health.png", 1, heros.dimension, FORWARD);
    heros.ship[SLIGHTLY_DAMAGED] = construct_animation("assets/sprites/Ships/MainShip/Bases/Slight damage.png", 1, heros.dimension, FORWARD);
    heros.ship[DAMAGED] = construct_animation("assets/sprites/Ships/MainShip/Bases/Damaged.png", 1, heros.dimension, FORWARD);
    heros.ship[VERY_DAMAGED] = construct_animation("assets/sprites/Ships/MainShip/Bases/Very damaged.png", 1, heros.dimension, FORWARD);

    heros.active_ship = FULL_HEALTH;

    initialize_engine_animations(heros.engine_animations, heros.dimension);
    heros.active_engine = BASE_ENGINE;

    initialize_weapon_animation(&heros, heros.dimension);
    heros.active_weapon = AUTO_CANNON;

    heros.is_firing = 0;
    heros.health = MAX_PLAYER_LIFE;

    heros.shield = construct_shield(SHIELD_NONE, heros.position, heros.dimension);
    return heros;
}

void load_heros_backup(Heros *heros)
{
    int i = 0;
    heros->ship[FULL_HEALTH] = construct_animation("assets/sprites/Ships/MainShip/Bases/Full health.png", 1, heros->dimension, FORWARD);
    heros->ship[SLIGHTLY_DAMAGED] = construct_animation("assets/sprites/Ships/MainShip/Bases/Slight damage.png", 1, heros->dimension, FORWARD);
    heros->ship[DAMAGED] = construct_animation("assets/sprites/Ships/MainShip/Bases/Damaged.png", 1, heros->dimension, FORWARD);
    heros->ship[VERY_DAMAGED] = construct_animation("assets/sprites/Ships/MainShip/Bases/Very damaged.png", 1, heros->dimension, FORWARD);

    initialize_engine_animations(heros->engine_animations, heros->dimension);
    initialize_weapon_animation(heros, heros->dimension);

    load_shield_backup(&heros->shield);
    for (; i < heros->list.projectiles_count; i++)
    {
        load_heros_projectile_backup(&heros->list.projectiles[i], heros->position, heros->dimension);
    }
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

static void draw_heros_projectiles(Projectiles list)
{
    int i = 0;
    for (; i < list.projectiles_count; i++)
    {
        draw_projectile(list.projectiles[i]);
    }
}

void update_heros_active_ship(Heros *heros)
{
    if (heros->health <= MAX_PLAYER_LIFE && heros->health > MAX_PLAYER_LIFE * 0.75)
    {
        heros->active_ship = FULL_HEALTH;
    }
    else if (heros->health <= MAX_PLAYER_LIFE * 0.75 && heros->health > MAX_PLAYER_LIFE * 0.5)
    {
        heros->active_ship = SLIGHTLY_DAMAGED;
    }
    else if (heros->health <= MAX_PLAYER_LIFE * 0.5 && heros->health > MAX_PLAYER_LIFE * 0.25)
    {
        heros->active_ship = DAMAGED;
    }
    else if (heros->health <= MAX_PLAYER_LIFE * 0.25 && heros->health > 0)
    {
        heros->active_ship = VERY_DAMAGED;
    }
    else if (heros->health <= 0)
    {
        heros->active_ship = FULL_HEALTH;
    }
}

int is_heros_alive(Heros heros)
{
    return heros.health > 0;
}

void draw_heros(Heros heros)
{
    draw_heros_projectiles(heros.list);

    draw_animation(heros.engine_animations[heros.active_engine].engine, heros.position);
    (heros.is_boost_activated) ? draw_animation(heros.engine_animations[heros.active_engine].engine_effect_boost, heros.position)
                               : draw_animation(heros.engine_animations[heros.active_engine].engine_effect_idle, heros.position);

    draw_animation(heros.weapons_animations[heros.active_weapon].weapon_shooting, heros.position);
    draw_animation(heros.ship[heros.active_ship], heros.position);

    draw_shield(heros.shield);
}

void free_heros(Heros *heros)
{
    int i;
    for (i = 0; i < nb_ship_health_state; i++)
    {
        free_animation(&heros->ship[i]);
    }

    for (i = 0; i < nb_engine_animations; i++)
    {
        free_animation(&heros->engine_animations[i].engine);
        free_animation(&heros->engine_animations[i].engine_effect_idle);
        free_animation(&heros->engine_animations[i].engine_effect_boost);
    }

    free_animation(&heros->weapons_animations[AUTO_CANNON].weapon_shooting);
    free_animation(&heros->weapons_animations[BIG_SPACE].weapon_shooting);
    free_animation(&heros->weapons_animations[ROCKETS].weapon_shooting);
    free_animation(&heros->weapons_animations[ZAPPER].weapon_shooting);

    for (i = 0; i < heros->list.projectiles_count; i++)
    {
        free_projectile(&heros->list.projectiles[i]);
    }

    free_shield(&heros->shield);
}