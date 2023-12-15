#include "../../../../include/game/controller/collision_controller/collision_controller.h"
#include "../../../../include/game/controller/bonus_controller/bonus_controller.h"

bonus_controller construct_bonus_controller()
{
    bonus_controller bonus_controller;

    bonus_controller.last_bonus_spawn_time = 0;
    bonus_controller.delay_between_spawn = 10000;

    bonus_controller.bonus_spawned = 0;
    bonus_controller.bonus_spawn_count = MAX_BONUS_SPAWN_COUNT;

    return bonus_controller;
}

void generate_bonus(bonus_controller *controller)
{
    if (controller->last_bonus_spawn_time + controller->delay_between_spawn < MLV_get_time() && controller->bonus_spawned < controller->bonus_spawn_count)
    {
        controller->last_bonus_spawn_time = MLV_get_time();
        controller->bonus[controller->bonus_spawned] = construct_bonus(rand() % nb_bonus_type);
        controller->bonus_spawned++;
    }
}

static void handle_bonus_selection(bonus_controller *controller, int index)
{
    if (is_bonus_selected(controller->bonus[index]))
    {
        controller->bonus_spawned--;
        controller->bonus[index] = controller->bonus[controller->bonus_spawned];
    }
}

static int is_bonus_out_of_screen(Bonus bonus)
{
    return bonus.position.x < -bonus.dimension.width || bonus.position.x > WINDOW_WIDTH + bonus.dimension.width || bonus.position.y > WINDOW_HEIGHT + bonus.dimension.height;
}

void update_bonus(bonus_controller *controller)
{
    int i = 0;
    for (; i < controller->bonus_spawned; i++)
    {
        move_bonus(&controller->bonus[i]);
        draw_bonus(controller->bonus[i]);
        handle_bonus_selection(controller, i);

        if (is_bonus_out_of_screen(controller->bonus[i]))
        {
            controller->bonus_spawned--;
            controller->bonus[i] = controller->bonus[controller->bonus_spawned];
        }
    }
}

void free_bonus_controller(bonus_controller *controller)
{
    int i = 0;
    for (; i < controller->bonus_spawned; i++)
    {
        free_bonus(&controller->bonus[i]);
    }
}