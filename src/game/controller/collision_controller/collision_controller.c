#include "../../../../include/game/controller/collision_controller/collision_controller.h"
#include "../../../../include/game/controller/players_controller.h"

/**
 * @brief Gère la collision entre le héros et les ennemis à courte portée.
 *
 * Cette fonction vérifie s'il y a une collision entre la hitbox du héros et la hitbox de chaque ennemi dans le contrôleur d'ennemis.
 * Si une collision est détectée, la fonction met à jour la santé de l'ennemi et du héros en conséquence.
 * Si la santé de l'ennemi atteint 0, il est considéré comme vaincu.
 * Si le bouclier du héros n'est pas actif, la santé du héros est réduite par les dégâts de l'ennemi.
 * Enfin, la fonction met à jour le vaisseau actif du héros.
 *
 * @param heros Pointeur vers l'objet héros.
 * @param enemy_controller Pointeur vers l'objet contrôleur d'ennemis.
 */
static void handle_heros_and_enemy_close_range_collision(Heros *heros, enemy_controller *enemy_controller)
{
    int i;
    for (i = 0; i < enemy_controller->enemy_spawned; i++)
    {
        if (is_hitbox_colliding(heros->hitbox, enemy_controller->enemies[i].hitbox))
        {
            if (enemy_controller->enemies[i].health <= 0)
            {
                continue;
            }

            enemy_controller->enemies[i].health = 0;
            if (!heros->shield.is_active)
            {
                heros->health -= enemy_controller->enemies[i].damage;
            }
            update_heros_active_ship(heros);
        }
    }
}

/**
 * @brief Gère la collision entre les projectiles du héros et les ennemis.
 *
 * Cette fonction vérifie s'il y a une collision entre chaque projectile tiré par le héros et chaque ennemi à l'écran.
 * Si une collision est détectée, la santé de l'ennemi est réduite par les dégâts du projectile.
 * La balle qui a causé la collision est supprimée de la liste des balles.
 * Si toutes les balles d'un projectile sont supprimées, le projectile lui-même est supprimé de la liste des projectiles.
 * Si un ennemi est tué, le score du joueur est augmenté et l'or du joueur est mis à jour en conséquence.
 *
 * @param player L'objet joueur.
 * @param enemy_controller L'objet contrôleur d'ennemis.
 */
static void handle_heros_projectiles_and_enemy_collision(Player *player, enemy_controller *enemy_controller)
{
    int i, j, k;
    for (i = 0; i < player->heros.list.projectiles_count; i++)
    {
        for (j = 0; j < enemy_controller->enemy_spawned; j++)
        {
            for (k = 0; k < player->heros.list.projectiles[i].list.bullets_count; k++)
            {
                if (is_hitbox_colliding(player->heros.list.projectiles[i].list.bullets[k].hitbox, enemy_controller->enemies[j].hitbox))
                {
                    enemy_controller->enemies[j].health -= player->heros.list.projectiles[i].damage;

                    player->heros.list.projectiles[i].list.bullets[k] = player->heros.list.projectiles[i].list.bullets[player->heros.list.projectiles[i].list.bullets_count - 1];
                    player->heros.list.projectiles[i].list.bullets_count--;

                    if (player->heros.list.projectiles[i].list.bullets_count == 0)
                    {
                        player->heros.list.projectiles[i] = player->heros.list.projectiles[player->heros.list.projectiles_count - 1];
                        player->heros.list.projectiles_count--;
                    }

                    if (is_enemy_dead(enemy_controller->enemies[j]))
                    {
                        player->score += 1;
                        strcpy(player->view.score_text.text, concat("Score: ", convert_int_to_string(player->score)));

                        player->gold += enemy_controller->enemies[j].score;
                        strcpy(player->view.gold.gold_text.text, convert_int_to_string(player->gold));
                    }
                }
            }
        }
    }
}

/**
 * @brief Gère la collision entre les projectiles ennemis et le héros.
 *
 * Cette fonction vérifie s'il y a une collision entre les projectiles ennemis et la hitbox du héros.
 * Si une collision est détectée, la santé du héros est réduite par les dégâts du projectile.
 * Si le bouclier du héros n'est pas actif, les dégâts sont appliqués à la santé du héros.
 * La balle en collision est supprimée de la liste des balles du projectile.
 * Si la liste des balles devient vide, le projectile est supprimé de la liste des projectiles de l'ennemi.
 * Enfin, le vaisseau actif du héros est mis à jour.
 *
 * @param enemy_controller L'objet du contrôleur des ennemis.
 * @param heros L'objet du héros.
 */
