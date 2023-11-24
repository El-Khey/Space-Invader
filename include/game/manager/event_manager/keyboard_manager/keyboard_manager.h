#ifndef KEYBOARD_MANAGER_H
#define KEYBOARD_MANAGER_H

#include "../../../../main.h"

typedef struct
{
    int key_left, key_right, key_up, key_down;
} ArrowKeys;

typedef struct
{
    int key_attack_1, key_attack_2, key_attack_3;
} AttackKeys;

typedef struct
{
    int space;
    int enter;
} SpaceKeys;

typedef struct
{
    int escape;
} EscapeKeys;

typedef struct
{
    SpaceKeys space_key;
    ArrowKeys arrow_keys;
    EscapeKeys escape_key;
    AttackKeys attack_keys;
} KeyboardEvent;

typedef struct
{
    KeyboardEvent event[MAX_PLAYERS];
} KeyboardManager;

/**
 * @brief Construct a new Keyboard Manager object with default values
 * The KeyboardManager object is used to store the state of the keyboard events in the game
 * such as the player shooting, moving left, moving right, moving up, moving down and closing the game
 *
 * @return KeyboardManager
 */
KeyboardManager construct_keyboard_manager();

/**
 * @brief Handle the keyboard events and update the keyboard event accordingly
 *
 * @param keyboard_manager
 */
void handle_keyboard_events(KeyboardManager *keyboard_manager, int player_id);

/**
 * @brief Check if the escape key is pressed and update the keyboard event accordingly
 * This function is used to close the game when one of the players press the escape key
 *
 * @param keyboard_manager The keyboard manager object
 * @param player_id The player id
 * @return int
 */
int is_escape_key_pressed(KeyboardManager keyboard_manager);

/**
 * @brief Get the left arrow key object
 *
 * @param keyboard_manager The keyboard manager object
 * @return int
 */
int get_left_arrow_key(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Get the right arrow key object
 *
 * @param keyboard_manager The keyboard manager object
 * @return int
 */
int get_right_arrow_key(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Get the up arrow key object
 *
 * @param keyboard_manager The keyboard manager object
 * @return int
 */
int get_up_arrow_key(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Get the down arrow key object
 *
 * @param keyboard_manager The keyboard manager object
 * @return int
 */
int get_down_arrow_key(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Get the space key object
 *
 * @param keyboard_manager The keyboard manager object
 * @return int
 */
int get_space_key(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Get the enter key object
 *
 * @param keyboard_manager The keyboard manager object
 * @return int
 */
int get_enter_key(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Get the key a object
 *
 * @param keyboard_manager The keyboard manager object
 * @return int
 */
int get_key_attack_1(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Get the key z object
 *
 * @param keyboard_manager The keyboard manager object
 * @return int
 */
int get_key_attack_2(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Get the key attack 3 object
 *
 * @param keyboard_manager The keyboard manager object
 * @param player_id The player id
 * @return int
 */
int get_key_attack_3(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Print the keyboard events in the console for debugging purposes
 * This function should not be used in the final version of the game
 *
 * @param keyboard_event
 */
void print_keyboard_event(KeyboardEvent keyboard_event);

#endif