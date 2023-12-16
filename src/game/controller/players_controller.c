#include "../../../include/game/controller/players_controller.h"

/**
 * Gère les actions du héros du joueur.
 *
 * Cette fonction vérifie les actions du joueur et met à jour la position du héros en conséquence.
 *
 * @param player Le joueur dont le héros est contrôlé.
 * @param event_manager Le gestionnaire d'événements contenant les informations sur les touches enfoncées.
 */
static void handle_heros_actions(Player *player, EventManager event_manager)
{
    /** Vérifie si la position du héros après le déplacement vers la droite est toujours à l'intérieur de la fenêtre de jeu */
    if (is_position_with_dimension_inside_rect(construct_position(player->heros.position.x + player->heros.speed, player->heros.position.y), player->heros.dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)) && event_manager.keyboard_manager.event[player->id].arrow_keys.key_right)
    {
        move_heros_right(&player->heros);
    }

    /** Vérifie si la position du héros après le déplacement vers la gauche est toujours à l'intérieur de la fenêtre de jeu */
    if (is_position_with_dimension_inside_rect(construct_position(player->heros.position.x - player->heros.speed, player->heros.position.y), player->heros.dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)) && event_manager.keyboard_manager.event[player->id].arrow_keys.key_left)
    {
        move_heros_left(&player->heros);
    }

    /** Vérifie si la position du héros après le déplacement vers le bas est toujours à l'intérieur de la fenêtre de jeu */
    if (is_position_with_dimension_inside_rect(construct_position(player->heros.position.x, player->heros.position.y + player->heros.speed), player->heros.dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)) && event_manager.keyboard_manager.event[player->id].arrow_keys.key_down)
    {
        move_heros_down(&player->heros);
    }

    /** Vérifie si la position du héros après le déplacement vers le haut est toujours à l'intérieur de la fenêtre de jeu */
    if (is_position_with_dimension_inside_rect(construct_position(player->heros.position.x, player->heros.position.y - player->heros.speed), player->heros.dimension, construct_position(0, 0), construct_dimension(WINDOW_WIDTH, WINDOW_HEIGHT)) && event_manager.keyboard_manager.event[player->id].arrow_keys.key_up)
    {
        player->heros.is_boost_activated = 1;
        move_heros_up(&player->heros);
    }
    else
    {
        player->heros.is_boost_activated = 0;
    }
}

/**
 * Gère les projectiles du joueur.
 * Cette fonction est appelée pour gérer les projectiles du joueur lorsqu'il attaque.
 *
 * @param player Le joueur dont les projectiles doivent être gérés.
 * @param event_manager Le gestionnaire d'événements pour détecter les touches d'attaque du clavier.
 */
static void handle_player_projectiles(Player *player, EventManager event_manager)
{
    /** Vérifie si la touche d'attaque 1 du joueur est enfoncée et s'il y a encore de la place pour des projectiles. */
    if (event_manager.keyboard_manager.event[player->id].attack_keys.key_attack_1 && player->heros.list.projectiles_count < MAX_PROJECTILES)
    {
        /** Vérifie si le joueur n'est pas déjà en train de tirer. */
        if (!player->heros.is_firing)
        {
            /** Joue l'animation de tir de l'arme du joueur. */
            play_animation(&player->heros.weapons_animations[player->heros.active_weapon].weapon_shooting);
            player->heros.is_firing = 1;

            /** Construit un projectile pour le joueur et l'ajoute à la liste des projectiles. */
            player->heros.list.projectiles[player->heros.list.projectiles_count] = construct_heros_projectile(player->heros.list.active_bullet_type, player->heros.position, player->heros.dimension);
            player->heros.list.projectiles_count += 1;
        }
    }

    /** Vérifie si l'animation de tir de l'arme du joueur est terminée et que le joueur est en train de tirer. */
    if (is_animation_finished(player->heros.weapons_animations[player->heros.active_weapon].weapon_shooting, MLV_get_time()) && player->heros.is_firing)
    {
        /** Rembobine et arrête l'animation de tir de l'arme du joueur. */
        rewind_animation(&player->heros.weapons_animations[player->heros.active_weapon].weapon_shooting);
        stop_animation(&player->heros.weapons_animations[player->heros.active_weapon].weapon_shooting);

        player->heros.is_firing = 0;
    }

    /** Met à jour les projectiles du joueur. */
    update_projectiles(&player->heros.list);
}

