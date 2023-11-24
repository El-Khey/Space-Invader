#include "../../../../include/game/manager/event_manager/event_manager.h"

EventManager construct_event_manager()
{
    EventManager event_manager;
    event_manager.keyboard_manager = construct_keyboard_manager();
    event_manager.mouse_manager = construct_mouse_manager();

    return event_manager;
}

void handle_events(EventManager *event_manager, int game_mode)
{
    handle_keyboard_events(&event_manager->keyboard_manager, game_mode);
    if (!(game_mode - 1))
    {
        handle_keyboard_events(&event_manager->keyboard_manager, game_mode - 1);
    }

    handle_mouse_events(&event_manager->mouse_manager);
}