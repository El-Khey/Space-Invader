#ifndef ANIMATION_H
#define ANIMATION_H

#include <MLV/MLV_all.h>
#include "./animation_infos.h"

#include "../position/position.h"
#include "../dimension/dimension.h"
#include "../image/image.h"

/**
 * @struct Animation
 * @brief Structure représentant une animation.
 *
 * Cette structure contient les informations nécessaires pour représenter une animation,
 * telles que le sprite, les frames, l'animation elle-même, le joueur d'animation, etc.
 */
typedef struct
{
    MLV_Image *sprite;            /** Structure MLV_Image pour stocker le sprite */
    MLV_Image **frames;           /** Structure MLV_Image pour stocker les frames de l'animation */
    MLV_Animation *animation;     /** Structure MLV_Animation pour stocker l'animation */
    MLV_Animation_player *player; /** Structure MLV_Animation_player pour jouer l'animation */

    int frame_count;    /** Nombre de frames dans l'animation */
    int frame_duration; /** Durée de chaque frame en millisecondes */

    int nb_layers;   /** Nombre de couches de l'animation */
    int nb_channels; /** Nombre de canaux de l'animation */

    int frame_rate; /** Fréquence d'images de l'animation */
    int layer;      /** Couche de l'animation */

    int start_time; /** Heure de début de l'animation */
    int end_time;   /** Heure de fin de l'animation */

    Dimension dimension;          /** Dimension de l'animation */
    AnimationDirection direction; /** Direction de l'animation */
} Animation;

/**
 * @brief Construit un nouvel objet Animation à partir d'un fichier.
 * L'animation est chargée à partir du fichier donné et des paramètres donnés.
 *
 * @param animation_file Le fichier à partir duquel charger l'animation
 * @param frame_count Le nombre de frames dans l'animation
 * @param dimension La dimension de l'animation
 * @param direction La direction de l'animation
 * @return Animation
 */
Animation construct_animation(char *path, int frame_count, Dimension dimension, AnimationDirection direction);

/**
 * @brief Redimensionne l'animation donnée à la dimension donnée.
 *
 * @param animation L'animation à redimensionner
 * @param dimension La dimension pour redimensionner l'animation
 */
void resize_animation(Animation *animation, Dimension dimension);

/**
 * @brief Joue l'animation donnée en avant.
 *
 * @param animation L'animation à jouer
 */
void play_animation(Animation *animation);

/**
 * @brief Joue l'animation donnée en arrière.
 *
 * @param animation L'animation à jouer
 */
void play_revert_animation(Animation *animation);

/**
 * @brief Arrête l'animation donnée.
 *
 * @param animation L'animation à arrêter
 */
void stop_animation(Animation *animation);

/**
 * @brief Rembobine l'animation.
 *
 * @param animation L'animation à rembobiner
 */
void rewind_animation(Animation *animation);

/**
 * @brief Vérifie si l'animation donnée est terminée.
 *
 * @param animation L'animation à vérifier
 * @param current_time Le temps actuel
 * @return 1 si l'animation est terminée, 0 sinon
 */
int is_animation_finished(Animation animation, int current_time);

/**
 * @brief Dessine l'animation donnée à la position donnée.
 *
 * @param animation L'animation à dessiner
 * @param position La position où dessiner l'animation
 */
void draw_animation(Animation animation, Position position);

/**
 * @brief Libère l'animation donnée.
 *
 * @param animation L'animation à libérer
 */
void free_animation(Animation *animation);

#endif /** ANIMATION_H */
