#include "../../../include/game/model/player.h"

Player construct_player(int id, char *username)
{
    Player player;

    player.id = id;
    strcpy(player.username, username);

    player.heros = construct_heros();
    return player;
}

Players construct_players(Player player_1, Player player_2)
{
    Players players;

    players.players[player_1.id] = player_1;
    players.players[player_2.id] = player_2;

    players.nb_players = 2;
    return players;
}