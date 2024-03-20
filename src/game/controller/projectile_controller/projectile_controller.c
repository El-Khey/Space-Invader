#include "../../../../include/game/controller/projectile_controller/projectile_controller.h"

/**
 * @brief Removes projectiles that are out of the screen.
 *
 * This function checks if the position of a bullet is outside the dimensions of the screen.
 * If a bullet is outside the screen, it is removed from the list of projectiles.
 * If a projectile has no bullets left after removing one, the projectile itself is also removed.
 *
 * @param list The list of projectiles.
 * @param index_projectile The index of the projectile to check.
 * @param index_bullet The index of the bullet to check.
 */
static void remove_out_of_screen_projectiles(Projectiles *list, int index_projectile, int index_bullet)
{
    if (!is_position_with_dimension_inside_rect(list->projectiles[index_projectile].list.bullets[index_bullet].position, list->projectiles[index_projectile].list.bullets[index_bullet].dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)))
    {
        /** Move the last bullet to the position of the removed bullet */
        list->projectiles[index_projectile].list.bullets_count--;
        list->projectiles[index_projectile].list.bullets[index_bullet] = list->projectiles[index_projectile].list.bullets[list->projectiles[index_projectile].list.bullets_count];

        /** If there are no bullets left in the projectile, remove the projectile */
        if (list->projectiles[index_projectile].list.bullets_count == 0)
        {
            /** Move the last projectile to the position of the removed projectile */
            list->projectiles_count--;
            list->projectiles[index_projectile] = list->projectiles[list->projectiles_count];
        }
    }
}

void update_projectiles(Projectiles *list)
{
    int i, j;
    for (i = 0; i < list->projectiles_count; i++)
    {
        for (j = 0; j < list->projectiles[i].list.bullets_count; j++)
        {
            remove_out_of_screen_projectiles(list, i, j);
            if (MLV_get_time() >= list->projectiles[i].list.bullets[j].start_fire_time)
            {
                move_bullet(&list->projectiles[i].list.bullets[j], -list->projectiles[i].speed);
            }
        }
    }
}