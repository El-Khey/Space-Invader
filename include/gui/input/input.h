#ifndef INPUT_H
#define INPUT_H

#include "../../utils/position/position.h"
#include "../../utils/dimension/dimension.h"

#include <MLV/MLV_all.h>

typedef struct
{
    MLV_Input_box *input_box;
    char *value;

    Position position;
    Dimension dimension;
} InputBox;

InputBox construct_input_box(Position position, Dimension dimension, char *default_value);

void draw_input_box(InputBox input_wrapper);

#endif