static void handle_enemy_projectiles_collision(enemy_controller *enemy_controller, Heros *heros)
{
    int i, j, k;
    for (i = 0; i < enemy_controller->enemy_spawned; i++)
    {
        for (j = 0; j < enemy_controller->enemies[i].list.projectiles_count; j++)
        {
            for (k = 0; k < enemy_controller->enemies[i].list.projectiles[j].list.bullets_count; k++)
            {
                if (is_hitbox_colliding(enemy_controller->enemies[i].list.projectiles[j].list.bullets[k].hitbox, heros->hitbox))
                {
                    if (!heros->shield.is_active)
                    {
                        heros->health -= enemy_controller->enemies[i].list.projectiles[j].damage;
                    }

                    enemy_controller->enemies[i].list.projectiles[j].list.bullets[k] = enemy_controller->enemies[i].list.projectiles[j].list.bullets[enemy_controller->enemies[i].list.projectiles[j].list.bullets_count - 1];
                    enemy_controller->enemies[i].list.projectiles[j].list.bullets_count--;

                    if (enemy_controller->enemies[i].list.projectiles[j].list.bullets_count == 0)
                    {
                        enemy_controller->enemies[i].list.projectiles[j] = enemy_controller->enemies[i].list.projectiles[enemy_controller->enemies[i].list.projectiles_count - 1];
                        enemy_controller->enemies[i].list.projectiles_count--;
                    }

                    update_heros_active_ship(heros);
                }
            }
        }
    }
}

/**
 * Gère la sélection d'un bonus et applique l'effet correspondant au héros.
 *
 * @param heros Le héros.
 * @param bonus Le bonus.
 */
static void handle_bonus_selection(Heros *heros, Bonus bonus)
{
    switch (bonus.type)
    {
    case BONUS_TYPE_SHIELD_ALL_AROUND:
        heros->shield = construct_shield(SHIELD_ALL_AROUND, heros->position, heros->dimension);
        break;

    case BONUS_TYPE_SHIELD_FRONT_AND_SIDE:
        heros->shield = construct_shield(SHIELD_FRONT_AND_SIDE, heros->position, heros->dimension);
        break;

    case BONUS_TYPE_SHIELD_FRONT:
        heros->shield = construct_shield(SHIELD_FRONT, heros->position, heros->dimension);
        break;

    case BONUS_TYPE_SHIELD_INVINCIBILITY:
        heros->shield = construct_shield(SHIELD_INVINCIBILITY, heros->position, heros->dimension);
        break;

    case BONUS_TYPE_LIFE:
        heros->health = (heros->health == MAX_PLAYER_LIFE) ? heros->health : heros->health + 1;
        break;

    default:
        fprintf(stderr, "Erreur : type de bonus inconnu : %d\n", bonus.type);
        break;
    }
}

/**
 * @brief Gère la collision entre le héros du joueur et les bonus.
 *
 * Cette fonction vérifie si la hitbox du héros du joueur entre en collision avec l'un des bonus apparus.
 * Si une collision est détectée, le bonus correspondant est marqué comme sélectionné et son effet est appliqué au héros du joueur.
 *
 * @param player Un pointeur vers la structure Player représentant le joueur.
 * @param bonus_controller Un pointeur vers la structure bonus_controller gérant les bonus.
 */
static void handle_heros_and_bonus_collision(Player *player, bonus_controller *bonus_controller)
{
    int i;
    for (i = 0; i < bonus_controller->bonus_spawned; i++)
    {
        if (is_hitbox_colliding(player->heros.hitbox, bonus_controller->bonus[i].hitbox))
        {
            bonus_controller->bonus[i].is_selected = 1;
            handle_bonus_selection(&player->heros, bonus_controller->bonus[i]);
        }
    }
}

/**
 * @brief Gère la collision entre les projectiles du héros et les objets bonus.
 *
 * Cette fonction vérifie s'il y a une collision entre chaque projectile tiré par le héros et chaque objet bonus apparu.
 * Si une collision est détectée, l'objet bonus est marqué comme sélectionné et l'action appropriée est effectuée.
 * La balle qui a collisionné avec l'objet bonus est supprimée de la liste des balles.
 * Si toutes les balles sont supprimées, le projectile lui-même est supprimé de la liste des projectiles.
 *
 * @param heros L'objet du héros.
 * @param bonus_controller L'objet du contrôleur des bonus.
 */
static void handle_heros_projectiles_and_bonus_collision(Heros *heros, bonus_controller *bonus_controller)
{
    int i, j, k;
    for (i = 0; i < heros->list.projectiles_count; i++)
    {
        for (j = 0; j < bonus_controller->bonus_spawned; j++)
        {
            for (k = 0; k < heros->list.projectiles[i].list.bullets_count; k++)
            {
                if (is_hitbox_colliding(heros->list.projectiles[i].list.bullets[k].hitbox, bonus_controller->bonus[j].hitbox))
                {
                    bonus_controller->bonus[j].is_selected = 1;
                    handle_bonus_selection(heros, bonus_controller->bonus[j]);

                    heros->list.projectiles[i].list.bullets[k] = heros->list.projectiles[i].list.bullets[heros->list.projectiles[i].list.bullets_count - 1];
                    heros->list.projectiles[i].list.bullets_count--;

                    if (heros->list.projectiles[i].list.bullets_count == 0)
                    {
                        heros->list.projectiles[i] = heros->list.projectiles[heros->list.projectiles_count - 1];
                        heros->list.projectiles_count--;
                    }
                }
            }
        }
    }
}

