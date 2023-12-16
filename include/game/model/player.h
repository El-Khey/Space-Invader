#ifndef PLAYER_H
#define PLAYER_H

#include "./heros.h"
#include "../../utils/image/image.h"
#include "../../utils/text/text.h"
#include "../view/player_view.h"

#include "../view/player_view.h"
#include "../view/ship_customization_view.h"

#define LEN_USERNAME_MAX 20
#define NB_PLAYERS_MAX 2

typedef struct
{
    Heros heros; /** Le héros du joueur */

    int id;    /** L'identifiant du joueur */
    int score; /** Le score du joueur */
    int gold;  /** La quantité d'or du joueur */

    char username[LEN_USERNAME_MAX];               /** Le nom d'utilisateur du joueur */
    PlayerView view;                               /** La vue du joueur */
    ShipCustomizationView ship_customization_view; /** La vue de personnalisation du vaisseau du joueur */
} Player;

/**
 * @struct Players
 * @brief Représente une collection de joueurs.
 *
 * Cette structure contient un tableau de joueurs et le nombre de joueurs actuellement présents.
 */
typedef struct
{
    Player players[NB_PLAYERS_MAX]; /**< Le tableau de joueurs */
    int nb_players;                 /**< Le nombre de joueurs */
} Players;

/**
 * @brief Construit un objet Player avec l'identifiant et le nom d'utilisateur spécifiés.
 *
 * @param id L'identifiant du joueur.
 * @param username Le nom d'utilisateur du joueur.
 * @return Player L'objet Player construit.
 */
Player construct_player(int id, char *username);

/**
 * @brief Construit un objet Players avec les joueurs spécifiés.
 *
 * @param player_1 Le premier joueur.
 * @param player_2 Le deuxième joueur.
 * @return Players L'objet Players construit.
 */
Players construct_players(Player player_1, Player player_2);

/**
 * @brief Charge les données de sauvegarde du joueur spécifié.
 *
 * @param player Le joueur dont les données de sauvegarde doivent être chargées.
 */
void load_player_backup(Player *player);

/**
 * @brief Définit la santé des joueurs spécifiés.
 *
 * @param players Les joueurs dont la santé doit être définie.
 * @param health La santé à définir.
 */
void set_players_health(Players *players, int health);

/**
 * @brief Dessine le joueur spécifié.
 *
 * @param player Le joueur à dessiner.
 */
void draw_player(Player player);

/**
 * @brief Libère la mémoire allouée pour les joueurs spécifiés.
 *
 * @param players Les joueurs à libérer.
 */
void free_players(Players *players);

#endif