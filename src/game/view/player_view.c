#include "../../../include/game/view/player_view.h"
#include "../../../include/main.h"

static void initialize_view_player_1(PlayerView *player_view);
static void initialize_view_player_2(PlayerView *player_view);

PlayerView construct_player_view(int player_id)
{
    PlayerView player_view;
    (player_id) ? initialize_view_player_1(&player_view) : initialize_view_player_2(&player_view);

    return player_view;
}

static void load_player_avatar(PlayerView *player_view, int player_id)
{
    char path[100];
    sprintf(path, "assets/images/avatars/%d.png", player_id);
    player_view->avatar = load_image(path, construct_dimension(125, 125));
}

static void initialize_view_player_1(PlayerView *player_view)
{
    load_player_avatar(player_view, 0);
    player_view->avatar.position = construct_position(50, 50);
}

static void initialize_view_player_2(PlayerView *player_view)
{
    load_player_avatar(player_view, 1);
    player_view->avatar.position = construct_position(WINDOW_WIDTH - get_width(player_view->avatar.dimension) - 50, 50);
}

void draw_player_view(PlayerView player_view)
{
    draw_image(&player_view.avatar);
}