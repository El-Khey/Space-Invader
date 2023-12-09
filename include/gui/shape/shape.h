#ifndef SHAPE_H
#define SHAPE_H

#include <MLV/MLV_all.h>

#include "../../utils/dimension/dimension.h"
#include "../../utils/position/position.h"

typedef struct
{
    Position position;
    Dimension dimension;

    MLV_Color color;
} Rectangle;

typedef Rectangle Shape;

Rectangle construct_rectangle(Position position, Dimension dimension, MLV_Color color);

void draw_rectangle(Rectangle rectangle);

/**
 * @brief Draw a gradient rectangle
 *
 * @param x1 The x position of the first point
 * @param y1 The y position of the first point
 * @param x2 The x position of the second point
 * @param y2 The y position of the second point
 * @param color1 The first color
 * @param color2 The second color
 */
void draw_gradient_rectangle(Position position1, Position position2, MLV_Color color1, MLV_Color color2);

/**
 * @brief Draw a vertical gradient rectangle
 *
 * @param x1 The x position of the first point
 * @param y1 The y position of the first point
 * @param x2 The x position of the second point
 * @param y2 The y position of the second point
 * @param color1 The first color
 * @param color2 The second color
 */
void draw_vertical_gradient_rectangle(Position position1, Position position2, MLV_Color color1, MLV_Color color2);

/**
 * @brief Draw a rounded filled rectangle
 *
 * @param position The position of the rectangle
 * @param dimension The dimension of the rectangle
 * @param corner_radius The corner radius
 * @param color The color of the rectangle
 */
void draw_rounded_filled_rectangle(Position position, Dimension dimension, int corner_radius, MLV_Color color);

/**
 * @brief Draw a border
 *
 * @param position The position of the border
 * @param dimension The dimension of the border
 * @param border_width The width of the border
 * @param color The color of the border
 */
void draw_border(Position position, Dimension dimension, int border_width, MLV_Color color);

/**
 * @brief Draw a cross
 *
 * @param position The position of the cross
 * @param dimension The dimension of the cross
 * @param border_width The width of the cross
 * @param color The color of the cross
 */
void draw_cross(Position position, Dimension dimension, int border_width, MLV_Color color);

/**
 * @brief Draw a rectangle
 *
 * @param position The position of the rectangle
 * @param dimension The dimension of the rectangle
 * @param color The color of the rectangle
 */
void draw_rectangle_outline(Position position, Dimension dimension, int border_width, MLV_Color color);

/**
 * @brief Draw a filled rectangle
 *
 * @param position The position of the rectangle
 * @param dimension The dimension of the rectangle
 * @param border_width The width of the rectangle
 * @param border_width_color The color of the rectangle
 * @param color The color of the rectangle
 */
void draw_filled_rectangle(Position position, Dimension dimension, int border_width, MLV_Color border_width_color, MLV_Color color);

/**
 * @brief Draw a filled rectangle with padding
 *
 * @param position The position of the rectangle
 * @param dimension The dimension of the rectangle
 * @param border_width The width of the rectangle
 * @param border_width_color The color of the rectangle
 * @param color The color of the rectangle
 * @param padding The padding of the rectangle
 */
void draw_filled_rectangle_with_padding(Position position, Dimension dimension, int border_width, MLV_Color border_width_color, MLV_Color color, int padding);

/**
 * @brief Draw a rounded filled rectangle with padding
 *
 * @param position The position of the rectangle
 * @param dimension The dimension of the rectangle
 * @param corner_radius The corner radius
 * @param color The color of the rectangle
 * @param padding The padding of the rectangle
 */
void draw_rounded_filled_rectangle_with_padding(Position position, Dimension dimension, int corner_radius, MLV_Color color, int padding);

/**
 * @brief Draw a filled circle
 *
 * @param position The position of the circle
 * @param radius The radius of the circle
 * @param color The color of the circle
 */
void draw_filled_circle_with_padding(Position position, int radius, MLV_Color color);

#endif