#include "../../../include/utils/hitbox/hitbox.h"

Hitbox construct_hitbox(Position position, Dimension dimension)
{
    Hitbox hitbox;

    hitbox.position = position;
    hitbox.dimension = dimension;

    hitbox.is_colliding = 0;

    return hitbox;
}

int is_hitbox_colliding(Hitbox hitbox1, Hitbox hitbox2)
{
    return get_x(hitbox1.position) < get_x(hitbox2.position) + get_width(hitbox2.dimension) &&
           get_x(hitbox1.position) + get_width(hitbox1.dimension) > get_x(hitbox2.position) &&
           get_y(hitbox1.position) < get_y(hitbox2.position) + get_height(hitbox2.dimension) &&
           get_y(hitbox1.position) + get_height(hitbox1.dimension) > get_y(hitbox2.position);
}

int is_position_inside_hitbox(Hitbox hitbox, Position position)
{
    return get_x(position) >= get_x(hitbox.position) &&
           get_x(position) <= get_x(hitbox.position) + get_width(hitbox.dimension) &&
           get_y(position) >= get_y(hitbox.position) &&
           get_y(position) <= get_y(hitbox.position) + get_height(hitbox.dimension);
}

void set_hitbox_position(Hitbox *hitbox, Position position)
{
    hitbox->position = position;
}

void set_hibtox_dimension(Hitbox *hitbox, Dimension dimension)
{
    hitbox->dimension = dimension;
}

void draw_hitbox(Hitbox hitbox, MLV_Color color)
{
    MLV_draw_filled_rectangle(
        get_x(hitbox.position),
        get_y(hitbox.position),
        get_width(hitbox.dimension),
        get_height(hitbox.dimension),
        color);
}
