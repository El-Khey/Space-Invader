#include "../../../include/menu/pages/map_selection_menu_page.h"

#define MAP_WIDTH WINDOW_WIDTH / 2
#define MAP_HEIGHT WINDOW_HEIGHT / 3

#define BUTTON_WIDTH 450
#define BUTTON_HEIGHT 50

MapSelectionMenu construct_map_selection_menu()
{
    MapSelectionMenu map_selection_menu;

    Image bamboo_map = load_image("assets/background/bamboo.png", construct_dimension(MAP_WIDTH, MAP_HEIGHT));
    set_image_position(&bamboo_map, construct_position(WINDOW_WIDTH / 2 - MAP_WIDTH / 2, WINDOW_HEIGHT / 2 - MAP_HEIGHT / 2));

    Image castle_bridge_map = load_image("assets/background/castle bridge.png", construct_dimension(MAP_WIDTH, MAP_HEIGHT));
    set_image_position(&castle_bridge_map, construct_position(WINDOW_WIDTH / 2 - MAP_WIDTH / 2, WINDOW_HEIGHT / 2 - MAP_HEIGHT / 2));

    Image forest_bridge_map = load_image("assets/background/forest bridge.png", construct_dimension(MAP_WIDTH, MAP_HEIGHT));
    set_image_position(&forest_bridge_map, construct_position(WINDOW_WIDTH / 2 - MAP_WIDTH / 2, WINDOW_HEIGHT / 2 - MAP_HEIGHT / 2));

    Image sky_bridge_map = load_image("assets/background/sky bridge.png", construct_dimension(MAP_WIDTH, MAP_HEIGHT));
    set_image_position(&sky_bridge_map, construct_position(WINDOW_WIDTH / 2 - MAP_WIDTH / 2, WINDOW_HEIGHT / 2 - MAP_HEIGHT / 2));

    map_selection_menu.map_images[0] = bamboo_map;
    map_selection_menu.map_images[1] = castle_bridge_map;
    map_selection_menu.map_images[2] = forest_bridge_map;
    map_selection_menu.map_images[3] = sky_bridge_map;

    map_selection_menu.map_names[0] = construct_text("Bambou", construct_position(0, 0), "assets/fonts/Play-Bold.ttf", 32, MLV_COLOR_WHITE);
    map_selection_menu.map_names[1] = construct_text("Chateau", construct_position(0, 0), "assets/fonts/Play-Bold.ttf", 32, MLV_COLOR_WHITE);
    map_selection_menu.map_names[2] = construct_text("Foret", construct_position(0, 0), "assets/fonts/Play-Bold.ttf", 32, MLV_COLOR_WHITE);
    map_selection_menu.map_names[3] = construct_text("Ciel", construct_position(0, 0), "assets/fonts/Play-Bold.ttf", 32, MLV_COLOR_WHITE);

    Position map_image_center = construct_position(get_x(bamboo_map.position) + get_width(bamboo_map.dimension) / 2, get_y(bamboo_map.position) + get_height(bamboo_map.dimension) / 2);

    for (int i = 0; i < NUMBER_OF_MAPS; i++)
    {
        set_text_position(&map_selection_menu.map_names[i], construct_position(get_x(map_image_center) - get_text_width(map_selection_menu.map_names[i]) / 2, get_y(map_image_center) - get_text_height(map_selection_menu.map_names[i]) / 2));
    }

    Position map_bottom_right = construct_position(get_x(bamboo_map.position) + get_width(bamboo_map.dimension), get_y(bamboo_map.position) + get_height(bamboo_map.dimension));
    Position map_bottom_left = construct_position(get_x(bamboo_map.position), get_y(bamboo_map.position) + get_height(bamboo_map.dimension));

    // Next and previous map buttons under the map
    map_selection_menu.next_map_button = construct_button_with_text(">", construct_position(get_x(map_bottom_right) - 50, get_y(map_bottom_right) + 32), construct_dimension(50, 50), MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 200));
    map_selection_menu.previous_map_button = construct_button_with_text("<", construct_position(get_x(map_bottom_left), get_y(map_bottom_left) + 32), construct_dimension(50, 50), MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 200));

    map_selection_menu.selected_map = 0;

    map_selection_menu.start_button = construct_button_with_text("Jouer", construct_position(WINDOW_WIDTH - 50 - BUTTON_WIDTH, WINDOW_HEIGHT - 100), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 200));
    map_selection_menu.back_button = construct_button_with_text("Retour", construct_position(50, WINDOW_HEIGHT - 100), construct_dimension(BUTTON_WIDTH, BUTTON_HEIGHT), MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 200));

    return map_selection_menu;
}

void draw_map_selection_menu_page(MapSelectionMenu map_selection_menu, Position mouse_position)
{
    draw_filled_rectangle_with_padding(map_selection_menu.map_images[abs(map_selection_menu.selected_map)].position, map_selection_menu.map_images[abs(map_selection_menu.selected_map)].dimension, 6, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150), 22);
    draw_image(&map_selection_menu.map_images[abs(map_selection_menu.selected_map)]);
    draw_text_with_shadow(map_selection_menu.map_names[abs(map_selection_menu.selected_map)], 5);

    draw_filled_button_with_hover_effect(map_selection_menu.next_map_button, mouse_position, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150));
    draw_filled_button_with_hover_effect(map_selection_menu.previous_map_button, mouse_position, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150));

    draw_filled_button_with_hover_effect(map_selection_menu.start_button, mouse_position, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150));
    draw_filled_button_with_hover_effect(map_selection_menu.back_button, mouse_position, MLV_COLOR_WHITE, MLV_rgba(12, 12, 17, 150));
}
