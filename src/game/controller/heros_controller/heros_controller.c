
#include "../../../../include/game/controller/heros_controller.h"

void move_heros_up(Heros *heros)
{
    move_position(&heros->hitbox.position, 0, -heros->speed);
    move_position(&heros->position, 0, -heros->speed);
}

void move_heros_down(Heros *heros)
{
    move_position(&heros->hitbox.position, 0, heros->speed);
    move_position(&heros->position, 0, heros->speed);
}

void move_heros_left(Heros *heros)
{
    move_position(&heros->hitbox.position, -heros->speed, 0);
    move_position(&heros->position, -heros->speed, 0);
}

void move_heros_right(Heros *heros)
{
    move_position(&heros->hitbox.position, heros->speed, 0);
    move_position(&heros->position, heros->speed, 0);
}
