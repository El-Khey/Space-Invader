#include "../../../include/game/view/ship_customization_view.h"
#include "../../../include/game/model/heros.h"
#include "../../../include/main.h"

#define OFFSET 25
#define PADDING_BAR 25

static void initialize_player_1_ship_customization(ShipCustomizationView *ship_customization);
static void initialize_player_2_ship_customization(ShipCustomizationView *ship_customization);
static void initialize_player_1_modal(ShipCustomizationView *ship_customization);
static void initialize_player_2_modal(ShipCustomizationView *ship_customization);

ShipCustomizationView construct_ship_customization(int player_id)
{
    ShipCustomizationView ship_customization;
    (player_id == 0) ? initialize_player_1_ship_customization(&ship_customization)
                     : initialize_player_2_ship_customization(&ship_customization);

    ship_customization.active_modal = 0;
    ship_customization.is_modal_active = 0;

    initialize_player_1_modal(&ship_customization);
    initialize_player_2_modal(&ship_customization);

    return ship_customization;
}

/**
 * Cette fonction retourne le chemin d'accès au sprite correspondant au type de moteur donné.
 *
 * @param engine_type Le type de moteur.
 * @return Le chemin d'accès au sprite correspondant au type de moteur donné.
 */
static char *get_engine_sprite_path(int engine_type)
{
    switch (engine_type)
    {
    case BASE_ENGINE:
        return "assets/sprites/Pickups/Engines/Base.png";
    case BIG_PULSE_ENGINE:
        return "assets/sprites/Pickups/Engines/Big Pulse.png";
    case BURST_ENGINE:
        return "assets/sprites/Pickups/Engines/Burst.png";
    case SUPERCHARGED_ENGINE:
        return "assets/sprites/Pickups/Engines/Supercharged.png";
    default:
        fprintf(stderr, "Erreur dans get_engine_sprite_path: type de moteur inconnu %d\n", engine_type);
        return "assets/sprites/Pickups/Engines/Base.png";
    }
}

/**
 * Cette fonction retourne le chemin d'accès au sprite correspondant au type d'arme donné.
 *
 * @param weapon_type Le type d'arme.
 * @return Le chemin d'accès au sprite correspondant au type d'arme donné.
 */
static char *get_weapon_sprite_path(int weapon_type)
{
    switch (weapon_type)
    {
    case AUTO_CANNON:
        return "assets/sprites/Pickups/Weapons/Auto Cannons.png";
    case BIG_SPACE:
        return "assets/sprites/Pickups/Weapons/Big Space Gun.png";
    case ROCKETS:
        return "assets/sprites/Pickups/Weapons/Rocket.png";
    case ZAPPER:
        return "assets/sprites/Pickups/Weapons/Zapper.png";
    default:
        fprintf(stderr, "Erreur dans get_weapon_sprite_path: type d'arme inconnu %d\n", weapon_type);
        return "assets/sprites/Pickups/Weapons/Auto Cannon.png";
    }
}

int get_weapon_price(int weapon_type)
{
    return (weapon_type + 1) * 100;
}

int get_engine_price(int engine_type)
{
    return (engine_type + 1) * 100;
}

