#ifndef EVENT_MANAGER_H_
#define EVENT_MANAGER_H_

#include "./keyboard_manager/keyboard_manager.h"
#include "./mouse_manager/mouse_manager.h"

typedef struct
{
    MouseManager mouse_manager;
    KeyboardManager keyboard_manager;
} EventManager;

/**
 * @brief Construct a new Event Manager object with default values
 * The EventManager object is used to store the state of the events in the game
 * The events are categorized into 2 types:
 * 1. The keyboard events
 * 2. The mouse events
 *
 * @return EventManager
 */
EventManager construct_event_manager();

/**
 * @brief Handle the events in the game by calling the respective event handlers
 * It will handle the keyboard events and mouse events separately
 *
 * @param event_manager
 */
void handle_events(EventManager *event_manager, int game_mode);

#endif