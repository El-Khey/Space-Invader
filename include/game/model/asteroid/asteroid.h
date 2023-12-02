#ifndef ASTEROID_H
#define ASTEROID_H

#include "../../../utils/animation/animation.h"
#include "../../../utils/hitbox/hitbox.h"
#include "../../model/enemy/enemy.h"

typedef enum
{
    NONE,
    EXPLODE,
    nb_asteroid_animation
} AsteroidAnimation;

typedef struct
{
    Animation animation[nb_asteroid_animation];
    AsteroidAnimation current_animation;

    Animation effect_animation;

    Hitbox hitbox;
    Position position;
    Dimension dimension;

    int speed;
    int health;
    int damage;

    int event_in_process;
    Position trajectory;
} Asteroid;

Asteroid construct_asteroid();

void move_asteroid(Asteroid *asteroid);

int is_asteroid_dead(Asteroid asteroid);

void draw_asteroid(Asteroid asteroid);

#endif