#ifndef SHIELD_H
#define SHIELD_H

#include "../../utils/animation/animation.h"
#include "../../utils/hitbox/hitbox.h"

typedef enum
{
    SHIELD_NONE,
    SHIELD_ALL_AROUND,
    SHIELD_FRONT_AND_SIDE,
    SHIELD_FRONT,
    SHIELD_INVINCIBILITY
} ShieldType;

typedef struct
{
    Animation animation;
    ShieldType type;

    int is_active;
    int active_time;
    int shield_duration;

    Position position;
    Dimension dimension;
} Shield;

Shield construct_shield(ShieldType bonus_type, Position position, Dimension dimension);

void load_shield_backup(Shield *shield);

void draw_shield(Shield shield);

#endif