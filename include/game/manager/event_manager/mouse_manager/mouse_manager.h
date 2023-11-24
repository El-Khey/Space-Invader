#ifndef MOUSE_MANAGER_H
#define MOUSE_MANAGER_H

#include "../../../../main.h"

#include "../../../../utils/position/position.h"

typedef struct
{
    int click_count;
    int is_right_click;
    int is_left_click;

    int was_right_click_pressed;
    int was_left_click_pressed;
} MouseEvent;

typedef struct
{
    int right_click;
    int left_click;
} MouseState;

typedef struct
{
    Position position;

    MouseState mouse_state;
    MouseState last_mouse_state;

    MouseEvent mouse_event;
} MouseManager;

/**
 * @brief Construct a new Mouse Manager object with default values
 *
 * @return MouseManager
 */
MouseManager construct_mouse_manager();

/**
 * @brief Handle the mouse events and update the mouse event accordingly
 *
 * @param mouse_manager The mouse manager object
 */
void handle_mouse_events(MouseManager *mouse_manager);

/**
 * @brief Check if the right button is clicked
 * A click is defined as a press and release of the button
 *
 * @param mouse_manager The mouse manager object
 * @return int
 */
int is_right_button_clicked(MouseManager mouse_manager);

/**
 * @brief Check if the left button is clicked
 * A click is defined as a press and release of the button
 *
 * @param mouse_manager The mouse manager object
 * @return int
 */
int is_left_button_clicked(MouseManager mouse_manager);

/**
 * @brief Set the mouse released object
 *
 * @param mouse_manager The mouse manager object
 */
void set_mouse_released(MouseManager *mouse_manager);

/**
 * @brief Get the mouse position object
 *
 * @param mouse_manager The mouse manager object
 * @return Position
 */
Position get_mouse_position(MouseManager mouse_manager);

#endif