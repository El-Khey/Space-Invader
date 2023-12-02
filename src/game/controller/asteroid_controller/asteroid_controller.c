#include "../../../../include/game/controller/collision_controller/collision_controller.h"
#include "../../../../include/game/controller/asteroid_controller/asteroid_controller.h"

asteroid_controller construct_asteroid_controller()
{
    asteroid_controller asteroid_controller;

    asteroid_controller.last_asteroid_spawn_time = 0;
    asteroid_controller.delay_between_spawn = 2000;

    asteroid_controller.asteroid_spawned = 0;
    asteroid_controller.asteroid_spawn_count = MAX_ENEMY_SPAWN_COUNT;

    return asteroid_controller;
}

void generate_asteroids(asteroid_controller *controller)
{
    if (controller->last_asteroid_spawn_time + controller->delay_between_spawn < MLV_get_time() && controller->asteroid_spawned < controller->asteroid_spawn_count)
    {
        controller->last_asteroid_spawn_time = MLV_get_time();
        controller->asteroids[controller->asteroid_spawned] = construct_asteroid();
        controller->asteroid_spawned++;
    }
}

static void handle_asteroid_death(asteroid_controller *controller, int index)
{
    if (is_asteroid_dead(controller->asteroids[index]))
    {
        if (controller->asteroids[index].event_in_process != DYING)
        {
            controller->asteroids[index].event_in_process = DYING;
            controller->asteroids[index].current_animation = EXPLODE;

            play_animation(&controller->asteroids[index].animation[controller->asteroids[index].current_animation]);
        }

        if (is_animation_finished(controller->asteroids[index].animation[controller->asteroids[index].current_animation], MLV_get_time()) && controller->asteroids[index].event_in_process == DYING)
        {
            controller->asteroid_spawned--;
            controller->asteroids[index] = controller->asteroids[controller->asteroid_spawned];
            controller->asteroids[index].event_in_process = NOTHING;
        }
    }
}

static int is_asteroid_out_of_screen(Asteroid asteroid)
{
    return asteroid.position.x < -asteroid.dimension.width || asteroid.position.x > WINDOW_WIDTH + asteroid.dimension.width || asteroid.position.y > WINDOW_HEIGHT + asteroid.dimension.height;
}

void update_asteroids(asteroid_controller *controller)
{
    int i = 0;
    for (; i < controller->asteroid_spawned; i++)
    {
        move_asteroid(&controller->asteroids[i]);
        draw_asteroid(controller->asteroids[i]);

        handle_asteroid_death(controller, i);

        if (is_asteroid_out_of_screen(controller->asteroids[i]))
        {
            controller->asteroid_spawned--;
            controller->asteroids[i] = controller->asteroids[controller->asteroid_spawned];
        }
    }
}