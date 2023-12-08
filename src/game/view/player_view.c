#include "../../../include/game/view/player_view.h"
#include "../../../include/main.h"

static void initialize_view_player_2(PlayerView *player_view);
static void initialize_view_player_1(PlayerView *player_view);

PlayerView construct_player_view(int player_id)
{
    PlayerView player_view;
    (player_id == 0) ? initialize_view_player_1(&player_view) : initialize_view_player_2(&player_view);
    return player_view;
}

static void load_player_avatar(PlayerView *player_view, int player_id)
{
    char path[100];
    sprintf(path, "assets/images/avatars/%d.png", player_id);
    player_view->avatar = load_image(path, construct_dimension(125, 125));
}

static void initialize_view_player_2(PlayerView *player_view)
{
    int bar_life_width = LIFE_BAR_WIDTH / MAX_PLAYER_LIFE;
    int total_padding = (MAX_PLAYER_LIFE + 1) * BAR_LIFE_PADDING;
    int background_width = LIFE_BAR_WIDTH + total_padding;

    load_player_avatar(player_view, 0);
    player_view->avatar.position = construct_position(50, 50);

    player_view->life_bar.background = construct_rectangle(construct_position(get_x(player_view->avatar.position) + get_width(player_view->avatar.dimension) + DETAILS_OFFSET_X, 50),
                                                           construct_dimension(background_width, LIFE_BAR_HEIGTH),
                                                           MLV_rgba(75, 75, 75, 255));

    player_view->life_bar.bar = construct_rectangle(construct_position(get_x(player_view->life_bar.background.position) + BAR_LIFE_PADDING, get_y(player_view->life_bar.background.position) + BAR_LIFE_PADDING),
                                                    construct_dimension(bar_life_width, get_height(player_view->life_bar.background.dimension) - BAR_LIFE_PADDING * 2),
                                                    MLV_rgba(255, 41, 41, 255));

    /**
     * Player 2 Shield bar
     */

    player_view->energy_bar.background = construct_rectangle(construct_position(get_x(player_view->life_bar.background.position), get_y(player_view->life_bar.background.position) + get_height(player_view->life_bar.background.dimension) + BAR_LIFE_PADDING),
                                                             construct_dimension(LIFE_BAR_WIDTH, LIFE_BAR_HEIGTH),
                                                             MLV_rgba(75, 75, 75, 255));

    player_view->energy_bar.filled_bar = construct_rectangle(construct_position(get_x(player_view->energy_bar.background.position), get_y(player_view->energy_bar.background.position)),
                                                             construct_dimension(0, get_height(player_view->energy_bar.background.dimension)),
                                                             MLV_rgba(50, 89, 255, 255));
}

static void initialize_view_player_1(PlayerView *player_view)
{
    int bar_life_width = LIFE_BAR_WIDTH / MAX_PLAYER_LIFE;
    int total_padding = (MAX_PLAYER_LIFE + 1) * BAR_LIFE_PADDING;
    int background_width = LIFE_BAR_WIDTH + total_padding;

    load_player_avatar(player_view, 1);
    player_view->avatar.position = construct_position(WINDOW_WIDTH - get_width(player_view->avatar.dimension) - 50, 50);

    player_view->life_bar.background = construct_rectangle(construct_position(get_x(player_view->avatar.position) - background_width - DETAILS_OFFSET_X, 50),
                                                           construct_dimension(background_width, LIFE_BAR_HEIGTH),
                                                           MLV_rgba(75, 75, 75, 255));

    player_view->life_bar.bar = construct_rectangle(construct_position(get_x(player_view->life_bar.background.position) + (get_width(player_view->life_bar.background.dimension) - bar_life_width) - BAR_LIFE_PADDING, get_y(player_view->life_bar.background.position) + BAR_LIFE_PADDING),
                                                    construct_dimension(bar_life_width, get_height(player_view->life_bar.background.dimension) - BAR_LIFE_PADDING * 2),
                                                    MLV_rgba(255, 41, 41, 255));

    /**
     * Player 1 Shield bar
     */

    player_view->energy_bar.background = construct_rectangle(construct_position(get_x(player_view->avatar.position) - LIFE_BAR_WIDTH - DETAILS_OFFSET_X, get_y(player_view->life_bar.background.position) + get_height(player_view->life_bar.background.dimension) + BAR_LIFE_PADDING),
                                                             construct_dimension(LIFE_BAR_WIDTH, LIFE_BAR_HEIGTH),
                                                             MLV_rgba(75, 75, 75, 255));

    player_view->energy_bar.filled_bar = construct_rectangle(construct_position(get_x(player_view->energy_bar.background.position), get_y(player_view->energy_bar.background.position)),
                                                             construct_dimension(0, get_height(player_view->energy_bar.background.dimension)),
                                                             MLV_rgba(50, 89, 255, 255));
}
