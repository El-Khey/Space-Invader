#ifndef PLAYER_H
#define PLAYER_H

#include "./heros.h"

#define LEN_USERNAME_MAX 20
#define NB_PLAYERS_MAX 2

typedef struct
{
    Heros heros;

    int id;
    int score;
    int lives;
    int gold;

    char username[LEN_USERNAME_MAX];
} Player;

typedef struct
{
    Player players[NB_PLAYERS_MAX];
    int nb_players;
} Players;

Player construct_player(int id, char *username);

Players construct_players(Player player_1, Player player_2);

void draw_player(Player player);

#endif