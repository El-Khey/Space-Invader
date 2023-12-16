#ifndef GAME_MANAGER_GAME_DETAILS_H_
#define GAME_MANAGER_GAME_DETAILS_H_

/**
 * @brief Enumération représentant les modes de jeu disponibles.
 */
typedef enum
{
    MODE_SOLO = 1, /**< Mode solo */
    MODE_MULTI,    /**< Mode multijoueur */
    nb_modes       /**< Nombre total de modes */
} GameMode;

/**
 * @brief Le mode de jeu
 * Le mode de jeu peut être soit solo, soit multijoueur.
 * La valeur nb_modes représente le nombre total de modes de jeu disponibles.
 */
typedef enum
{
    EASY,
    MEDIUM,
    HARD,
    nb_difficulties
} GameDifficulty;

#endif