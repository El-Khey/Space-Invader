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

/**
 * @struct LifeBar
 * @brief Représente la barre de vie d'un joueur.
 *
 * La structure LifeBar contient les informations nécessaires pour afficher la barre de vie d'un joueur.
 * Elle comprend un rectangle représentant l'arrière-plan de la barre, un rectangle représentant la barre elle-même,
 * et la valeur maximale de la vie du joueur.
 */

typedef struct
{
    Rectangle background; /** Rectangle représentant l'arrière-plan de la barre de vie */
    Rectangle bar;        /** Rectangle représentant la barre de vie */
    int max_life;         /** Valeur maximale de la vie du joueur */
} LifeBar;

/**
 * @struct EnergyBar
 * @brief Représente la barre d'énergie d'un joueur.
 *
 * La structure EnergyBar contient les informations nécessaires pour afficher la barre d'énergie d'un joueur.
 * Elle comprend un rectangle représentant l'arrière-plan de la barre et un rectangle représentant la partie remplie de la barre.
 */

typedef struct
{
    Rectangle background; /** Rectangle représentant l'arrière-plan de la barre d'énergie */
    Rectangle filled_bar; /** Rectangle représentant la partie remplie de la barre d'énergie */
} EnergyBar;

/**
 * @struct Gold
 * @brief Représente les informations sur l'or d'un joueur.
 *
 * La structure Gold contient les informations nécessaires pour afficher les informations sur l'or d'un joueur.
 * Elle comprend un texte représentant la quantité d'or et une image représentant l'icône de l'or.
 */

typedef struct
{
    Text gold_text;   /** Texte représentant la quantité d'or du joueur */
    Image gold_image; /** Image représentant l'icône de l'or */
} Gold;

/**
 * @struct PlayerView
 * @brief Représente la vue d'un joueur.
 *
 * La structure PlayerView contient les informations nécessaires pour afficher la vue d'un joueur.
 * Elle comprend une image représentant l'avatar du joueur, un texte représentant le nom d'utilisateur du joueur,
 * un texte représentant le score du joueur, une barre de vie, une barre d'énergie et des informations sur l'or du joueur.
 */

typedef struct
{
    Image avatar;    /** Image représentant l'avatar du joueur */
    Text username;   /** Texte représentant le nom d'utilisateur du joueur */
    Text score_text; /** Texte représentant le score du joueur */

    LifeBar life_bar;     /** Barre de vie du joueur */
    EnergyBar energy_bar; /** Barre d'énergie du joueur */
    Gold gold;            /** Informations sur l'or du joueur */

} PlayerView;

/**
 * @brief Construit une vue joueur.
 *
 * @param player_id L'identifiant du joueur.
 * @return PlayerView La vue joueur construite.
 */
PlayerView construct_player_view(int player_id);

/**
 * @brief Libère la mémoire allouée pour une vue joueur.
 *
 * @param player_view Le pointeur vers la vue joueur à libérer.
 */
void free_player_view(PlayerView *player_view);

#endif