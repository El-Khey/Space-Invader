#include "../../../include/game/model/shield.h"

static void initialize_shield_from_type(Shield *shield);

Shield construct_shield(ShieldType type, Position position, Dimension dimension)
{
    Shield shield;

    shield.position = position;
    shield.dimension = dimension;

    shield.type = type;
    initialize_shield_from_type(&shield);

    return shield;
}

void load_shield_backup(Shield *shield)
{
    initialize_shield_from_type(shield);
}

static void initialize_shield_from_type(Shield *shield)
{
    switch (shield->type)
    {
    case SHIELD_ALL_AROUND:
        shield->animation = construct_animation("assets/sprites/Ships/MainShip/Shields/All around.png", 12, shield->dimension, FORWARD);
        shield->shield_duration = 10000;
        shield->active_time = MLV_get_time() + shield->shield_duration;
        shield->is_active = 1;

        break;

    case SHIELD_FRONT_AND_SIDE:
        shield->animation = construct_animation("assets/sprites/Ships/MainShip/Shields/Front and Side.png", 6, shield->dimension, FORWARD);
        shield->shield_duration = 10000;
        shield->active_time = MLV_get_time() + shield->shield_duration;
        shield->is_active = 1;

        break;
    case SHIELD_FRONT:
        shield->animation = construct_animation("assets/sprites/Ships/MainShip/Shields/Front.png", 10, shield->dimension, FORWARD);
        shield->shield_duration = 10000;
        shield->active_time = MLV_get_time() + shield->shield_duration;
        shield->is_active = 1;

        break;
    case SHIELD_INVINCIBILITY:
        shield->animation = construct_animation("assets/sprites/Ships/MainShip/Shields/Invincibility.png", 10, shield->dimension, FORWARD);
        shield->shield_duration = 10000;
        shield->active_time = MLV_get_time() + shield->shield_duration;
        shield->is_active = 1;

        break;
    case SHIELD_NONE:
        shield->is_active = 0;
        break;

    default:
        fprintf(stderr, "Error: unknown shield type\n");
        break;
    }

    if (shield->is_active)
    {
        play_animation(&shield->animation);
    }
}

void draw_shield(Shield shield)
{
    if (shield.is_active)
    {
        draw_animation(shield.animation, shield.position);
    }
}

void free_shield(Shield *shield)
{
    if (shield->type != SHIELD_NONE)
    {
        free_animation(&shield->animation);
    }
}