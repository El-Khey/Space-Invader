#ifndef PLAYER_VIEW_H
#define PLAYER_VIEW_H

#include "../../main.h"

#include "../../utils/image/image.h"
#include "../../utils/text/text.h"

#include "../../gui/shape/shape.h"

#define LIFE_BAR_WIDTH 280
#define LIFE_BAR_HEIGTH 20

#define BAR_LIFE_PADDING 4
#define DETAILS_OFFSET_X 15

typedef struct
{
    Rectangle background;
    Rectangle bar;
    int max_life;
} LifeBar;

typedef struct
{
    Rectangle background;
    Rectangle filled_bar;
} EnergyBar;

typedef struct
{
    Text gold_text;
    Image gold_image;
} Gold;

typedef struct
{
    Image avatar;
    Text username;

    LifeBar life_bar;
    EnergyBar energy_bar;
    Gold gold;

} PlayerView;

PlayerView construct_player_view(int player_id);

#endif