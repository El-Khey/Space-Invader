#ifndef HITBOX_H
#define HITBOX_H

#include "../position/position.h"
#include "../dimension/dimension.h"
#include "../utils.h"

/**
 * @brief Structure représentant une boîte de collision.
 *
 * Cette structure contient les informations nécessaires pour définir une boîte de collision.
 * Elle comprend la position de la boîte, sa dimension et un indicateur indiquant si elle est en collision avec une autre boîte.
 */
typedef struct
{
    Position position;   /**< La position de la boîte de collision. */
    Dimension dimension; /**< La dimension de la boîte de collision. */

    int is_colliding; /**< Indicateur de collision avec une autre boîte. */
} Hitbox;

/**
 * @brief Construit un nouvel objet Hitbox.
 *
 * @param position La position de la hitbox.
 * @param dimension Les dimensions de la hitbox.
 * @return Hitbox L'objet Hitbox construit.
 */
Hitbox construct_hitbox(Position position, Dimension dimension);

/**
 * @brief Vérifie si la première hitbox donnée entre en collision avec la deuxième hitbox donnée.
 *
 * @param hitbox1 La première hitbox à vérifier.
 * @param hitbox2 La deuxième hitbox à vérifier.
 * @return int Retourne 1 si les hitbox entrent en collision, 0 sinon.
 */
int is_hitbox_colliding(Hitbox hitbox1, Hitbox hitbox2);

/**
 * @brief Vérifie si la position donnée se trouve à l'intérieur de la hitbox donnée.
 *
 * @param hitbox La hitbox à vérifier.
 * @param position La position à vérifier.
 * @return int Retourne 1 si la position est à l'intérieur de la hitbox, 0 sinon.
 */
int is_position_inside_hitbox(Hitbox hitbox, Position position);

/**
 * @brief Définit la position de la hitbox donnée.
 *
 * @param hitbox La hitbox dont on veut définir la position.
 * @param position La position à définir.
 */
void set_hitbox_position(Hitbox *hitbox, Position position);

/**
 * @brief Définit les dimensions de la hitbox donnée.
 *
 * @param hitbox La hitbox dont on veut définir les dimensions.
 * @param dimension Les dimensions à définir.
 */
void set_hibtox_dimension(Hitbox *hitbox, Dimension dimension);

/**
 * @brief Dessine la hitbox donnée à l'écran.
 *
 * @param hitbox La hitbox à dessiner.
 * @param color La couleur avec laquelle dessiner la hitbox.
 */
void draw_hitbox(Hitbox hitbox, MLV_Color color);

#endif