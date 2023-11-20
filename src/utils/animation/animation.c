#include "../../../include/utils/animation/animation.h"

#define FRAME_RATE 24

void init_animation_player(Animation *animation, Dimension dimension);

Animation construct_animation(char *path, int frame_count, Dimension dimension, AnimationDirection direction)
{
    Animation animation;

    animation.frame_count = frame_count;
    animation.direction = direction;

    animation.frame_duration = 4;

    animation.nb_channels = 1;
    animation.nb_layers = 1;
    animation.layer = 0;

    animation.start_time = 0;

    animation.sprite = MLV_load_image(path);
    is_image_loaded_successfully(animation.sprite, path);

    MLV_get_image_size(animation.sprite, &animation.dimension.width, &animation.dimension.height);
    set_width(&animation.dimension, (get_width(animation.dimension) / animation.frame_count));

    init_animation_player(&animation, dimension);

    return animation;
}

void init_animation_player(Animation *animation, Dimension dimension)
{
    int i = 0;
    animation->frames = (MLV_Image **)malloc(animation->frame_count * sizeof(MLV_Image *));
    animation->animation = MLV_create_animation(animation->frame_count, animation->nb_layers, animation->nb_channels);

    if (animation->direction == BACKWARD)
    {
        MLV_vertical_image_mirror(animation->sprite);
    }

    for (; i < animation->frame_count; i++)
    {
        animation->frames[i] = MLV_copy_partial_image(animation->sprite, i * get_width(animation->dimension), 0, get_width(animation->dimension), get_height(animation->dimension));
        MLV_resize_image(animation->frames[i], get_width(dimension), get_height(dimension));
        MLV_add_frame_in_animation(animation->frames + i, NULL, animation->frame_duration, animation->animation);
    }

    animation->player = MLV_create_animation_player(animation->animation);

    if (animation->direction == BACKWARD)
    {
        play_revert_animation(animation);
    }
}

void resize_animation(Animation *animation, Dimension dimension)
{
    int i = 0;
    for (; i < animation->frame_count; i++)
    {
        /** Create a new frame based on the resized dimension */
        MLV_Image *resized_frame = MLV_copy_partial_image(animation->sprite, i * get_width(animation->dimension), 0, get_width(animation->dimension), get_height(animation->dimension));
        MLV_resize_image(resized_frame, get_width(dimension), get_height(dimension));

        /** Free the original frame to avoid memory leaks */
        MLV_free_image(animation->frames[i]);

        /** Assign the new frame to the animation's frames array */
        animation->frames[i] = resized_frame;

        MLV_change_frame_in_animation(animation->frames + i, NULL, animation->frame_duration, animation->animation, i);
    }

    if (animation->direction == BACKWARD)
    {
        play_revert_animation(animation);
    }

    MLV_update_animation_player(animation->player);
}

void play_animation(Animation *animation)
{
    MLV_rewind_animation_player(animation->player);

    animation->start_time = MLV_get_time();
    animation->end_time = animation->start_time + (animation->frame_duration * animation->frame_count * MLV_get_frame_rate());

    MLV_play_animation_player(animation->player);
}

void play_revert_animation(Animation *animation)
{
    MLV_play_revert_animation_player(animation->player);
}

void stop_animation(Animation *animation)
{
    MLV_stop_animation_player(animation->player);
}

int is_animation_finished(Animation animation, int current_time)
{
    return current_time >= animation.end_time;
}

void draw_animation(Animation animation, Position position)
{
    MLV_update_animation_player(animation.player);

    MLV_draw_image_from_animation_player(animation.player, animation.layer, get_x(position), get_y(position));
    MLV_play_sound_from_animation_player(animation.player, 0);
}

void free_animation(Animation *animation)
{
    int i = 0;
    MLV_free_animation_player(animation->player);
    MLV_free_animation(animation->animation);

    for (; i < animation->frame_count; i++)
    {
        MLV_free_image(animation->frames[i]);
        animation->frames[i] = NULL;
    }

    free(animation->frames);
    MLV_free_image(animation->sprite);

    animation->frames = NULL;
    animation->sprite = NULL;
    animation->player = NULL;
    animation->animation = NULL;
}