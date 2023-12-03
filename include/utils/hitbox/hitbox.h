#ifndef HITBOX_H
#define HITBOX_H

#include "../position/position.h"
#include "../dimension/dimension.h"
#include "../utils.h"

typedef struct
{
    Position position;
    Dimension dimension;

    int is_colliding;
} Hitbox;

/**
 * @brief Construct a new Hitbox object
 *
 * @param position
 * @param dimension
 * @return Hitbox
 */
Hitbox construct_hitbox(Position position, Dimension dimension);

/**
 * @brief Check if the given hitbox is colliding with the other given hitbox
 *
 * @param hitbox1 The first hitbox to check
 * @param hitbox2 The second hitbox to check
 * @return int
 */
int is_hitbox_colliding(Hitbox hitbox1, Hitbox hitbox2);

/**
 * @brief Check if the given position is inside the given hitbox
 *
 * @param hitbox The hitbox to check
 * @param position The position to check
 * @return int
 */
int is_position_inside_hitbox(Hitbox hitbox, Position position);

/**
 * @brief Set the hitbox position object
 *
 * @param hitbox The hitbox to set the position
 * @param position The position to set
 */
void set_hitbox_position(Hitbox *hitbox, Position position);

/**
 * @brief Set the hibtox dimension object
 *
 * @param hitbox The hitbox to set the dimension
 * @param dimension The dimension to set
 */
void set_hibtox_dimension(Hitbox *hitbox, Dimension dimension);

/**
 * @brief Draw the given hitbox on the screen
 *
 * @param hitbox The hitbox to draw
 * @param color The color to draw the hitbox
 */
void draw_hitbox(Hitbox hitbox, MLV_Color color);

#endif