/**
 * @brief Gère le bonus du joueur.
 *
 * Cette fonction vérifie si le bouclier du joueur est actif et si le temps d'activation est dépassé.
 * Si le temps d'activation est dépassé, le bouclier du joueur est réinitialisé.
 *
 * @param player Le joueur dont le bonus doit être géré.
 */
static void handle_player_bonus(Player *player)
{
    if (player->heros.shield.is_active)
    {
        if (player->heros.shield.active_time <= MLV_get_time())
        {
            player->heros.shield = construct_shield(SHIELD_NONE, player->heros.position, player->heros.dimension);
        }
    }
}

/**
 * @brief Gère les événements de personnalisation du vaisseau.
 *
 * Cette fonction vérifie si un bouton de personnalisation du vaisseau a été cliqué.
 * Si un seul joueur modifie le vaisseau, la fenêtre modale est désactivée.
 * Sinon, la fenêtre modale est activée ou désactivée en fonction de son état actuel.
 *
 * @param ship_customization La vue de personnalisation du vaisseau.
 * @param event_manager Le gestionnaire d'événements.
 * @param is_one_player_modifying_ship Indique si un seul joueur modifie le vaisseau.
 */
static void handle_ship_customization_events(ShipCustomizationView *ship_customization, EventManager event_manager, int is_one_player_modifying_ship)
{
    int i = 0;
    for (i = 0; i < CUSTOMIZATION_NUMBER_OF_BUTTONS; i++)
    {
        if (is_button_clicked(ship_customization->bar.button[i], event_manager.mouse_manager))
        {
            if (is_one_player_modifying_ship)
            {
                ship_customization->is_modal_active = 0;
            }
            else
            {
                ship_customization->is_modal_active = !ship_customization->is_modal_active;
                ship_customization->active_modal = i;
            }
        }
    }
}

/**
 * Gère la sélection de personnalisation du vaisseau pour le joueur.
 *
 * @param player Le joueur dont le vaisseau est personnalisé.
 * @param event_manager Le gestionnaire d'événements.
 */
static void handle_ship_customization_selection(Player *player, EventManager event_manager)
{
    int i;
    for (i = 0; i < MAX_SHIP_LEVEL; i++)
    {
        if (player->ship_customization_view.is_modal_active && player->ship_customization_view.active_modal == MODAL_ENGINE && is_button_clicked(player->ship_customization_view.modal[player->id].engine_buttons[i], event_manager.mouse_manager))
        {
            if (player->gold >= get_engine_price(i))
            {
                player->gold -= get_engine_price(i);
                set_text_content(&player->view.gold.gold_text, convert_int_to_string(player->gold));
                player->heros.active_engine = i;
            }
        }
        else if (player->ship_customization_view.is_modal_active && player->ship_customization_view.active_modal == MODAL_WEAPON && is_button_clicked(player->ship_customization_view.modal[player->id].weapon_buttons[i], event_manager.mouse_manager))
        {
            if (player->gold >= get_weapon_price(i))
            {
                player->gold -= get_weapon_price(i);
                set_text_content(&player->view.gold.gold_text, convert_int_to_string(player->gold));
                player->heros.active_weapon = i;
                player->heros.list.active_bullet_type = player->heros.active_weapon;
            }
        }
    }
}

void update_players(GameManager *game_manager, EventManager event_manager)
{
    int i = 0;
    int is_one_player_modifying_ship = 0;
    int player_id_to_update = 0;

    for (; i < game_manager->players.nb_players; i++)
    {
        if (!is_heros_alive(game_manager->players.players[i].heros))
        {
            continue;
        }

        handle_heros_actions(&game_manager->players.players[i], event_manager);
        handle_player_projectiles(&game_manager->players.players[i], event_manager);

        handle_player_bonus(&game_manager->players.players[i]);

        draw_player(game_manager->players.players[i]);
        draw_ship_customization(game_manager->players.players[i].ship_customization_view, event_manager.mouse_manager.position);
        if (game_manager->players.players[i].ship_customization_view.is_modal_active)
        {
            is_one_player_modifying_ship = 1;
            player_id_to_update = i;
        }
    }

    if (is_one_player_modifying_ship)
    {
        handle_ship_customization_selection(&game_manager->players.players[player_id_to_update], event_manager);
    }

    for (i = 0; i < game_manager->players.nb_players; i++)
    {
        handle_ship_customization_events(&game_manager->players.players[i].ship_customization_view, event_manager, is_one_player_modifying_ship);
    }
}