/**
 * @brief Gère la collision entre les astéroïdes et le vaisseau du joueur à courte portée.
 *
 * Cette fonction vérifie s'il y a une collision entre la boîte de collision du vaisseau du joueur et les boîtes de collision des astéroïdes
 * gérés par le contrôleur d'astéroïdes. Si une collision est détectée, la fonction met à jour la santé du joueur et la santé de l'astéroïde en conséquence.
 * Si le bouclier du joueur n'est pas actif et que l'astéroïde n'est pas mort, la santé du joueur est réduite de la valeur des dégâts de l'astéroïde.
 * La santé de l'astéroïde est définie à 0 et le vaisseau actif du héros du joueur est mis à jour.
 *
 * @param player Pointeur vers la structure Player représentant les données du joueur.
 * @param asteroid_controller Pointeur vers la structure asteroid_controller gérant les astéroïdes.
 */
static void handle_asteroid_and_heros_close_range_collision(Player *player, asteroid_controller *asteroid_controller)
{
    int i;
    for (i = 0; i < asteroid_controller->asteroid_spawned; i++)
    {
        if (is_hitbox_colliding(player->heros.hitbox, asteroid_controller->asteroids[i].hitbox))
        {

            if (!player->heros.shield.is_active && !is_asteroid_dead(asteroid_controller->asteroids[i]))
            {
                player->heros.health -= asteroid_controller->asteroids[i].damage;
            }

            asteroid_controller->asteroids[i].health = 0;
            update_heros_active_ship(&player->heros);
        }
    }
}

/**
 * @brief Gère la collision entre les astéroïdes et les projectiles du héros.
 *
 * Cette fonction vérifie s'il y a une collision entre chaque projectile de la liste et chaque astéroïde du contrôleur d'astéroïdes.
 * Si une collision est détectée, la santé de l'astéroïde est définie à 0 et le projectile est supprimé de la liste.
 *
 * @param list La liste des projectiles.
 * @param asteroid_controller Le contrôleur d'astéroïdes.
 */
static void handle_asteroid_and_heros_projectiles_collision(Projectiles *list, asteroid_controller *asteroid_controller)
{
    int i, j, k;
    for (i = 0; i < list->projectiles_count; i++)
    {
        for (k = 0; k < asteroid_controller->asteroid_spawned; k++)
        {
            for (j = 0; j < list->projectiles[i].list.bullets_count; j++)
            {
                if (is_hitbox_colliding(list->projectiles[i].list.bullets[j].hitbox, asteroid_controller->asteroids[k].hitbox))
                {
                    asteroid_controller->asteroids[k].health = 0;

                    list->projectiles[i].list.bullets[j] = list->projectiles[i].list.bullets[list->projectiles[i].list.bullets_count - 1];
                    list->projectiles[i].list.bullets_count--;

                    if (list->projectiles[i].list.bullets_count == 0)
                    {
                        list->projectiles[i] = list->projectiles[list->projectiles_count - 1];
                        list->projectiles_count--;
                    }
                }
            }
        }
    }
}

/**
 * Gère la collision entre le héros du joueur et les astéroïdes.
 *
 * Cette fonction appelle deux fonctions d'aide pour gérer la collision à courte portée
 * entre le héros et les astéroïdes, et la collision entre les projectiles du héros
 * et les astéroïdes.
 *
 * @param player L'objet joueur.
 * @param asteroid_controller L'objet contrôleur d'astéroïdes.
 */
static void handle_heros_asteroid_collision(Player *player, asteroid_controller *asteroid_controller)
{
    handle_asteroid_and_heros_close_range_collision(player, asteroid_controller);
    handle_asteroid_and_heros_projectiles_collision(&player->heros.list, asteroid_controller);
}

/**
 * Gère la collision entre le héros et les bonus.
 *
 * @param player Le joueur.
 * @param bonus_controller Le contrôleur des bonus.
 */
static void handle_heros_bonus_collision(Player *player, bonus_controller *bonus_controller)
{
    handle_heros_and_bonus_collision(player, bonus_controller);
    handle_heros_projectiles_and_bonus_collision(&player->heros, bonus_controller);
}

/**
 * Gère la collision entre le héros et les ennemis.
 * Cette fonction appelle les fonctions de gestion des collisions de proximité, des projectiles du héros et des projectiles ennemis.
 *
 * @param player Le joueur contenant le héros.
 * @param enemy_controller Le contrôleur des ennemis.
 */
static void handle_heros_enemy_collision(Player *player, enemy_controller *enemy_controller)
{
    handle_heros_and_enemy_close_range_collision(&player->heros, enemy_controller);
    handle_heros_projectiles_and_enemy_collision(player, enemy_controller);
    handle_enemy_projectiles_collision(enemy_controller, &player->heros);
}

void handle_heros_collision(Players *players, enemy_controller *enemy_controller, bonus_controller *bonus_controller, asteroid_controller *asteroid_controller)
{
    int i = 0;
    for (; i < players->nb_players; i++)
    {
        if (!is_heros_alive(players->players[i].heros))
        {
            continue;
        }

        handle_heros_enemy_collision(&players->players[i], enemy_controller);
        handle_heros_bonus_collision(&players->players[i], bonus_controller);
        handle_heros_asteroid_collision(&players->players[i], asteroid_controller);
    }
}
