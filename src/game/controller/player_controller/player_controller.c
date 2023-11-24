#include "../../../../include/game/manager/event_manager/event_manager.h"
#include "../../../../include/game/model/objet/creature/heros/heros.h"

void move_heros_up(Heros *Heros)
{
    move_position(&Heros->creature.objet.position, 0, -Heros->speed);
}

void move_heros_down(Heros *Heros)
{
    move_position(&Heros->creature.objet.position, 0, Heros->speed);
}

void move_heros_left(Heros *Heros)
{
    move_position(&Heros->creature.objet.position, -Heros->speed, 0);
}

void move_heros_right(Heros *Heros)
{
    move_position(&Heros->creature.objet.position, Heros->speed, 0);
}

void handle_player_movement(Heros *heros, EventManager *event_manager)
{
    handle_events(event_manager, 0);

    if (event_manager->keyboard_manager.event[0].arrow_keys.key_right)
    {
        move_heros_right(heros);
    }
    if (event_manager->keyboard_manager.event[0].arrow_keys.key_left)
    {
        move_heros_left(heros);
    }
    if (event_manager->keyboard_manager.event[0].arrow_keys.key_up)
    {
        move_heros_up(heros);
    }
    if (event_manager->keyboard_manager.event[0].arrow_keys.key_down)
    {
        move_heros_down(heros);
    }
}
