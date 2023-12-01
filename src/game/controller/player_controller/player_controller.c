
#include "../../../../include/game/controller/player_controller.h"

static void handle_heros_movement(Heros *heros, EventManager event_manager)
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

    /** TODO : a supprimer les moteurs se change depuis l'ecran */
    if (event_manager.keyboard_manager.event[0].attack_keys.key_attack_2)
    {
        heros->active_engine = (heros->active_engine + 1) % nb_engine_animations;
    }

    if (event_manager.keyboard_manager.event[0].attack_keys.key_attack_3)
    {
        heros->active_weapon = (heros->active_weapon + 1) % 4;
        heros->list.active_bullet_type = heros->active_weapon;
    }
}

static void handle_heros_projectiles(Heros *heros, EventManager event_manager)
{
    if (event_manager.keyboard_manager.event[0].attack_keys.key_attack_1 && heros->list.projectiles_count < MAX_PROJECTILES)
    {
        if (!heros->is_firing)
        {
            play_animation(&heros->weapons_animations[heros->active_weapon].weapon_shooting);
            heros->is_firing = 1;

            heros->list.projectiles[heros->list.projectiles_count] = construct_projectile(heros->position, heros->dimension, heros->list.active_bullet_type);
            heros->list.projectiles_count += 1;
        }
    }

    if (is_animation_finished(heros->weapons_animations[heros->active_weapon].weapon_shooting, MLV_get_time()) && heros->is_firing)
    {
        rewind_animation(&heros->weapons_animations[heros->active_weapon].weapon_shooting);
        stop_animation(&heros->weapons_animations[heros->active_weapon].weapon_shooting);

        heros->is_firing = 0;
    }

    update_projectiles(&heros->list);
}

void update_heros(Heros *heros, EventManager event_manager)
{
    handle_heros_movement(heros, event_manager);
    handle_heros_projectiles(heros, event_manager);
    draw_heros(*heros);
}