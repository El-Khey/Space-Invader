#ifndef GAME_MANAGER_GAME_DETAILS_H_
#define GAME_MANAGER_GAME_DETAILS_H_

typedef enum
{
    MODE_SOLO = 1,
    MODE_MULTI,
    nb_modes
} GameMode;

/**
 * @brief The difficulty of the game
 * The difficulty of the game is used to determine the number of lives of the player
 * and the delay between each monster spawn
 */
typedef enum
{
    EASY,
    MEDIUM,
    HARD,
    nb_difficulties
} GameDifficulty;

#endif