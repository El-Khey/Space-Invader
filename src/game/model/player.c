#include "../../../include/game/model/player.h"

static void init_view_elements(Player *player);

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

    init_view_elements(&player);

    player.gold = 0;
    player.score = 0;

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

static void init_view_elements(Player *player)
{
    char score_text[13];
    player->view = construct_player_view(player->id);
    set_text_content(&player->view.username, player->username);

    sprintf(score_text, "Score: %d", player->score);
    set_text_content(&player->view.score_text, score_text);

    player->ship_customization_view = construct_ship_customization(player->id);

    if (player->id == 0)
    {
        set_text_position(&player->view.username,
                          construct_position(get_x(player->view.life_bar.background.position) + get_width(player->view.life_bar.background.dimension) - get_text_width(player->view.username) - 5,
                                             get_y(player->view.life_bar.background.position) - get_height(player->view.username.dimension)));
    }
}

static void draw_player_view(Player player)
{
    int i = 0;

    draw_text(player.view.username);
    draw_text(player.view.score_text);

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
    draw_rectangle(player.view.energy_bar.background);

    if (player.heros.shield.is_active)
    {
        int remaining_time = player.heros.shield.active_time - MLV_get_time();
        int remaining_time_percent = (remaining_time * 100) / player.heros.shield.shield_duration;
        int filled_bar_width = (remaining_time_percent * get_width(player.view.energy_bar.background.dimension)) / 100;

        player.view.energy_bar.filled_bar.dimension.width = filled_bar_width;

        if (player.id == 0)
        {
            player.view.energy_bar.filled_bar.position.x = player.view.energy_bar.background.position.x + get_width(player.view.energy_bar.background.dimension) - filled_bar_width;
        }

        draw_rectangle(player.view.energy_bar.filled_bar);
    }

    draw_border(player.view.energy_bar.background.position, player.view.energy_bar.background.dimension, 2, MLV_COLOR_WHITE);
    draw_image(&player.view.gold.gold_image);
    draw_text(player.view.gold.gold_text);
}

void set_players_health(Players *players, int health)
{
    int i = 0;
    for (; i < players->nb_players; i++)
    {
        players->players[i].heros.health = health;
    }
}

void draw_player(Player player)
{
    draw_heros(player.heros);
    draw_player_view(player);
}