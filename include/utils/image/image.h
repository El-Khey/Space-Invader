#ifndef IMAGE_H
#define IMAGE_H

#include "../position/position.h"
#include "../dimension/dimension.h"

#define MAX_CHARACTERS 250

typedef struct
{
    Dimension dimension;
    Position position;

    char path[MAX_CHARACTERS];

    MLV_Image *image;
} Image;

/**
 * @brief Load an image from a path and resize it to the given dimension.
 *
 * @param path The path to the image.
 * @param dimension The dimension to resize the image.
 * @return Image*
 */
Image load_image(char *path, Dimension dimension);

/**
 * @brief Mirror the image vertically.
 *
 * @param image The image to mirror.
 */
void vertical_image_mirror(Image *image);

/**
 * @brief Get the image dimension object
 *
 * @param image The image to get the dimension.
 * @param path The path to the image.
 * @return Dimension The dimension of the image.
 */
int is_image_loaded_successfully(MLV_Image *image, char *path);

/**
 * @brief Get the image dimension object
 *
 * @param image The image to get the dimension.
 * @return Dimension The dimension of the image.
 */
Dimension get_image_dimension(MLV_Image *image);

/**
 * @brief Set the image position object
 *
 * @param image The image to set the position.
 * @param position The position to set.
 */
void set_image_position(Image *image, Position position);

/**
 * @brief Set the image dimension object
 *
 * @param image The image to set the dimension.
 * @param dimension The dimension to set.
 */
void set_image_dimension(Image *image, Dimension dimension);

/**
 * @brief Free the image.
 *
 * @param image The image to free.
 */
void free_image(Image *image);

/**
 * @brief Draw the image.
 *
 * @param image The image to draw.
 */
void draw_image(Image *image);

#endif /** IMAGE_H */