#ifndef HEROS_H
#define HEROS_H

#include <stdio.h>
#include <stdlib.h>

#include "../../utils/position/position.h"
#include "../../utils/dimension/dimension.h"
#include "./projectile.h"
#include "../../utils/animation/animation.h"

#define MAX_PROJECTILES 200

typedef struct
{
    Projectile projectiles[MAX_PROJECTILES];
    int projectiles_count;
} Projectiles;

typedef enum
{
    BASE_ENGINE,
    BIG_PULSE_ENGINE,
    BURST_ENGINE,
    SUPERCHARGED_ENGINE,
    nb_engine_animations
} EngineType;

typedef struct
{
    Animation engine;
    Animation engine_effect_idle;
    Animation engine_effect_boost;
} EngineAnimation;

typedef struct
{
    Position position;
    Dimension dimension;

    Animation ship;

    EngineAnimation engine_animations[nb_engine_animations];
    EngineType active_engine;

    Projectiles list;

    int is_boost_activated;
    int speed;
} Heros;

Heros construct_heros();

void move_heros_up(Heros *heros);

void move_heros_down(Heros *Heros);

void move_heros_left(Heros *Heros);

void move_heros_right(Heros *Heros);

void draw_heros(Heros heros);

#endif