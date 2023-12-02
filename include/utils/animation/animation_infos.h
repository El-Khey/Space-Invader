#ifndef ANIMATION_INFOS_H
#define ANIMATION_INFOS_H

#define MAX_CHAR_LENGTH 25

typedef enum
{
    WALK,
    RUN,
    ATTACK_1,
    ATTACK_2,
    ATTACK_3,
    HURT,
    DEATH,
    IDLE,
    nb_animations
} AnimationType;

typedef enum
{
    FORWARD,
    BACKWARD,
    VERTICAL,
    ROTATION_90
} AnimationDirection;

typedef struct
{
    AnimationDirection direction;
    AnimationType type;

    char action_name[MAX_CHAR_LENGTH];
    int frame_count;
} AnimationInfos;

typedef struct
{
    AnimationInfos animation_infos[nb_animations];
    int animation_infos_count;
} AnimationInfosList;

#endif