#include "../../../include/gui/input/input.h"

InputBox construct_input_box(Position position, Dimension dimension, char *default_value)
{
    InputBox input_wrapper;

    input_wrapper.input_box = MLV_create_input_box(get_x(position), get_y(position), get_width(dimension), get_height(dimension), MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_GRAY, default_value);

    input_wrapper.position = position;
    input_wrapper.dimension = dimension;

    input_wrapper.value = default_value;

    return input_wrapper;
}

/**
 * Active la boîte de saisie d'entrée.
 *
 * Cette fonction active la boîte de saisie d'entrée spécifiée en paramètre.
 * L'activation de la boîte de saisie permet à l'utilisateur de saisir du texte.
 *
 * @param input_wrapper Le pointeur vers la structure InputBox contenant la boîte de saisie d'entrée.
 */
static void activate_input_box(InputBox *input_wrapper)
{
    MLV_activate_input_box(input_wrapper->input_box);
}

/**
 * Gère les événements de la boîte de saisie d'entrée.
 *
 * Cette fonction récupère les événements de la boîte de saisie d'entrée spécifiée en paramètre.
 * Elle met à jour la valeur de la boîte de saisie et active la boîte de saisie.
 *
 * @param input_wrapper Le pointeur vers la structure InputBox contenant la boîte de saisie d'entrée.
 */
static void handle_input_box_events(InputBox *input_wrapper)
{
    MLV_get_event(NULL, NULL, NULL, &input_wrapper->value, &input_wrapper->input_box, NULL, NULL, NULL, NULL);
    activate_input_box(input_wrapper);
}

void draw_input_box(InputBox input_wrapper)
{
    handle_input_box_events(&input_wrapper);
    MLV_draw_input_box(input_wrapper.input_box);
}
