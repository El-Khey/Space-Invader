
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

    /** TODO : a supprier les moteurs ce change depuis l'ecran */
    if (event_manager.keyboard_manager.event[0].attack_keys.key_attack_2)
    {
        heros->active_engine = (heros->active_engine + 1) % nb_engine_animations;
    }

    if (event_manager.keyboard_manager.event[0].attack_keys.key_attack_3)
    {
        heros->active_weapon = (heros->active_weapon + 1) % nb_weapon;
        heros->list.active_bullet_type = heros->active_weapon;
    }
}

static void remove_out_of_screen_projectiles(Heros *heros, int index_projectile, int index_bullet)
{
    if (!is_position_with_dimension_inside_rect(heros->list.projectiles[index_projectile].list.bullets[index_bullet].position, heros->list.projectiles[index_projectile].list.bullets[index_bullet].dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)))
    {
        /** Move the last bullet to the position of the removed bullet */
        heros->list.projectiles[index_projectile].list.bullets_count--;
        heros->list.projectiles[index_projectile].list.bullets[index_bullet] = heros->list.projectiles[index_projectile].list.bullets[heros->list.projectiles[index_projectile].list.bullets_count];

        /** If there are no bullets left in the projectile, remove the projectile */
        if (heros->list.projectiles[index_projectile].list.bullets_count == 0)
        {
            /** Move the last projectile to the position of the removed projectile */
            heros->list.projectiles_count--;
            heros->list.projectiles[index_projectile] = heros->list.projectiles[heros->list.projectiles_count];
        }
    }
}

void handle_heros_projectiles(Heros *heros, EventManager event_manager)
{
    int i, j;
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

    for (i = 0; i < heros->list.projectiles_count; i++)
    {
        for (j = 0; j < heros->list.projectiles[i].list.bullets_count; j++)
        {
            remove_out_of_screen_projectiles(heros, i, j);
            if (MLV_get_time() >= heros->list.projectiles[i].list.bullets[j].start_fire_time)
            {
                move_position(&heros->list.projectiles[i].list.bullets[j].position, 0, -heros->list.projectiles[i].speed);
            }
        }
    }
}