#ifndef ANIMATION_H
#define ANIMATION_H

#include <MLV/MLV_all.h>
#include "./animation_infos.h"

#include "../position/position.h"
#include "../dimension/dimension.h"
#include "../image/image.h"

typedef struct
{
    MLV_Image *sprite;            /** MLV_Image structure to store the sprite */
    MLV_Image **frames;           /** MLV_Image structure to store the frames of the animation */
    MLV_Animation *animation;     /** MLV_Animation structure to store the */
    MLV_Animation_player *player; /** MLV_Animation_player structure to play the animation */

    int frame_count;    /** Number of frames in the animation */
    int frame_duration; /** Duration of each frame in milliseconds */

    int nb_layers;   /** Number of layers of the animation */
    int nb_channels; /** Number of channels of the animation */

    int frame_rate; /** Frame rate of the animation */
    int layer;      /** Layer of the animation */

    int start_time; /** Start time of the animation */
    int end_time;   /** End time of the animation */

    Dimension dimension;          /** Dimension of the animation */
    AnimationDirection direction; /** Direction of the animation */
} Animation;

/**
 * @brief Construct a new Animation object from a file
 * The animation is loaded from the given file and the given parameters
 *
 * @param animation_file The file to load the animation from
 * @param frame_count The number of frames in the animation
 * @param dimension The dimension of the animation
 * @param direction The direction of the animation
 * @return Animation
 */
Animation construct_animation(char *path, int frame_count, Dimension dimension, AnimationDirection direction);

/**
 * @brief Resize the given animation to the given dimension
 *
 * @param animation The animation to resize
 * @param dimension The dimension to resize the animation
 */
void resize_animation(Animation *animation, Dimension dimension);

/**
 * @brief Play the given animation forward
 *
 * @param animation The animation to play
 */
void play_animation(Animation *animation);

/**
 * @brief Play the given animation backward
 *
 * @param animation The animation to play
 */
void play_revert_animation(Animation *animation);

/**
 * @brief Stop the given animation
 *
 * @param animation The animation to stop
 */
void stop_animation(Animation *animation);

/**
 * @brief Rewind the animation
 *
 * @param animation The animation to rewind
 */
void rewind_animation(Animation *animation);

/**
 * @brief Check if the given animation is finished
 *
 * @param animation The animation to check
 * @param current_time The current time
 */
int is_animation_finished(Animation animation, int current_time);

/**
 * @brief Draw the given animation at the given position
 *
 * @param animation The animation to draw
 * @param position The position to draw the animation
 */
void draw_animation(Animation animation, Position position);

/**
 * @brief Free the given animation
 *
 * @param animation The animation to free
 */
void free_animation(Animation *animation);

#endif /** ANIMATION_H */
