#include "../../../../include/game/controller/enemy_controller.h"

enemy_controller construct_enemy_controller()
{
    enemy_controller enemy_controller;

    enemy_controller.last_enemy_spawn_time = 0;
    enemy_controller.delay_between_spawn = 3000;

    enemy_controller.enemy_spawned = 0;
    enemy_controller.enemy_spawn_count = MAX_ENEMY_SPAWN_COUNT;

    return enemy_controller;
}

void generate_enemies(enemy_controller *controller)
{
    if (controller->last_enemy_spawn_time + controller->delay_between_spawn < MLV_get_time() && controller->enemy_spawned < controller->enemy_spawn_count)
    {
        controller->last_enemy_spawn_time = MLV_get_time();
        controller->enemies[controller->enemy_spawned] = construct_enemy(rand() % nb_enemy_class);
        controller->enemy_spawned++;
    }
}

/**
 * Vérifie si l'ennemi est sorti de l'écran.
 *
 * @param enemy L'ennemi à vérifier.
 * @return 1 si l'ennemi est sorti de l'écran, 0 sinon.
 */
static int is_enemy_out_of_screen(Enemy enemy)
{
    return get_y(enemy.position) > WINDOW_HEIGHT + get_height(enemy.dimension);
}

/**
 * Vérifie si le vaisseau ennemi peut tirer.
 *
 * Cette fonction vérifie si le vaisseau ennemi peut tirer en fonction de la position et de la dimension du vaisseau du joueur.
 * Elle utilise les coordonnées x et y pour déterminer si le centre du vaisseau du joueur se trouve entre les bords gauche et droit du vaisseau ennemi,
 * et si le vaisseau du joueur se trouve en dessous du vaisseau ennemi.
 * De plus, elle vérifie également si le nombre de projectiles du vaisseau ennemi est inférieur à la limite maximale et si le vaisseau ennemi n'est pas mort.
 *
 * @param heros_position La position du vaisseau du joueur.
 * @param heros_dimension La dimension du vaisseau du joueur.
 * @param enemy Le vaisseau ennemi.
 * @return 1 si le vaisseau ennemi peut tirer, 0 sinon.
 *
 * TODO: Ajouter une marge d'erreur pour que le vaisseau ennemi puisse tirer.
 */
static int can_ship_fire(Position heros_position, Dimension heros_dimension, Enemy enemy)
{
    return get_y(heros_position) > get_y(enemy.position) + get_height(enemy.dimension) &&
           get_x(heros_position) + get_width(heros_dimension) / 2 > get_x(enemy.position) &&
           get_x(heros_position) + get_width(heros_dimension) / 2 < get_x(enemy.position) + get_width(enemy.dimension) &&
           enemy.list.projectiles_count < MAX_PROJECTILES &&
           !is_enemy_dead(enemy);
}

/**
 * @brief Gère les attaques des ennemis.
 *
 * Cette fonction vérifie si le vaisseau ennemi peut tirer sur le héros. Si c'est le cas, elle crée un projectile ennemi, met à jour son état et joue l'animation d'attaque.
 *
 * @param enemy Le vaisseau ennemi.
 * @param heros Le héros.
 */
static void handle_enemy_attacks(Enemy *enemy, Heros heros)
{
    /** Vérifie si le vaisseau ennemi peut tirer sur le héros */
    if (can_ship_fire(heros.position, heros.dimension, *enemy))
    {
        /** Vérifie si l'événement d'attaque est en cours */
        if (enemy->event_in_process != ATTACKING)
        {
            /** Crée un projectile ennemi et met à jour sa vitesse */
            enemy->list.projectiles[enemy->list.projectiles_count] = construct_enemy_projectile(enemy->list.active_bullet_type, enemy->position, enemy->dimension);
            enemy->list.projectiles[enemy->list.projectiles_count].speed = -enemy->list.projectiles[enemy->list.projectiles_count].speed;
            enemy->list.projectiles_count++;

            /** Met à jour l'état de l'événement et joue l'animation d'attaque */
            enemy->event_in_process = ATTACKING;
            enemy->enemy_animation.active_state = ATTACK;
            play_animation(&enemy->enemy_animation.ship[enemy->enemy_animation.active_state]);
        }
    }

    /** Vérifie si l'animation d'attaque est terminée */
    if (is_animation_finished(enemy->enemy_animation.ship[enemy->enemy_animation.active_state], MLV_get_time()) && enemy->event_in_process == ATTACKING)
    {
        /** Rembobine et arrête l'animation d'attaque */
        rewind_animation(&enemy->enemy_animation.ship[enemy->enemy_animation.active_state]);
        stop_animation(&enemy->enemy_animation.ship[enemy->enemy_animation.active_state]);

        /** Met à jour l'état de l'événement et l'état actif de l'animation */
        enemy->event_in_process = NOTHING;
        enemy->enemy_animation.active_state = BASE;
    }
}

/**
 * @brief Gère la mort d'un ennemi.
 *
 * Cette fonction vérifie si l'ennemi est mort. Si c'est le cas, elle met à jour son état, joue l'animation de destruction et supprime l'ennemi du contrôleur.
 *
 * @param controller Le contrôleur des ennemis.
 * @param index L'index de l'ennemi à gérer.
 */
static void handle_enemy_death(enemy_controller *controller, int index)
{
    /** Vérifie si l'ennemi est mort */
    if (is_enemy_dead(controller->enemies[index]))
    {
        /** Vérifie si l'événement de mort est en cours */
        if (controller->enemies[index].event_in_process != DYING)
        {
            /** Met à jour l'état de l'événement et joue l'animation de destruction */
            controller->enemies[index].event_in_process = DYING;
            controller->enemies[index].enemy_animation.active_state = DESTRUCTION;

            play_animation(&controller->enemies[index].enemy_animation.ship[controller->enemies[index].enemy_animation.active_state]);
        }

        /** Vérifie si l'animation de destruction est terminée */
        if (is_animation_finished(controller->enemies[index].enemy_animation.ship[controller->enemies[index].enemy_animation.active_state], MLV_get_time()) && controller->enemies[index].event_in_process == DYING)
        {
            /** Réduit le nombre d'ennemis et remplace l'ennemi supprimé par le dernier ennemi du contrôleur */
            controller->enemy_spawned--;
            controller->enemies[index] = controller->enemies[controller->enemy_spawned];
            controller->enemies[index].event_in_process = NOTHING;
        }
    }
}

void update_enemies(enemy_controller *controller, Players *players)
{
    int i, j;

    for (j = 0; j < controller->enemy_spawned; j++)
    {
        move_enemy(&controller->enemies[j]);
        draw_enemy(controller->enemies[j]);

        update_projectiles(&controller->enemies[j].list);
        handle_enemy_death(controller, j);

        if (is_enemy_out_of_screen(controller->enemies[j]))
        {
            controller->enemy_spawned--;
            controller->enemies[j] = controller->enemies[controller->enemy_spawned];
            for (i = 0; i < players->nb_players; i++)
            {
                players->players[i].heros.health -= 1;
            }
        }

        for (i = 0; i < players->nb_players; i++)
        {
            if (!is_heros_alive(players->players[i].heros))
            {
                continue;
            }
            handle_enemy_attacks(&controller->enemies[j], players->players[i].heros);
        }
    }
}

void free_enemy_controller(enemy_controller *controller)
{
    int i;
    for (i = 0; i < controller->enemy_spawned; i++)
    {
        free_enemy(&controller->enemies[i]);
    }
}