#ifndef ANIMATION_INFOS_H
#define ANIMATION_INFOS_H

#define MAX_CHAR_LENGTH 25

/**
 * @brief Type d'animation.
 */
typedef enum
{
    WALK,         /**< Animation de marche. */
    RUN,          /**< Animation de course. */
    ATTACK_1,     /**< Animation d'attaque 1. */
    ATTACK_2,     /**< Animation d'attaque 2. */
    ATTACK_3,     /**< Animation d'attaque 3. */
    HURT,         /**< Animation de blessure. */
    DEATH,        /**< Animation de mort. */
    IDLE,         /**< Animation d'inactivité. */
    nb_animations /**< Nombre total d'animations. */
} AnimationType;

/**
 * @brief Direction de l'animation.
 */
typedef enum
{
    FORWARD,    /**< Animation vers l'avant. */
    BACKWARD,   /**< Animation vers l'arrière. */
    VERTICAL,   /**< Animation verticale. */
    ROTATION_90 /**< Animation de rotation à 90 degrés. */
} AnimationDirection;

/**
 * @brief Informations sur une animation.
 */
typedef struct
{
    AnimationDirection direction; /**< Direction de l'animation. */
    AnimationType type;           /**< Type d'animation. */

    char action_name[MAX_CHAR_LENGTH]; /**< Nom de l'action. */
    int frame_count;                   /**< Nombre de frames. */
} AnimationInfos;

/**
 * @brief Liste des informations sur les animations.
 */
typedef struct
{
    AnimationInfos animation_infos[nb_animations]; /**< Tableau des informations sur les animations. */
    int animation_infos_count;                     /**< Nombre d'informations sur les animations. */
} AnimationInfosList;

#endif