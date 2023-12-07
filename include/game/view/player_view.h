#ifndef PLAYER_VIEW_H
#define PLAYER_VIEW_H

#include "../../utils/image/image.h"
#include "../../utils/text/text.h"

typedef struct
{
    Image avatar;
    Text username;
} PlayerView;

PlayerView construct_player_view(int player_id);

#endif