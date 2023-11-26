
#include "../../../../include/game/controller/player_controller.h"

void handle_heros_movement(Heros *heros, EventManager event_manager)
{
    if (is_position_with_dimension_inside_rect(construct_position(heros->position.x + heros->speed, heros->position.y), heros->dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)) && event_manager.keyboard_manager.event[0].arrow_keys.key_right)
    {
        move_heros_right(heros);
    }
    if (is_position_with_dimension_inside_rect(construct_position(heros->position.x - heros->speed, heros->position.y), heros->dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)) && event_manager.keyboard_manager.event[0].arrow_keys.key_left)
    {
        move_heros_left(heros);
    }
    if (is_position_with_dimension_inside_rect(construct_position(heros->position.x, heros->position.y - heros->speed), heros->dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)) && event_manager.keyboard_manager.event[0].arrow_keys.key_up)
    {
        heros->is_boost_activated = 1;
        move_heros_up(heros);
    }
    else
    {
        heros->is_boost_activated = 0;
    }
    if (is_position_with_dimension_inside_rect(construct_position(heros->position.x, heros->position.y + heros->speed), heros->dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)) && event_manager.keyboard_manager.event[0].arrow_keys.key_down)
    {
        move_heros_down(heros);
    }
}

static void remove_out_of_screen_projectiles(Heros *heros, int index)
{
    int j;
    if (!is_position_with_dimension_inside_rect(heros->list.projectiles[index].position, heros->list.projectiles[index].dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)))
    {
        for (j = index; j < heros->list.projectiles_count; j++)
        {
            heros->list.projectiles[j] = heros->list.projectiles[j + 1];
        }
        heros->list.projectiles_count -= 1;
    }
}

void handle_heros_projectiles(Heros *heros, EventManager event_manager)
{
    int i = 0;
    if (event_manager.keyboard_manager.event[0].attack_keys.key_attack_1 && heros->list.projectiles_count < MAX_PROJECTILES)
    {
        heros->list.projectiles[heros->list.projectiles_count] = construct_projectile(heros->position, heros->dimension);
        heros->list.projectiles_count += 1;
    }

    for (; i < heros->list.projectiles_count; i++)
    {
        move_position(&heros->list.projectiles[i].position, 0, -heros->list.projectiles[i].speed);
        remove_out_of_screen_projectiles(heros, i);
    }
}