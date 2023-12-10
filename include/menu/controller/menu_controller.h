#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include "../menu.h"
#include "../../game/manager/event_manager/mouse_manager/mouse_manager.h"
#include "../../game/manager/game_manager/game_manager.h"

void handle_menu_events(MenuPage *menu_page, MouseManager mouse_manager);

#endif