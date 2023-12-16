#ifndef EVENT_MANAGER_H_
#define EVENT_MANAGER_H_

#include "./keyboard_manager/keyboard_manager.h"
#include "./mouse_manager/mouse_manager.h"

/**
 * @brief Structure représentant le gestionnaire d'événements.
 *
 * Cette structure contient les gestionnaires de souris et de clavier.
 */
typedef struct
{
    MouseManager mouse_manager;       /**< Gestionnaire de souris */
    KeyboardManager keyboard_manager; /**< Gestionnaire de clavier */
} EventManager;

/**
 * @brief Construit un nouvel objet EventManager avec des valeurs par défaut.
 * L'objet EventManager est utilisé pour stocker l'état des événements dans le jeu.
 * Les événements sont catégorisés en 2 types :
 * 1. Les événements du clavier
 * 2. Les événements de la souris
 *
 * @return EventManager
 */
EventManager construct_event_manager();

/**
 * @brief Gère les événements dans le jeu en appelant les gestionnaires d'événements respectifs.
 * Il gérera séparément les événements du clavier et les événements de la souris.
 *
 * @param event_manager
 * @param game_mode
 */
void handle_events(EventManager *event_manager, int game_mode);

#endif