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
    int i = 0;

    draw_heros(player.heros);
    draw_image(&player.view.avatar);

    draw_rectangle(player.view.life_bar.background);
    draw_border(player.view.life_bar.background.position, player.view.life_bar.background.dimension, 2, MLV_COLOR_WHITE);

    for (; i < MAX_PLAYER_LIFE; i++)
    {
        if (i < player.heros.health)
        {
            draw_rectangle(player.view.life_bar.bar);
        }

        draw_border(player.view.life_bar.bar.position, player.view.life_bar.bar.dimension, 1, MLV_COLOR_WHITE);
        player.view.life_bar.bar.position.x = (player.id) ? player.view.life_bar.bar.position.x + get_width(player.view.life_bar.bar.dimension) + BAR_LIFE_PADDING
                                                          : player.view.life_bar.bar.position.x - get_width(player.view.life_bar.bar.dimension) - BAR_LIFE_PADDING;
    }
}