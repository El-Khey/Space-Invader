#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include "../menu.h"
#include "../../game/manager/event_manager/mouse_manager/mouse_manager.h"
#include "../../game/manager/game_manager/game_manager.h"

/**
 * Gère les événements du menu.
 *
 * Cette fonction est responsable de la gestion des événements du menu.
 * Elle prend en paramètre un pointeur vers la page de menu et un gestionnaire de souris.
 *
 * @param menu_page Le pointeur vers la page de menu.
 * @param mouse_manager Le gestionnaire de souris.
 */
void handle_menu_events(MenuPage *menu_page, MouseManager mouse_manager);

#endif