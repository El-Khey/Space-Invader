#ifndef HEROS_H
#define HEROS_H

#include <stdio.h>
#include <stdlib.h>

#include "../../utils/dimension/dimension.h"
#include "../../utils/animation/animation.h"
#include "../../utils/position/position.h"
#include "../../utils/hitbox/hitbox.h"
#include "./projectile.h"

typedef enum
{
    BASE_ENGINE,
    BIG_PULSE_ENGINE,
    BURST_ENGINE,
    SUPERCHARGED_ENGINE,
    nb_engine_animations
} EngineType;

typedef enum
{
    FULL_HEALTH,
    SLIGHTLY_DAMAGED,
    DAMAGED,
    VERY_DAMAGED,
    nb_ship_health_state
} ShipHealthState;

typedef struct
{
    Animation engine;
    Animation engine_effect_idle;
    Animation engine_effect_boost;
} EngineAnimation;

typedef struct
{
    Animation weapon_shooting;
} WeaponAnimation;

typedef struct
{
    Hitbox hitbox;
    Position position;
    Dimension dimension;

    Animation ship[nb_ship_health_state];
    int active_ship;

    EngineAnimation engine_animations[nb_engine_animations];
    EngineType active_engine;

    WeaponAnimation weapons_animations[nb_weapon];
    Weapon_Type active_weapon;

    Projectiles list;

    int is_boost_activated;
    int is_firing;

    int speed;
    int health;
} Heros;

Heros construct_heros();

void move_heros_up(Heros *heros);

void move_heros_down(Heros *heros);

void move_heros_left(Heros *heros);

void move_heros_right(Heros *heros);

void update_heros_active_ship(Heros *heros);

void draw_heros(Heros heros);

#endif