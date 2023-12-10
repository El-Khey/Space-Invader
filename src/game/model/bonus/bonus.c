#include "../../../../include/game/model/bonus/bonus.h"

static void initialize_bonus(Bonus *bonus);

Bonus construct_bonus(BonusType type)
{
    Bonus bonus;

    bonus.type = type;
    bonus.dimension = construct_dimension(100, 100);
    bonus.position = construct_position(rand() % (WINDOW_WIDTH - bonus.dimension.width), -bonus.dimension.height);

    bonus.is_selected = 0;
    bonus.speed = 4;

    initialize_bonus(&bonus);
    return bonus;
}

void load_bonus_backup(Bonus *bonus)
{
    initialize_bonus(bonus);
}

static void initialize_bonus(Bonus *bonus)
{
    switch (bonus->type)
    {
    case BONUS_TYPE_LIFE:
        bonus->hitbox = construct_hitbox(bonus->position, bonus->dimension);
        bonus->animation = construct_animation("assets/sprites/Pickups/Bonus/heart.png", 1, bonus->dimension, FORWARD);

        break;

    case BONUS_TYPE_SHIELD_ALL_AROUND:
        bonus->hitbox = construct_hitbox(bonus->position, bonus->dimension);
        bonus->animation = construct_animation("assets/sprites/Pickups/Shields/All around.png", 15, bonus->dimension, FORWARD);

        break;

    case BONUS_TYPE_SHIELD_FRONT_AND_SIDE:
        bonus->hitbox = construct_hitbox(bonus->position, bonus->dimension);
        bonus->animation = construct_animation("assets/sprites/Pickups/Shields/Front and Side.png", 15, bonus->dimension, FORWARD);

        break;

    case BONUS_TYPE_SHIELD_FRONT:
        bonus->hitbox = construct_hitbox(bonus->position, bonus->dimension);
        bonus->animation = construct_animation("assets/sprites/Pickups/Shields/Front.png", 15, bonus->dimension, FORWARD);

        break;

    case BONUS_TYPE_SHIELD_INVINCIBILITY:
        bonus->hitbox = construct_hitbox(bonus->position, bonus->dimension);
        bonus->animation = construct_animation("assets/sprites/Pickups/Shields/Invincibility.png", 15, bonus->dimension, FORWARD);

        break;

    default:
        fprintf(stderr, "Error Bonus : unknown bonus type\n");
        break;
    }

    play_animation(&bonus->animation);
}

int is_bonus_selected(Bonus bonus)
{
    return bonus.is_selected;
}

void move_bonus(Bonus *bonus)
{
    move_position(&bonus->position, 0, bonus->speed);
    move_position(&bonus->hitbox.position, 0, bonus->speed);
}

void draw_bonus(Bonus bonus)
{
    draw_animation(bonus.animation, bonus.position);
}

void free_bonus(Bonus *bonus)
{
    free_animation(&bonus->animation);
}