static void initialize_player_1_modal(ShipCustomizationView *ship_customization)
{
    int i = 0;
    int modal_center_x, animation_x, animation_y;

    ship_customization->modal[0].background = construct_rectangle(construct_position(0, 225), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT - 450), MLV_rgba(255, 41, 41, 100));
    ship_customization->modal[0].title = construct_text("Acheter vos moteurs", construct_position(WINDOW_WIDTH / 2, 275), "assets/fonts/Play-Bold.ttf", 50, MLV_COLOR_WHITE);
    set_text_position(&ship_customization->modal[0].title, construct_position(get_x(ship_customization->modal[0].title.position) - get_text_width(ship_customization->modal[0].title) / 2, get_y(ship_customization->modal[0].title.position)));

    for (i = 0; i < MAX_SHIP_LEVEL; i++)
    {
        modal_center_x = get_x(ship_customization->modal[0].background.position) + get_width(ship_customization->modal[0].background.dimension) / 2;

        animation_x = modal_center_x - (MAX_SHIP_LEVEL * (100 + PADDING_BAR)) / 2;
        animation_y = get_y(ship_customization->modal[0].title.position) + get_height(ship_customization->modal[0].title.dimension) + 50;

        ship_customization->modal[0].engine_buttons[i] = construct_button_with_animation(construct_animation(get_engine_sprite_path(i), 15, construct_dimension(100, 100), FORWARD),
                                                                                         construct_position(animation_x + i * (100 + PADDING_BAR), animation_y),
                                                                                         construct_dimension(100, 100));

        ship_customization->modal[0].engine_text_buttons[i] = construct_button_with_text(convert_int_to_string(get_engine_price(i)),
                                                                                         construct_position(get_x(ship_customization->modal[0].engine_buttons[i].position),
                                                                                                            get_y(ship_customization->modal[0].engine_buttons[i].position) + get_height(ship_customization->modal[0].engine_buttons[i].dimension) + 10),
                                                                                         construct_dimension(get_width(ship_customization->modal[0].engine_buttons[i].dimension), 20),
                                                                                         MLV_COLOR_WHITE, MLV_COLOR_WHITE);
        set_text_position(&ship_customization->modal[0].engine_text_buttons[i].text, construct_position(get_x(ship_customization->modal[0].engine_buttons[i].position) + get_width(ship_customization->modal[0].engine_buttons[i].dimension) / 2 - get_text_width(ship_customization->modal[0].engine_text_buttons[i].text) / 2,
                                                                                                        get_y(ship_customization->modal[0].engine_text_buttons[i].position)));

        ship_customization->modal[0].weapon_buttons[i] = construct_button_with_animation(construct_animation(get_weapon_sprite_path(i), 15, construct_dimension(100, 100), FORWARD),
                                                                                         construct_position(animation_x + i * (100 + PADDING_BAR), animation_y),
                                                                                         construct_dimension(100, 100));

        ship_customization->modal[0].weapon_text_buttons[i] = construct_button_with_text(convert_int_to_string(get_weapon_price(i)),
                                                                                         construct_position(get_x(ship_customization->modal[0].weapon_buttons[i].position),
                                                                                                            get_y(ship_customization->modal[0].weapon_buttons[i].position) + get_height(ship_customization->modal[0].weapon_buttons[i].dimension) + 10),
                                                                                         construct_dimension(get_width(ship_customization->modal[0].weapon_buttons[i].dimension), 20),
                                                                                         MLV_COLOR_WHITE, MLV_COLOR_WHITE);
        set_text_position(&ship_customization->modal[0].weapon_text_buttons[i].text, construct_position(get_x(ship_customization->modal[0].weapon_buttons[i].position) + get_width(ship_customization->modal[0].weapon_buttons[i].dimension) / 2 - get_text_width(ship_customization->modal[0].weapon_text_buttons[i].text) / 2,
                                                                                                        get_y(ship_customization->modal[0].weapon_text_buttons[i].position)));
    }
}

