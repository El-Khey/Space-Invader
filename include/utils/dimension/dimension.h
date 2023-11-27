#ifndef DIMENSION_H
#define DIMENSION_H

#include "../../main.h"

typedef struct
{
    int width;
    int height;
} Dimension;

/**
 * @brief Construct a Dimension object with the given width and height
 *
 * @param width The width of the dimension
 * @param height The height of the dimension
 * @return Dimension
 */
Dimension construct_dimension(int width, int height);

/**
 * @brief Resize the given dimension to the given width and height
 *
 * @param dimension The dimension to resize
 * @param width The width to resize the dimension
 * @param height The height to resize the dimension
 */
void resize_dimension(Dimension *dimension, int width, int height);

/**
 * @brief Get the width object
 *
 * @param dimension The dimension
 * @return int
 */
int get_width(Dimension dimension);

/**
 * @brief Get the height object
 *
 * @param dimension The dimension
 * @return int
 */
int get_height(Dimension dimension);

/**
 * @brief Set the width object
 *
 * @param dimension The dimension
 * @param width
 */
void set_width(Dimension *dimension, int width);

/**
 * @brief Set the height object
 *
 * @param dimension The dimension
 * @param height
 */
void set_height(Dimension *dimension, int height);

/**
 * @brief
 *
 * @param dimension
 * @param factor
 * @return Dimension
 */
Dimension scale_down_dimension(Dimension dimension, int factor);

/**
 * @brief Print the given dimension on the screen
 * The dimension is printed in the following format: Dimension: widthxheight
 * Should be used for debugging purposes only
 *
 * @param dimension The dimension to print
 */
void print_dimension(Dimension dimension);

#endif /** DIMENSION_H */