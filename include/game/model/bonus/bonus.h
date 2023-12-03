#ifndef BONUS_H
#define BONUS_H

#include "../../../utils/animation/animation.h"
#include "../../../utils/hitbox/hitbox.h"

typedef enum
{
    BONUS_TYPE_LIFE,
    BONUS_TYPE_SHIELD_ALL_AROUND,
    BONUS_TYPE_SHIELD_FRONT_AND_SIDE,
    BONUS_TYPE_SHIELD_FRONT,
    BONUS_TYPE_SHIELD_INVINCIBILITY,
    nb_bonus_type
} BonusType;

typedef struct
{
    Position position;
    Dimension dimension;
    Hitbox hitbox;

    BonusType type;
    Animation animation;

    int is_selected;
    int speed;
} Bonus;

Bonus construct_bonus(BonusType type);

void move_bonus(Bonus *bonus);

int is_bonus_selected(Bonus bonus);

void draw_bonus(Bonus bonus);

#endif