static void initialize_player_2_modal(ShipCustomizationView *ship_customization)
{
    int i = 0;
    int modal_center_x, animation_x, animation_y;

    ship_customization->modal[1].background = construct_rectangle(construct_position(0, 225), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT - 450), MLV_rgba(50, 83, 255, 100));
    ship_customization->modal[1].title = construct_text("Acheter vos armes", construct_position(WINDOW_WIDTH / 2, 275), "assets/fonts/Play-Bold.ttf", 50, MLV_COLOR_WHITE);
    set_text_position(&ship_customization->modal[1].title, construct_position(get_x(ship_customization->modal[1].title.position) - get_text_width(ship_customization->modal[1].title) / 2, get_y(ship_customization->modal[1].title.position)));

    for (i = 0; i < MAX_SHIP_LEVEL; i++)
    {
        modal_center_x = get_x(ship_customization->modal[1].background.position) + get_width(ship_customization->modal[1].background.dimension) / 2;
        animation_x = modal_center_x - (MAX_SHIP_LEVEL * (100 + PADDING_BAR)) / 2;
        animation_y = get_y(ship_customization->modal[1].title.position) + get_height(ship_customization->modal[1].title.dimension) + 50;

        ship_customization->modal[1].engine_buttons[i] = construct_button_with_animation(construct_animation(get_engine_sprite_path(i), 15, construct_dimension(100, 100), FORWARD),
                                                                                         construct_position(animation_x + i * (100 + PADDING_BAR), animation_y),
                                                                                         construct_dimension(100, 100));

        ship_customization->modal[1].engine_text_buttons[i] = construct_button_with_text(convert_int_to_string(get_engine_price(i)),
                                                                                         construct_position(get_x(ship_customization->modal[1].engine_buttons[i].position),
                                                                                                            get_y(ship_customization->modal[1].engine_buttons[i].position) + get_height(ship_customization->modal[1].engine_buttons[i].dimension) + 10),
                                                                                         construct_dimension(get_width(ship_customization->modal[1].engine_buttons[i].dimension), 20),
                                                                                         MLV_COLOR_WHITE, MLV_COLOR_WHITE);
        set_text_position(&ship_customization->modal[1].engine_text_buttons[i].text, construct_position(get_x(ship_customization->modal[1].engine_buttons[i].position) + get_width(ship_customization->modal[1].engine_buttons[i].dimension) / 2 - get_text_width(ship_customization->modal[1].engine_text_buttons[i].text) / 2,
                                                                                                        get_y(ship_customization->modal[1].engine_text_buttons[i].position)));

        ship_customization->modal[1].weapon_buttons[i] = construct_button_with_animation(construct_animation(get_weapon_sprite_path(i), 15, construct_dimension(100, 100), FORWARD),
                                                                                         construct_position(animation_x + i * (100 + PADDING_BAR), animation_y),
                                                                                         construct_dimension(100, 100));

        ship_customization->modal[1].weapon_text_buttons[i] = construct_button_with_text(convert_int_to_string(get_weapon_price(i)),
                                                                                         construct_position(get_x(ship_customization->modal[1].weapon_buttons[i].position),
                                                                                                            get_y(ship_customization->modal[1].weapon_buttons[i].position) + get_height(ship_customization->modal[1].weapon_buttons[i].dimension) + 10),
                                                                                         construct_dimension(get_width(ship_customization->modal[1].weapon_buttons[i].dimension), 20),
                                                                                         MLV_COLOR_WHITE, MLV_COLOR_WHITE);
        set_text_position(&ship_customization->modal[1].weapon_text_buttons[i].text, construct_position(get_x(ship_customization->modal[1].weapon_buttons[i].position) + get_width(ship_customization->modal[1].weapon_buttons[i].dimension) / 2 - get_text_width(ship_customization->modal[1].weapon_text_buttons[i].text) / 2,
                                                                                                        get_y(ship_customization->modal[1].weapon_text_buttons[i].position)));
    }
}

static void initialize_player_1_ship_customization(ShipCustomizationView *ship_customization)
{
    int total_button_width = (BAR_WIDTH - 2 * PADDING_BAR) / 2;

    ship_customization->bar.background = construct_rectangle(construct_position(WINDOW_WIDTH - BAR_WIDTH - OFFSET, WINDOW_HEIGHT - BAR_HEIGHT - OFFSET),
                                                             construct_dimension(BAR_WIDTH, BAR_HEIGHT),
                                                             PRIMARY_RED_COLOR);

    ship_customization->bar.button[0] = construct_button_with_image(load_image("assets/images/icons/blue-engine.png", construct_dimension(BAR_HEIGHT - PADDING_BAR, BAR_HEIGHT - PADDING_BAR)),
                                                                    construct_position(get_x(ship_customization->bar.background.position) + PADDING_BAR,
                                                                                       get_y(ship_customization->bar.background.position) + PADDING_BAR / 2),
                                                                    construct_dimension(BAR_HEIGHT, BAR_HEIGHT));

    ship_customization->bar.button[1] = construct_button_with_image(load_image("assets/images/icons/weapon.png", construct_dimension(BAR_HEIGHT - PADDING_BAR, BAR_HEIGHT - PADDING_BAR)),
                                                                    construct_position(get_x(ship_customization->bar.button[0].image.position) + total_button_width + PADDING_BAR,
                                                                                       get_y(ship_customization->bar.background.position) + PADDING_BAR / 2),
                                                                    construct_dimension(BAR_HEIGHT, BAR_HEIGHT));
}

