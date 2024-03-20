#ifndef INPUT_H
#define INPUT_H

#include "../../utils/position/position.h"
#include "../../utils/dimension/dimension.h"

#include <MLV/MLV_all.h>

/**
 * @struct InputBox
 * @brief Représente une boîte de saisie d'entrée.
 *
 * Cette structure contient un pointeur vers une boîte de saisie MLV_Input_box,
 * une chaîne de caractères représentant la valeur saisie,
 * ainsi que la position et les dimensions de la boîte de saisie.
 */
typedef struct
{
    MLV_Input_box *input_box;
    char *value;

    Position position;
    Dimension dimension;
} InputBox;

/**
 * @brief Construit une boîte de saisie d'entrée avec les paramètres spécifiés.
 *
 * @param position La position de la boîte de saisie d'entrée.
 * @param dimension Les dimensions de la boîte de saisie d'entrée.
 * @param default_value La valeur par défaut de la boîte de saisie d'entrée.
 * @return InputBox La boîte de saisie d'entrée construite.
 */
InputBox construct_input_box(Position position, Dimension dimension, char *default_value);

/**
 * @brief Dessine la boîte de saisie d'entrée spécifiée.
 *
 * @param input_wrapper La boîte de saisie d'entrée à dessiner.
 */
void draw_input_box(InputBox input_wrapper);

#endif