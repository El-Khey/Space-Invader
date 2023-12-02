#include "../../../../include/game/model/asteroid/asteroid.h"
#include <math.h>

Asteroid construct_asteroid()
{
    Asteroid asteroid;

    asteroid.dimension = construct_dimension(100, 100);
    asteroid.position = construct_position(rand() % (WINDOW_WIDTH - asteroid.dimension.width), -asteroid.dimension.height);
    asteroid.hitbox = construct_hitbox(asteroid.position, asteroid.dimension);

    asteroid.speed = rand() % 6 + 4;

    asteroid.animation[NONE] = construct_animation("assets/sprites/Environment/Asteroids/Base.png", 1, asteroid.dimension, ROTATION_90);
    asteroid.animation[EXPLODE] = construct_animation("assets/sprites/Environment/Asteroids/Explode.png", 8, asteroid.dimension, FORWARD);
    asteroid.effect_animation = construct_animation("assets/sprites/Environment/Asteroids/Flame.png", 3, asteroid.dimension, ROTATION_90);

    asteroid.current_animation = NONE;
    play_animation(&asteroid.effect_animation);

    asteroid.event_in_process = NOTHING;
    return asteroid;
}

void move_asteroid(Asteroid *asteroid)
{
    move_position(&asteroid->hitbox.position, 0, asteroid->speed);
    move_position(&asteroid->position, 0, asteroid->speed);
}

int is_asteroid_dead(Asteroid asteroid)
{
    return asteroid.health <= 0;
}

void draw_asteroid(Asteroid asteroid)
{
    draw_animation(asteroid.animation[asteroid.current_animation], asteroid.position);

    if (asteroid.event_in_process != DYING)
    {
        draw_animation(asteroid.effect_animation, asteroid.position);
    }
}