static void initialize_player_2_ship_customization(ShipCustomizationView *ship_customization)
{
    int total_button_width = (BAR_WIDTH - 2 * PADDING_BAR) / 2;
    ship_customization->bar.background = construct_rectangle(construct_position(OFFSET, WINDOW_HEIGHT - BAR_HEIGHT - OFFSET), construct_dimension(BAR_WIDTH, BAR_HEIGHT), PRIMARY_BLUE_COLOR);

    ship_customization->bar.button[0] = construct_button_with_image(load_image("assets/images/icons/red-engine.png", construct_dimension(BAR_HEIGHT - PADDING_BAR, BAR_HEIGHT - PADDING_BAR)),
                                                                    construct_position(get_x(ship_customization->bar.background.position) + PADDING_BAR,
                                                                                       get_y(ship_customization->bar.background.position) + PADDING_BAR / 2),
                                                                    construct_dimension(BAR_HEIGHT, BAR_HEIGHT));

    ship_customization->bar.button[1] = construct_button_with_image(load_image("assets/images/icons/weapon.png", construct_dimension(BAR_HEIGHT - PADDING_BAR, BAR_HEIGHT - PADDING_BAR)),
                                                                    construct_position(get_x(ship_customization->bar.button[0].image.position) + total_button_width + PADDING_BAR,
                                                                                       get_y(ship_customization->bar.background.position) + PADDING_BAR / 2),
                                                                    construct_dimension(BAR_HEIGHT, BAR_HEIGHT));
}

void draw_ship_customization(ShipCustomizationView ship_customization, Position mouse_position)
{
    int i = 0;
    draw_rectangle(ship_customization.bar.background);
    draw_border(ship_customization.bar.background.position, ship_customization.bar.background.dimension, 4, MLV_COLOR_WHITE);

    for (; i < CUSTOMIZATION_NUMBER_OF_BUTTONS; i++)
    {
        draw_button_image(ship_customization.bar.button[i]);
        if (is_button_hovered(ship_customization.bar.button[i], mouse_position))
        {
            draw_filled_rectangle(ship_customization.bar.button[i].image.position, ship_customization.bar.button[i].image.dimension, 0, MLV_rgba(255, 255, 255, 100), MLV_rgba(255, 255, 255, 100));
        }
    }

    if (ship_customization.is_modal_active)
    {
        draw_rectangle(ship_customization.modal[ship_customization.active_modal].background);
        draw_text(ship_customization.modal[ship_customization.active_modal].title);

        for (i = 0; i < MAX_SHIP_LEVEL; i++)
        {
            if (ship_customization.active_modal)
            {
                draw_hovered_button(ship_customization.modal[ship_customization.active_modal].weapon_buttons[i], mouse_position, MLV_rgba(125, 125, 125, 125), MLV_rgba(0, 0, 0, 125));
                draw_button_animation(ship_customization.modal[ship_customization.active_modal].weapon_buttons[i]);

                draw_button_text(ship_customization.modal[ship_customization.active_modal].weapon_text_buttons[i]);
            }
            else
            {
                draw_hovered_button(ship_customization.modal[ship_customization.active_modal].engine_buttons[i], mouse_position, MLV_rgba(125, 125, 125, 125), MLV_rgba(0, 0, 0, 125));
                draw_button_animation(ship_customization.modal[ship_customization.active_modal].engine_buttons[i]);

                draw_button_text(ship_customization.modal[ship_customization.active_modal].engine_text_buttons[i]);
            }
        }
    }
}

void free_ship_customization(ShipCustomizationView *ship_customization)
{
    int i = 0;

    for (; i < CUSTOMIZATION_NUMBER_OF_BUTTONS; i++)
    {
        free_button_image(&ship_customization->bar.button[i]);
        free_text(&ship_customization->modal[i].title);
    }

    for (i = 0; i < MAX_SHIP_LEVEL; i++)
    {
        free_button_animation(&ship_customization->modal[0].engine_buttons[i]);
        free_button_animation(&ship_customization->modal[0].weapon_buttons[i]);

        free_button_text(&ship_customization->modal[0].engine_text_buttons[i]);
        free_button_text(&ship_customization->modal[0].weapon_text_buttons[i]);
    }
}