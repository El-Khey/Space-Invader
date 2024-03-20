#ifndef KEYBOARD_MANAGER_H
#define KEYBOARD_MANAGER_H

#include "../../../../main.h"

/**
 * @brief Structure représentant les touches fléchées du clavier.
 */
typedef struct
{
    int key_left;  /**< Touche gauche */
    int key_right; /**< Touche droite */
    int key_up;    /**< Touche haut */
    int key_down;  /**< Touche bas */
} ArrowKeys;

/**
 * @brief Structure représentant les touches d'attaque.
 */
typedef struct
{
    int key_attack_1, key_attack_2, key_attack_3;
} AttackKeys;

/**
 * @brief Structure représentant les touches de l'espace.
 */
typedef struct
{
    int space; /**< Touche espace */
    int enter; /**< Touche entrée */
} SpaceKeys;

/**
 * @brief Structure représentant les touches d'échappement.
 */
typedef struct
{
    int escape;
} EscapeKeys;

/**
 * @brief Structure représentant un événement clavier.
 */
typedef struct
{
    SpaceKeys space_key;    /**< Touche espace */
    ArrowKeys arrow_keys;   /**< Touches de direction */
    EscapeKeys escape_key;  /**< Touche échappement */
    AttackKeys attack_keys; /**< Touches d'attaque */
} KeyboardEvent;

/**
 * @brief Structure représentant le gestionnaire de clavier.
 *
 * Cette structure contient un tableau d'événements de clavier pour chaque joueur.
 */
typedef struct
{
    KeyboardEvent event[MAX_PLAYERS];
} KeyboardManager;

/**
 * @brief Constructeur d'un nouvel objet KeyboardManager avec des valeurs par défaut.
 * L'objet KeyboardManager est utilisé pour stocker l'état des événements du clavier dans le jeu,
 * tels que le tir du joueur, le déplacement à gauche, le déplacement à droite, le déplacement vers le haut,
 * le déplacement vers le bas et la fermeture du jeu.
 *
 * @return KeyboardManager
 */
KeyboardManager construct_keyboard_manager();

/**
 * @brief Gère les événements du clavier et met à jour l'événement du clavier en conséquence.
 *
 * @param keyboard_manager Le gestionnaire du clavier
 * @param player_id L'identifiant du joueur
 */
void handle_keyboard_events(KeyboardManager *keyboard_manager, int player_id);

/**
 * @brief Vérifie si la touche d'échappement est enfoncée et met à jour l'événement du clavier en conséquence.
 * Cette fonction est utilisée pour fermer le jeu lorsque l'un des joueurs appuie sur la touche d'échappement.
 *
 * @param keyboard_manager Le gestionnaire du clavier
 * @param player_id L'identifiant du joueur
 * @return int
 */
int is_escape_key_pressed(KeyboardManager keyboard_manager);

/**
 * @brief Obtient la touche de la flèche gauche.
 *
 * @param keyboard_manager Le gestionnaire du clavier
 * @return int
 */
int get_left_arrow_key(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Obtient la touche de la flèche droite.
 *
 * @param keyboard_manager Le gestionnaire du clavier
 * @return int
 */
int get_right_arrow_key(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Obtient la touche de la flèche vers le haut.
 *
 * @param keyboard_manager Le gestionnaire du clavier
 * @return int
 */
int get_up_arrow_key(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Obtient la touche de la flèche vers le bas.
 *
 * @param keyboard_manager Le gestionnaire du clavier
 * @return int
 */
int get_down_arrow_key(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Obtient la touche espace.
 *
 * @param keyboard_manager Le gestionnaire du clavier
 * @return int
 */
int get_space_key(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Obtient la touche entrée.
 *
 * @param keyboard_manager Le gestionnaire du clavier
 * @return int
 */
int get_enter_key(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Obtient la touche d'attaque 1.
 *
 * @param keyboard_manager Le gestionnaire du clavier
 * @return int
 */
int get_key_attack_1(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Obtient la touche d'attaque 2.
 *
 * @param keyboard_manager Le gestionnaire du clavier
 * @return int
 */
int get_key_attack_2(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Obtient la touche d'attaque 3.
 *
 * @param keyboard_manager Le gestionnaire du clavier
 * @param player_id L'identifiant du joueur
 * @return int
 */
int get_key_attack_3(KeyboardManager keyboard_manager, int player_id);

/**
 * @brief Affiche les événements du clavier dans la console à des fins de débogage.
 * Cette fonction ne doit pas être utilisée dans la version finale du jeu.
 *
 * @param keyboard_event L'événement du clavier
 */
void print_keyboard_event(KeyboardEvent keyboard_event);

#endif