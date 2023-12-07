#include "../../../include/game/model/player.h"

Player construct_player(int id, char *username)
{
    Player player;

    Dimension heros_dimension = construct_dimension(150, 150);
    Position heros_position = construct_position(WINDOW_WIDTH / 2 - get_width(heros_dimension) / 2,
                                                 WINDOW_HEIGHT - get_height(heros_dimension) - 50);

    player.id = id;
    strcpy(player.username, username);

    player.heros = (player.id)
                       ? construct_heros(heros_position, heros_dimension)
                       : construct_heros(construct_position(get_x(heros_position) + 50 + get_width(heros_dimension), get_y(heros_position)), heros_dimension);

    player.view = construct_player_view(player.id);

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

void draw_player(Player player)
{
    draw_heros(player.heros);
    draw_image(&player.view.avatar);
}