#ifndef SHIP_CUSTOMIZATION_H
#define SHIP_CUSTOMIZATION_H

#include "../../main.h"
#include "../../gui/button/button.h"
#include "../../gui/shape/shape.h"
#include "../../utils/text/text.h"
#include "../../utils/animation/animation.h"

#define MAX_SHIP_LEVEL 4
#define CUSTOMIZATION_NUMBER_OF_BUTTONS 2
#define BAR_WIDTH 200
#define BAR_HEIGHT 75

typedef struct
{
    Rectangle background;
    Button button[CUSTOMIZATION_NUMBER_OF_BUTTONS];
} ShipCustomizationBar;

typedef struct
{
    Text title;
    Rectangle background;
    Button engine_buttons[MAX_SHIP_LEVEL];
    Button weapon_buttons[MAX_SHIP_LEVEL];
} ShipCustomizationModal;

typedef struct
{
    ShipCustomizationBar bar;
    ShipCustomizationModal modal[CUSTOMIZATION_NUMBER_OF_BUTTONS];
    int active_modal;
    int is_modal_active;
} ShipCustomizationView;

ShipCustomizationView construct_ship_customization(int player_id);

void draw_ship_customization(ShipCustomizationView ship_customization, Position mouse_position);

#endif