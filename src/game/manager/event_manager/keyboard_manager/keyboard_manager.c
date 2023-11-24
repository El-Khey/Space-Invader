#include "../../../../../include/game/manager/event_manager/keyboard_manager/keyboard_manager.h"

static void init_keyboard_event(KeyboardEvent *keyboard_event);

KeyboardManager construct_keyboard_manager()
{
    KeyboardManager keyboard_manager;

    init_keyboard_event(&keyboard_manager.event[0]);
    init_keyboard_event(&keyboard_manager.event[1]);

    return keyboard_manager;
}

static void init_keyboard_event(KeyboardEvent *keyboard_event)
{
    keyboard_event->arrow_keys.key_left = 0;
    keyboard_event->arrow_keys.key_right = 0;
    keyboard_event->arrow_keys.key_up = 0;
    keyboard_event->arrow_keys.key_down = 0;

    keyboard_event->space_key.space = 0;
    keyboard_event->space_key.enter = 0;

    keyboard_event->escape_key.escape = 0;

    keyboard_event->attack_keys.key_attack_1 = 0;
    keyboard_event->attack_keys.key_attack_2 = 0;
    keyboard_event->attack_keys.key_attack_3 = 0;
}

static void handle_player_1_keyboard_events(KeyboardManager *keyboard_manager)
{
    int player_id = 0;

    keyboard_manager->event[player_id].arrow_keys.key_left = MLV_get_keyboard_state(MLV_KEYBOARD_LEFT) == MLV_PRESSED;
    keyboard_manager->event[player_id].arrow_keys.key_right = MLV_get_keyboard_state(MLV_KEYBOARD_RIGHT) == MLV_PRESSED;
    keyboard_manager->event[player_id].arrow_keys.key_up = MLV_get_keyboard_state(MLV_KEYBOARD_UP) == MLV_PRESSED;
    keyboard_manager->event[player_id].arrow_keys.key_down = MLV_get_keyboard_state(MLV_KEYBOARD_DOWN) == MLV_PRESSED;

    keyboard_manager->event[player_id].attack_keys.key_attack_1 = MLV_get_keyboard_state(MLV_KEYBOARD_k) == MLV_PRESSED;
    keyboard_manager->event[player_id].attack_keys.key_attack_2 = MLV_get_keyboard_state(MLV_KEYBOARD_l) == MLV_PRESSED;
    keyboard_manager->event[player_id].attack_keys.key_attack_3 = MLV_get_keyboard_state(MLV_KEYBOARD_m) == MLV_PRESSED;
}

static void handle_player_2_keyboard_events(KeyboardManager *keyboard_manager)
{
    int player_id = 1;

    keyboard_manager->event[player_id].arrow_keys.key_left = MLV_get_keyboard_state(MLV_KEYBOARD_q) == MLV_PRESSED;
    keyboard_manager->event[player_id].arrow_keys.key_right = MLV_get_keyboard_state(MLV_KEYBOARD_d) == MLV_PRESSED;
    keyboard_manager->event[player_id].arrow_keys.key_up = MLV_get_keyboard_state(MLV_KEYBOARD_z) == MLV_PRESSED;
    keyboard_manager->event[player_id].arrow_keys.key_down = MLV_get_keyboard_state(MLV_KEYBOARD_s) == MLV_PRESSED;

    keyboard_manager->event[player_id].attack_keys.key_attack_1 = MLV_get_keyboard_state(MLV_KEYBOARD_v) == MLV_PRESSED;
    keyboard_manager->event[player_id].attack_keys.key_attack_2 = MLV_get_keyboard_state(MLV_KEYBOARD_b) == MLV_PRESSED;
    keyboard_manager->event[player_id].attack_keys.key_attack_3 = MLV_get_keyboard_state(MLV_KEYBOARD_n) == MLV_PRESSED;
}

void handle_keyboard_events(KeyboardManager *keyboard_manager, int player_id)
{
    if (player_id == 0)
    {
        handle_player_1_keyboard_events(keyboard_manager);
    }
    else
    {
        handle_player_2_keyboard_events(keyboard_manager);
    }

    keyboard_manager->event[player_id].space_key.space = MLV_get_keyboard_state(MLV_KEYBOARD_SPACE) == MLV_PRESSED;
    keyboard_manager->event[player_id].space_key.enter = MLV_get_keyboard_state(MLV_KEYBOARD_RETURN) == MLV_PRESSED;

    keyboard_manager->event[player_id].escape_key.escape = MLV_get_keyboard_state(MLV_KEYBOARD_ESCAPE) == MLV_PRESSED;
}

int is_escape_key_pressed(KeyboardManager keyboard_manager)
{
    return keyboard_manager.event[0].escape_key.escape || keyboard_manager.event[1].escape_key.escape;
}

int get_left_arrow_key(KeyboardManager keyboard_manager, int player_id) { return keyboard_manager.event[player_id].arrow_keys.key_left; }

int get_right_arrow_key(KeyboardManager keyboard_manager, int player_id) { return keyboard_manager.event[player_id].arrow_keys.key_right; }

int get_up_arrow_key(KeyboardManager keyboard_manager, int player_id) { return keyboard_manager.event[player_id].arrow_keys.key_up; }

int get_down_arrow_key(KeyboardManager keyboard_manager, int player_id) { return keyboard_manager.event[player_id].arrow_keys.key_down; }

int get_space_key(KeyboardManager keyboard_manager, int player_id) { return keyboard_manager.event[player_id].space_key.space; }

int get_enter_key(KeyboardManager keyboard_manager, int player_id) { return keyboard_manager.event[player_id].space_key.enter; }

int get_key_attack_1(KeyboardManager keyboard_manager, int player_id) { return keyboard_manager.event[player_id].attack_keys.key_attack_1; }

int get_key_attack_2(KeyboardManager keyboard_manager, int player_id) { return keyboard_manager.event[player_id].attack_keys.key_attack_2; }

int get_key_attack_3(KeyboardManager keyboard_manager, int player_id) { return keyboard_manager.event[player_id].attack_keys.key_attack_3; }

void print_keyboard_event(KeyboardEvent keyboard_event)
{
    printf("+-----------------------+\n");
    printf("|      Keyboard event   |\n");
    printf("+-----------------------+\n");
    printf("| Arrow keys            |\n");
    printf("+-----------+-----------+\n");
    printf("| Left      | %9d |\n", keyboard_event.arrow_keys.key_left);
    printf("| Right     | %9d |\n", keyboard_event.arrow_keys.key_right);
    printf("| Up        | %9d |\n", keyboard_event.arrow_keys.key_up);
    printf("| Down      | %9d |\n", keyboard_event.arrow_keys.key_down);
    printf("+-----------+-----------+\n");
    printf("| Space key             |\n");
    printf("+-----------+-----------+\n");
    printf("| Space     | %9d |\n", keyboard_event.space_key.space);
    printf("| Enter     | %9d |\n", keyboard_event.space_key.enter);
    printf("+-----------+-----------+\n");
    printf("| Escape key            |\n");
    printf("+-----------+-----------+\n");
    printf("| Escape    | %9d |\n", keyboard_event.escape_key.escape);
    printf("+-----------+-----------+\n");
}